#!/usr/bin/env python3

import torch
import torch.nn as nn


class Foo(nn.Module):
    def __init__(self):
        super().__init__()
        self.linear = nn.Linear(2, 3)

    def forward(self, x):
        return self.linear(x)


f = Foo()
m = torch.jit.script(f)
assert isinstance(m, torch.jit.ScriptModule)
#  print(m.graph)
"""
graph(%self : __torch__.Foo,
      %x.1 : Tensor):
  %linear : __torch__.torch.nn.modules.linear.Linear = prim::GetAttr[name="linear"](%self)
  %4 : Tensor = prim::CallMethod[name="forward"](%linear, %x.1) # ./ex2.py:13:15
  return (%4)
"""
#  print(m.inlined_graph)
"""
graph(%self : __torch__.Foo,
      %x.1 : Tensor):
  %linear : __torch__.torch.nn.modules.linear.Linear = prim::GetAttr[name="linear"](%self)
  %4 : Function = prim::Constant[name="linear"]()
  %weight : Tensor = prim::GetAttr[name="weight"](%linear)
  %bias : Tensor = prim::GetAttr[name="bias"](%linear)
  %7 : Tensor = aten::linear(%x.1, %weight, %bias) # /ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch/nn/functional.py:1848:11
  return (%7)
"""
print(m.linear.graph)
"""
graph(%self : __torch__.torch.nn.modules.linear.Linear,
      %input.1 : Tensor):
  %5 : Function = prim::Constant[name="linear"]()
  %weight : Tensor = prim::GetAttr[name="weight"](%self)
  %bias : Tensor = prim::GetAttr[name="bias"](%self)
  %6 : Tensor = prim::CallFunction(%5, %input.1, %weight, %bias) # /ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch/nn/modules/linear.py:103:15
  return (%6)
"""
print(dir(m))
