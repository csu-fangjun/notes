#!/usr/bin/env python3

import torch.nn as nn
import torch


def my_add_impl(x: torch.Tensor):
    return x + 2


def my_add(x: torch.Tensor):
    return my_add_impl(x) + 10


class Foo(nn.Module):
    def __init__(self):
        super().__init__()
        self.linear = nn.Linear(2, 2)
        self.relu = nn.ReLU()

    def add(self, x: torch.Tensor):
        return my_add(x) + 3

    def forward(self, x: torch.Tensor):
        y = self.linear(x) + self.add(x)
        return self.relu(y)


def test_bar(x):
    y = my_add(x)
    return y


def test_foo(x):
    return my_add(x)


@torch.no_grad()
def main():
    x = torch.rand(1, 2)
    f = torch.jit.trace(test_foo, x)
    print(f.graph)


if __name__ == "__main__":
    main()
