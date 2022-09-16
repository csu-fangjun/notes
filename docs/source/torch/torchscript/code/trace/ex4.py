#!/usr/bin/env python3

import torch


class Foo(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.linear = torch.nn.Linear(2, 3)
        self.relu = torch.nn.ReLU()

    def forward(self, x):
        return self.relu(self.linear(x))


f = Foo()
x = torch.rand(2)
m = torch.jit.trace(f, x)
#  print(m.graph)

"""
graph(%self.1 : __torch__.Foo,
      %x : Float(2, strides=[1], requires_grad=0, device=cpu)):
  %relu : __torch__.torch.nn.modules.activation.ReLU = prim::GetAttr[name="relu"](%self.1)
  %linear : __torch__.torch.nn.modules.linear.Linear = prim::GetAttr[name="linear"](%self.1)
  %22 : Tensor = prim::CallMethod[name="forward"](%linear, %x)
  %23 : Tensor = prim::CallMethod[name="forward"](%relu, %22)
  return (%23)
"""
print(dir(m.graph))
