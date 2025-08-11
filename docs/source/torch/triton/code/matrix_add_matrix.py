#!/usr/bin/env python3
import torch
import triton
import triton.language as tl

device = torch.device("cuda", 0)


@triton.jit
def matrix_add_matrix_kernel(
    x_ptr,
    y_ptr,
    out_ptr,
    num_rows,
    num_cols,
    BLOCK_SIZE_ROW: tl.constexpr,
    BLOCK_SIZE_COL: tl.constexpr,
):
    row_start = tl.program_id(0)
    col_start = tl.program_id(1)

    row_offset = row_start * BLOCK_SIZE_ROW + tl.arange(0, BLOCK_SIZE_ROW)[:, None]
    col_offset = col_start * BLOCK_SIZE_COL + tl.arange(0, BLOCK_SIZE_COL)[None, :]
    mask = (row_offset < num_rows) & (col_offset < num_cols)

    offset = row_offset * num_cols + col_offset

    x = tl.load(x_ptr + offset, mask=mask)
    y = tl.load(y_ptr + offset, mask=mask)
    out = x + y
    tl.store(out_ptr + offset, out, mask=mask)


def matrix_add_matrix(x: torch.Tensor, y: torch.Tensor):
    assert x.device == device, (x.device, device)
    assert y.device == device, (y.device, device)
    z = torch.empty_like(x)
    num_rows = x.shape[0]
    num_cols = x.shape[1]
    grid = lambda meta: (
        triton.cdiv(num_rows, meta["BLOCK_SIZE_ROW"]),
        triton.cdiv(num_cols, meta["BLOCK_SIZE_COL"]),
    )
    matrix_add_matrix_kernel[grid](
        x, y, z, num_rows, num_cols, BLOCK_SIZE_ROW=16, BLOCK_SIZE_COL=32
    )
    return z


def main():
    x = torch.randn(301, 529, device=device)
    y = torch.randn(301, 529, device=device)
    z0 = x + y
    z1 = matrix_add_matrix(x, y)
    #  print(x)
    #  print(y)
    #  print(z0)
    #  print(z1)
    print((z0 - z1).abs().max())


if __name__ == "__main__":
    torch.manual_seed(20250810)
    main()
