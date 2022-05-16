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
    adder.save("adder.pt")

    my_adder = torch.jit.load("adder.pt")

    assert isinstance(my_adder, torch.jit._script.RecursiveScriptModule)
    assert isinstance(my_adder, torch.jit.ScriptModule)
    assert not isinstance(my_adder, torch.jit.ScriptFunction)
    print(my_adder(torch.tensor([3])))


"""
graph(%x.1 : int):
  %2 : int = prim::Constant[value=1]() # ./1-ex.py:8:15
  %3 : int = aten::add(%x.1, %2) # ./1-ex.py:8:11
  return (%3)

----------
def adder(x: int) -> int:
  return torch.add(x, 1)

4
"""


def main():
    test_adder()


if __name__ == "__main__":
    main()
