#!/usr/bin/env python3

import torch


def f(a, b):
    c = a + b
    d = c * c
    e = torch.tanh(d * c)
    return d + (e + e)


m = torch.jit.script(f)
print(m.graph)

"""
graph(%a.1 : Tensor,
      %b.1 : Tensor):
  %4 : int = prim::Constant[value=1]()
  %c.1 : Tensor = aten::add(%a.1, %b.1, %4) # ./ex1.py:7:8
  %d.1 : Tensor = aten::mul(%c.1, %c.1) # ./ex1.py:8:8
  %11 : Tensor = aten::mul(%d.1, %c.1) # ./ex1.py:9:19
  %e.1 : Tensor = aten::tanh(%11) # ./ex1.py:9:8
  %17 : Tensor = aten::add(%e.1, %e.1, %4) # ./ex1.py:10:16
  %19 : Tensor = aten::add(%d.1, %17, %4) # ./ex1.py:10:11
  return (%19)
"""

"""
Note: for aten::add(a0, a1, a2), it does  a0 + a2 * a1.
See torch/csrc/jit/codegen/fuser/codegen.cpp

"""
assert isinstance(m.graph, torch._C.Graph)

# Every graph has inputs and outputs
# m.graph.inputs() returns an iterator
assert len(list(m.graph.inputs())) == 2, "It has two inputs: a, b, in our case"
it = m.graph.inputs()
a = next(it)
b = next(it)

assert isinstance(a, torch._C.Value)
assert isinstance(a.node(), torch._C.Node)

# every node has inputs and outputs
# a.node().inputs() is an iterator
assert list(a.node().inputs()) == []
assert a.node().kind() == "prim::Param"
assert a.node().inputsSize() == 0
assert a.node().outputsSize() == 2
print(next(a.node().outputs()))

oit = a.node().outputs()
assert next(oit) == a
assert next(oit) == b

assert next(a.node().outputs()) == a

assert a.node().outputsAt(0) == a
assert a.node().outputsAt(1) == b
assert a.node() == b.node()
assert a.node().attributeNames() == [], "this node has no attributes"
assert a.debugName() == "a.1"
assert isinstance(a.type(), torch._C.TensorType)
assert a.type().kind() == "TensorType"
assert a.unique() == 0  # TODO(fangjun): what does it mean?
assert isinstance(a.uses(), list)
assert isinstance(a.uses()[0], torch._C.Use)
assert isinstance(a.uses()[0].user, torch._C.Node)

c_node = a.uses()[0].user
assert c_node.kind() == "aten::add"
assert c_node.attributeNames() == []
assert len(list(c_node.inputs())) == 3
c_it = c_node.inputs()
assert a == next(c_it)
assert b == next(c_it)
v4 = next(c_it)
assert v4.debugName() == "4"
assert c_node.hasAttributes() is False
assert c_node.hasMultipleOutputs() is False
assert c_node.hasUses() is True
assert (
    c_node.schema()
    == "aten::add.Tensor(Tensor self, Tensor other, *, Scalar alpha=1) -> (Tensor)"
)
print(c_node.schema())
print(type(c_node.schema()))
v4_node = v4.node()
assert v4_node.attributeNames() == ["value"]
assert v4_node.hasAttributes() is True
assert v4_node.hasAttribute("value") is True
#  print(v4_node.t("value"))
print(dir(v4_node))
