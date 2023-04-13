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


def print_graph():
    assert isinstance(adder.graph, torch._C.Graph)
    assert isinstance(adder.graph, torch.Graph)

    # It should have only 1 input
    assert len(list(adder.graph.inputs())) == 1

    x = next(adder.graph.inputs())
    assert isinstance(x, torch.Value)
    assert isinstance(x.debugName(), str)
    assert x.debugName() == "x.1"
    print(type(x.uses()[0]))
    print(dir(x.uses()[0]))
    print(x.uses()[0].user)
    assert isinstance(x.uses()[0].user, torch.Node)

    x.setDebugName("x.2")
    assert next(adder.graph.inputs()).debugName() == "x.2"
    assert isinstance(x.type(), torch.IntType)

    print(x.node())
    assert isinstance(x.node(), torch.Node)
    print(dir(x.node()))
    n = x.node()
    assert isinstance(n.kind(), str)
    assert n.kind() == "prim::Param", n.kind()
    print(n.kind())
    # a node as input and output
    assert list(n.inputs()) == []

    # n has only one output, i.e., x
    assert len(list(n.outputs())) == 1
    x2 = next(n.outputs())  # its type is torch.Value
    assert x2 is x
    assert len(list(n.blocks())) == 0


def main():
    #  test_adder()
    print_graph()


if __name__ == "__main__":
    main()
