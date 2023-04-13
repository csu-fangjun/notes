#!/usr/bin/env python3

import torch


class Foo(torch.nn.Module):
    def forward(self, x: torch.Tensor, y: torch.Tensor):
        a = torch.nn.functional.relu(x + y, inplace=True)
        return a + 10


def main():
    f = Foo()
    m = torch.jit.trace(f, (torch.rand(3), torch.rand(3)))
    g = m.graph

    with open("fuse_add_relu_-before.txt", "w") as f:
        print(g, file=f)

    torch._C._jit_pass_fuse_add_relu(g)

    with open("fuse_add_relu_-after.txt", "w") as f:
        print(g, file=f)


if __name__ == "__main__":
    main()
