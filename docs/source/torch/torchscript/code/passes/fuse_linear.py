#!/usr/bin/env python3

import torch


class Foo(torch.nn.Module):
    def forward(self, x: torch.Tensor, w: torch.Tensor, b: torch.Tensor):
        return torch.matmul(x, w.t()) + b


def main():
    f = Foo()
    m = torch.jit.trace(f, (torch.rand(3), torch.rand(3, 3), torch.rand(3)))
    g = m.graph

    with open("fuse_linear-before.txt", "w") as f:
        print(g, file=f)

    torch._C._jit_pass_fuse_linear(g)

    with open("fuse_linear-after.txt", "w") as f:
        print(g, file=f)


if __name__ == "__main__":
    main()
