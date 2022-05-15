#!/usr/bin/env python3

import torch


@torch.jit.script
def adder(x: int):
    return x + 1


def test_adder():
    assert isinstance(adder, torch.jit.ScriptFunction)
    print(adder.graph)
    print("-" * 10)
    print(adder.code)


"""
graph(%x.1 : int):
  %2 : int = prim::Constant[value=1]() # ./1-ex.py:8:15
  %3 : int = aten::add(%x.1, %2) # ./1-ex.py:8:11
  return (%3)

----------
def adder(x: int) -> int:
  return torch.add(x, 1)
"""


def main():
    test_adder()


if __name__ == "__main__":
    main()
