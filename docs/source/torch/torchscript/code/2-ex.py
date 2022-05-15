#!/usr/bin/env python3
import torch


def adder(x: int):
    return x + 2


def test_adder():
    adder_func = torch.jit.script(adder)
    assert isinstance(adder_func, torch.jit.ScriptFunction)
    print(adder_func.graph)
    print(adder_func(3))


"""
graph(%x.1 : int):
  %2 : int = prim::Constant[value=2]() # ./2-ex.py:6:15
  %3 : int = aten::add(%x.1, %2) # ./2-ex.py:6:11
  return (%3)

5
"""


if __name__ == "__main__":
    test_adder()
