#!/usr/bin/env python3

import torch
import triton.language as tl
import triton

device = torch.device("cuda", 0)


def native(x):
    max_x = x.max(dim=-1, keepdims=True)[0]
    x = x - max_x
    x = x.exp()
    den = x.sum(dim=-1, keepdims=True)
    return x / den


@triton.jit
def softmax_kernel(in_ptr, out_ptr, num_rows, num_cols, BLOCK_SIZE: tl.constexpr):
    row_start = tl.program_id(0)
    row_step = tl.num_programs(0)
    for row_idx in tl.range(row_start, num_rows, row_step):
        row_start_ptr = in_ptr + row_idx * num_cols
        col_offset = tl.arange(0, BLOCK_SIZE)
        mask = col_offset < num_cols
        row = tl.load(row_start_ptr + col_offset, mask=mask, other=-float("inf"))
        row_minux_max = row - tl.max(row, axis=0)
        numerator = tl.exp(row_minux_max)
        denominator = tl.sum(numerator, axis=0)
        softmax_output = numerator / denominator

        tl.store(out_ptr + row_idx * num_cols + col_offset, softmax_output, mask=mask)


def softmax(x):
    assert x.device == device, (x.device, device)
    x = x.contiguous()
    y = torch.empty_like(x)
    assert x.shape[1] <= 1024, x.shape[1]
    num_programs = min(5, x.shape[0])
    print("num_programs", num_programs)
    softmax_kernel[(num_programs,)](x, y, x.shape[0], x.shape[1], BLOCK_SIZE=1024)
    return y


def main():
    x = torch.randn(100, 768, device=device)
    y0 = native(x)
    y1 = x.softmax(dim=-1)
    y2 = softmax(x)
    print((y0 - y1).abs().max())
    print((y0 - y2).abs().max())


if __name__ == "__main__":
    main()
