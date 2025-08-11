#!/usr/bin/env python3
import torch
import triton
import triton.language as tl

device = torch.device("cuda", 0)


@triton.jit
def sub_kernel(x_ptr, y_ptr, output_ptr, n_elements, BLOCK_SIZE: tl.constexpr):
    start = tl.program_id(0)
    offset = start * BLOCK_SIZE + tl.arange(0, BLOCK_SIZE)
    mask = offset < n_elements
    x = tl.load(x_ptr + offset, mask=mask)
    y = tl.load(y_ptr + offset, mask=mask)
    z = x - y
    tl.store(output_ptr + offset, z, mask=mask)


def sub(x: torch.Tensor, y: torch.Tensor) -> torch.Tensor:
    assert x.device == device, (x.device, device)
    assert y.device == device, (y.device, device)
    n = x.nelement()
    grid = lambda meta: (triton.cdiv(n, meta["BLOCK_SIZE"]),)
    z = torch.empty_like(x)
    sub_kernel[grid](x, y, z, n, BLOCK_SIZE=1024)
    return z


def main():
    n = 10
    x = torch.rand(n, device=device)
    y = torch.rand(n, device=device)
    z0 = x - y
    z1 = sub(x, y)
    print(z0)
    print(z1)
    print((z0 - z1).abs().max())


if __name__ == "__main__":
    main()
