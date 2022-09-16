#!/usr/bin/env python3

import torch
import torch.nn as nn


class MyConv2d(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv2d(
            in_channels=2,
            out_channels=3,
            kernel_size=(3, 3),
            stride=1,
        )

    def forward(self, x: torch.Tensor):
        return self.conv(x)


def test_conv2d():
    f = MyConv2d()
    x = torch.rand(2, 2, 5, 5)  # nchw
    m = torch.jit.trace(f, x)
    print(m.graph)
    print(m.conv.graph)
    for n in m.conv.graph.nodes():
        assert isinstance(n, torch._C.Node)
        print(n)
        print(dir(n))
        break

    print(dir(type(m.conv.graph)))


def test_linear():
    f = nn.Linear(in_features=2, out_features=3)
    x = torch.rand(2, 2)
    m = torch.jit.trace(f, x)
    print(m.graph)


def main():
    #  test_conv2d()
    test_linear()


if __name__ == "__main__":
    main()
