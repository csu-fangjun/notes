#!/usr/bin/env python

import torch

# pytorch/test/jit/test_graph_rewrite_pass.py
class Foo(torch.nn.Module):
    def __init__(self, weight, bias):
        super().__init__()
        self.weight = weight
        self.bias = bias

    def forward(self, x):
        res = torch.matmul(x, self.weight.t())
        if self.bias is not None:
            res.add_(self.bias)
        return res


x = torch.rand(3)
w = torch.rand(5, 3)
b = torch.rand(5)
f = Foo(w, b)
m = torch.jit.trace(f, x)
#  print(m.graph)
"""
graph(%self : __torch__.Foo,
      %x : Float(3, strides=[1], requires_grad=0, device=cpu)):
  %4 : Float(5, 3, strides=[3, 1], requires_grad=0, device=cpu) = prim::Constant[value=<Tensor>]() # ./ex3.py:13:0
  %5 : Float(3, 5, strides=[1, 3], requires_grad=0, device=cpu) = aten::t(%4) # ./ex3.py:13:0
  %res : Float(5, strides=[1], requires_grad=0, device=cpu) = aten::matmul(%x, %5) # ./ex3.py:13:0
  %7 : Float(5, strides=[1], requires_grad=0, device=cpu) = prim::Constant[value= 0.3834  0.7570  0.8494  0.7691  0.4170 [ CPUFloatType{5} ]]() # ./ex3.py:15:0
  %8 : int = prim::Constant[value=1]() # ./ex3.py:15:0
  %9 : Float(5, strides=[1], requires_grad=0, device=cpu) = aten::add_(%res, %7, %8) # ./ex3.py:15:0
  return (%9)
"""
torch._C._jit_pass_fuse_linear(m.graph)
#  print(m.graph)
"""
graph(%self : __torch__.Foo,
      %x : Float(3, strides=[1], requires_grad=0, device=cpu)):
  %4 : Float(5, 3, strides=[3, 1], requires_grad=0, device=cpu) = prim::Constant[value=<Tensor>]() # ./ex3.py:13:0
  %7 : Float(5, strides=[1], requires_grad=0, device=cpu) = prim::Constant[value= 0.7757  0.5726  0.1596  0.3731  0.8581 [ CPUFloatType{5} ]]() # ./ex3.py:15:0
  %12 : Tensor = aten::linear(%x, %4, %7) # ./ex3.py:13:0
  %8 : int = prim::Constant[value=1]() # ./ex3.py:15:0
  return (%12)
"""

torch._C._jit_pass_dce(m.graph)  # dce: dead code elimination
#  print(m.graph) # Note: %8 is removed
"""
graph(%self : __torch__.Foo,
      %x : Float(3, strides=[1], requires_grad=0, device=cpu)):
  %4 : Float(5, 3, strides=[3, 1], requires_grad=0, device=cpu) = prim::Constant[value=<Tensor>]() # ./ex3.py:13:0
  %7 : Float(5, strides=[1], requires_grad=0, device=cpu) = prim::Constant[value= 0.3112  0.8055  0.6374  0.2117  0.2649 [ CPUFloatType{5} ]]() # ./ex3.py:15:0
  %12 : Tensor = aten::linear(%x, %4, %7) # ./ex3.py:13:0
  return (%12)
"""
print(dir(m))
