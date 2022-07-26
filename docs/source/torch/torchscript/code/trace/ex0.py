#!/usr/bin/env python3

import torch

import torch.nn as nn


class Foo(nn.Module):
    def __init__(self):
        super().__init__()
        self.relu = nn.ReLU()

    def forward(self, x):
        return self.relu(x)


def main():
    f = Foo()
    m = torch.jit.trace(f, torch.rand(2, 3))

    print(m(torch.rand(2)))
    print(m(torch.rand(2, 3, 4)))


if __name__ == "__main__":
    main()
