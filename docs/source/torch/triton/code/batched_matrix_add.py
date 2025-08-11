#!/usr/bin/env python3
import torch
import triton
import triton.language as tl

device = torch.device("cuda", 0)


@triton.jit
def add_kernel(
    a_ptr,
    b_ptr,
    c_ptr,
    num_rows,
    num_cols,
    BLOCK_SIZE_ROW: tl.constexpr,
    BLOCK_SIZE_COL: tl.constexpr,
):
    batch_start = tl.program_id(0)
    row_start = tl.program_id(1)
    col_start = tl.program_id(2)

    batch_offset = batch_start * num_rows * num_cols

    row_offset = row_start * BLOCK_SIZE_ROW + tl.arange(0, BLOCK_SIZE_ROW)[:, None]
    col_offset = col_start * BLOCK_SIZE_COL + tl.arange(0, BLOCK_SIZE_COL)[None, :]

    mask = (row_offset < num_rows) & (col_offset < num_cols)

    offset = batch_offset + row_offset * num_cols + col_offset
    a = tl.load(a_ptr + offset, mask=mask)
    b = tl.load(b_ptr + offset, mask=mask)
    c = a + b
    tl.store(c_ptr + offset, c, mask=mask)


def batched_add(a: torch.Tensor, b: torch.Tensor):
    assert a.device == device, (a.device, device)
    assert b.device == device, (b.device, device)

    n, r, c = a.shape
    BLOCK_SIZE_ROW = 32
    BLOCK_SIZE_COL = 32
    grid = (n, triton.cdiv(r, BLOCK_SIZE_ROW), triton.cdiv(c, BLOCK_SIZE_COL))
    out = torch.empty_like(a)
    add_kernel[grid](a, b, out, r, c, BLOCK_SIZE_ROW, BLOCK_SIZE_COL)
    return out


def main():
    a = torch.randn(5, 10, 20, device=device)
    b = torch.randn(5, 10, 20, device=device)
    c0 = a + b
    c1 = batched_add(a, b)
    print((c0 - c1).abs().max())


if __name__ == "__main__":
    main()
