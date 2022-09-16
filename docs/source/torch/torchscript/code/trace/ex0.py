#!/usr/bin/env python3

import torch

import torch.nn as nn
from typing import List


class Foo(nn.Module):
    def __init__(self):
        super().__init__()
        self.relu = nn.ReLU()

    def forward(self, x):
        return self.relu(x)


def test_foo():
    f = Foo()
    m = torch.jit.trace(f, torch.rand(2, 3))

    print(m(torch.rand(2)))
    print(m(torch.rand(2, 3, 4)))
    # Note: The input shape is dynamic, not fixed.


def simple(x: List[torch.Tensor], y: torch.Tensor):
    x = x[0].item()
    if x > 2:
        return y + x + 1
    elif x < 1:
        return y
    else:
        return y + x


def test_simple():
    f0 = torch.jit.trace(simple, ([torch.tensor([0])], torch.rand(2, 3)))
    #  print(dir(f0))
    """
    ['__call__', '__class__', '__delattr__', '__dict__', '__dir__', '__doc__',
    '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__',
    '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__',
    '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__',
    '__sizeof__', '__str__', '__subclasshook__', '_debug_flush_compilation_cache',
    'code', 'get_debug_state', 'graph', 'graph_for', 'inlined_graph', 'name',
    'qualified_name', 'save', 'save_to_buffer', 'schema']
    """
    #  print(f0.schema)  # simple(Tensor[] x, Tensor y) -> (Tensor)
    #  print(f0.code)
    """
    def simple(x: List[Tensor],
        y: Tensor) -> Tensor:
      return y
    """
    #  print(f0.graph)
    """
    graph(%x : Tensor[],
          %y : Float(2, 3, strides=[3, 1], requires_grad=0, device=cpu)):
      return (%y)
    """
    #  print(f0.inlined_graph) # same as the above one
    #  print(f0.name) # simple
    print(f0.qualified_name)  # __torch__.simple


def main():
    #  test_foo()
    test_simple()


if __name__ == "__main__":
    main()
