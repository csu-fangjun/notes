#!/usr/bin/env python3
import torch
import triton
import triton.language as tl

device = torch.device("cuda", 0)


@triton.jit
def vector_add_scalar_kernel(x_ptr, y_ptr, scalar, n, BLOCK_SIZE: tl.constexpr):
    start = tl.program_id(0)
    offset = start * BLOCK_SIZE + tl.arange(0, BLOCK_SIZE)
    mask = offset < n
    x = tl.load(x_ptr + offset, mask=mask)
    y = x + scalar
    tl.store(y_ptr + offset, y, mask=mask)


def vector_add_scalar(x: torch.Tensor, scalar: float):
    assert x.device == device, (x.device, device)
    y = torch.empty_like(x)
    n = x.nelement()
    grid = lambda meta: (triton.cdiv(n, meta["BLOCK_SIZE"]),)
    vector_add_scalar_kernel[grid](x, y, scalar, n, BLOCK_SIZE=4096)
    return y


def main():
    x = torch.randn(10240, device=device)
    scalar = 2.25
    y0 = x + scalar
    y1 = vector_add_scalar(x, scalar)
    #  print(x)
    #  print(y0)
    #  print(y1)
    print((y0 - y1).abs().max())


if __name__ == "__main__":
    main()
