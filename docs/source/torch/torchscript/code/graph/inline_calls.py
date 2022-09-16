#!/usr/bin/env python3

from pathlib import Path

import torch
import torch.nn as nn


class Foo(nn.Module):
    def __init__(self):
        super().__init__()
        self.linear = nn.Linear(2, 2)
        self.linear2 = nn.Linear(2, 2)
        self.relu = nn.ReLU()
        self.t = torch.rand(2)

    def forward(self, x: torch.Tensor):
        y = self.linear(x + self.t)
        y = self.linear2(y)
        y = self.linear2(y)
        #  z = self.relu(y)
        return nn.functional.elu(y)
        return z


def generate_foo_pt():
    f = Foo()
    x = torch.rand(1, 2)
    m = torch.jit.trace(f, x)
    m.save("foo.pt")


def test_foo_pt():
    m = torch.jit.load("foo.pt")
    assert isinstance(m.forward, torch._C.ScriptMethod)
    assert isinstance(m.forward.graph, torch._C.Graph)
    assert isinstance(m.forward.inlined_graph, torch._C.Graph)

    print(m.linear.graph)
    return

    print(m.forward.graph)
    #  print(m.forward.inlined_graph)
    g = m.forward.graph
    nodes = g.nodes()

    n = next(nodes)
    print(dir(n))
    assert n.kind() == "prim::GetAttr"
    for i in n.inputs():
        assert isinstance(i, torch._C.Value)
        assert i.debugName() == "self.1"
        assert isinstance(i.type(), torch._C.ClassType)
        t = i.type()
        assert t.str() == "__torch__.Foo"


def main():
    generate_foo_pt()
    #  test_foo_pt()


if __name__ == "__main__":
    main()
