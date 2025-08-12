#!/usr/bin/env python3
import triton.language as tl
import triton
import torch

device = torch.device("cuda", 0)


@triton.jit
def relative_position_attention_fwd_kernel(
    # fmt: off
        q_ptr,  # (batches, head, seq_q, channel)
        k_ptr,  # (batches, head, seq_k, channel)
        pos_ptr,  # (head, 2*max_seq_len-1, channel)
        scores_ptr,  # (batches, head, seq_q, seq_k)
        B, H, seq_q, seq_k, channels, max_seq_len,   # shape
        stride_qb, stride_qh, stride_qs, stride_qc,  # stride for q
        stride_kb, stride_kh, stride_ks, stride_kc,  # stride for k
        stride_ph, stride_ps, stride_pc,  # stride for pos
        stride_sb, stride_sh, stride_sq, stride_sk,  # stride for scores
        BLOCK_M: tl.constexpr,  # block size in q
        BLOCK_N: tl.constexpr,  # block size in k
        BLOCK_C: tl.constexpr,  # block size for channel
        GROUP_SIZE_M: tl.constexpr,  # size for grouped block
):
    # fmt: on
    pid = tl.program_id(axis=0)
    pid_bh = tl.program_id(axis=1)

    head = pid_bh % H
    batch = pid_bh // H

    num_pid_m = tl.cdiv(seq_q, BLOCK_M)
    num_pid_n = tl.cdiv(seq_k, BLOCK_N)
    num_pid_in_group = GROUP_SIZE_M * num_pid_n

    group_id = pid // num_pid_in_group
    first_pid_m = group_id * GROUP_SIZE_M

    group_size_m = min(num_pid_m - first_pid_m, GROUP_SIZE_M)
    pid_in_group = pid % num_pid_in_group
    pid_m = first_pid_m + (pid_in_group % group_size_m)
    pid_n = pid_in_group // group_size_m

    # (BLOCK_M,)
    offs_m = pid_m * BLOCK_M + tl.arange(0, BLOCK_M)

    # (BLOCK_N,)
    offs_n = pid_n * BLOCK_N + tl.arange(0, BLOCK_N)

    # (BLOCK_C,)
    offs_c = tl.arange(0, BLOCK_C)

    # (BLOCK_M, BLOCK_M)
    rel_idx = offs_m[:, None] - offs_n[None, :] + max_seq_len - 1

    q_base = q_ptr + batch * stride_qb + head * stride_qh
    k_base = k_ptr + batch * stride_kb + head * stride_kh
    pos_base = pos_ptr + head * stride_ph
    scores_base = scores_ptr + batch * stride_sb + head * stride_sh

    acc = tl.zeros((BLOCK_M, BLOCK_N), dtype=tl.float32)

    for c in range(0, channels, BLOCK_C):
        c_idx = c + offs_c

        # (BLOCK_M, BLOCK_C)
        q_mask = (offs_m[:, None] < seq_q) & (c_idx[None, :] < channels)

        # (BLOCK_N, BLOCK_C)
        k_mask = (offs_n[:, None] < seq_k) & (c_idx[None, :] < channels)

        # (BLOCK_M, BLOCK_N, BLOCK_C)
        pos_mask = (
            (rel_idx[:, :, None] >= 0)
            & (rel_idx[:, :, None] < 2 * max_seq_len - 1)
            & (c_idx[None, None, :] < channels)
        )

        q_ptrs = q_base + offs_m[:, None] * stride_qs + c_idx[None, :] * stride_qc
        k_ptrs = k_base + offs_n[:, None] * stride_ks + c_idx[None, :] * stride_kc

        # (BLOCK_M, BLOCK_C)
        q_chunk = tl.load(q_ptrs, mask=q_mask, other=0.0)

        # (BLOCK_N, BLOCK_C)
        k_chunk = tl.load(k_ptrs, mask=k_mask, other=0.0)

        # (BLOCK_M, BLOCK_N, BLOCK_C)
        pos_ptrs = (
            pos_base
            + rel_idx[:, :, None] * stride_ps
            + c_idx[None, None, :] * stride_pc
        )

        pos_chunk = tl.load(pos_ptrs, mask=pos_mask, other=0.0)

        # q_chunk[:, None, :]   (BLOCK_M, 1,       BLOCK_C)
        # k_chunk[None, :, :]   (1,       BLOCK_N, BLOCK_C)
        # pos_chunk[None, :, :] (BLOCK_M, BLOCK_N, BLOCK_C)

        acc += tl.sum(q_chunk[:, None, :] * k_chunk[None, :, :] * pos_chunk, axis=2)

    scores_ptrs = (
        scores_base + offs_m[:, None] * stride_sq + offs_n[None, :] * stride_sk
    )
    scores_mask = (offs_m[:, None] < seq_q) & (offs_n[None, :] < seq_k)
    tl.store(scores_ptrs, acc, mask=scores_mask)


def relative_position_attention_fwd(
    q, k, pos, BLOCK_M=32, BLOCK_N=32, BLOCK_C=16, GROUP_SIZE_M=4
):
    assert q.ndim == k.ndim == 4, (q.shape, k.shape)
    assert pos.ndim == 3, pos.shape
    b, h, seq_q, c = q.shape
    assert k.shape[0] == b, k.shape
    assert k.shape[1] == h, k.shape
    assert k.shape[3] == c, k.shape

    seq_k = k.shape[2]

    assert pos.shape[0] == h, pos.shape
    pos.shape[2] == c, pos.shape

    max_seq_len = (pos.shape[1] + 1) // 2

    assert q.device == k.device == pos.device == device, (
        q.device,
        k.device,
        pos.device,
        device,
    )

    scores = torch.empty(b, h, seq_q, seq_k, device=q.device)

    num_pid_m = triton.cdiv(seq_q, BLOCK_M)
    num_pid_n = triton.cdiv(seq_k, BLOCK_N)
    grid0 = num_pid_m * num_pid_n
    grid1 = b * h

    # fmt:off
    relative_position_attention_fwd_kernel[(grid0, grid1)](
            q, k, pos, scores,
            b, h, seq_q, seq_k, c, max_seq_len,
            q.stride(0), q.stride(1), q.stride(2), q.stride(3),
            k.stride(0), k.stride(1), k.stride(2), k.stride(3),
            pos.stride(0), pos.stride(1), pos.stride(2),
            scores.stride(0), scores.stride(1), scores.stride(2), scores.stride(3),
            BLOCK_M=BLOCK_M,
            BLOCK_N=BLOCK_N,
            BLOCK_C=BLOCK_C,
            GROUP_SIZE_M=GROUP_SIZE_M,
            )
    # fmt: on
    return scores


def relative_position_attention_fwd_torch(q, k, pos):
    max_seq_len = (pos.shape[1] + 1) // 2
    seq_q = q.shape[2]
    seq_k = k.shape[2]

    q = q.unsqueeze(3)
    k = k.unsqueeze(2)

    i = torch.arange(seq_q, device=device).unsqueeze(1)
    j = torch.arange(seq_k, device=device).unsqueeze(0)
    rel = (i - j) + max_seq_len - 1
    rel = rel.clamp(0, pos.shape[1] - 1)
    pos_indexed = pos[:, rel].unsqueeze(0)

    # q: (b, h, seq_q, 1, c)
    # q: (b, h, 1, seq_k, c)
    # pos: (1, h, seq_q, seq_k, c)
    scores = (q * k * pos_indexed).sum(dim=-1)
    return scores


def main():
    b = 2
    h = 4
    seq_q = 5
    seq_k = 5
    c = 3
    max_seq_len = seq_q

    q = torch.randn(b, h, seq_q, c, device=device)
    k = torch.randn(b, h, seq_k, c, device=device)
    pos = torch.randn(h, 2 * max_seq_len - 1, c, device=device)
    scores0 = relative_position_attention_fwd_torch(q, k, pos)
    scores1 = relative_position_attention_fwd(q, k, pos)
    print(scores0.shape, scores0.sum())
    print(scores1.shape, scores1.sum())
    print((scores0 - scores1).abs().max())


if __name__ == "__main__":
    torch.manual_seed(20250812)
    main()
