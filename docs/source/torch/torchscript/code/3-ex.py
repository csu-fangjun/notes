#!/usr/bin/env python3

import torch


class MyModel(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.p = torch.nn.Parameter(torch.tensor([2.0]))

    def forward(self, x: torch.Tensor):
        return self.p * x


def test_my_model():
    model = MyModel()
    scripted_model = torch.jit.script(model)
    print(scripted_model.graph)
    print("-" * 10)
    print(scripted_model.code)
    print(scripted_model(torch.tensor([10])))


"""
graph(%self : __torch__.MyModel,
      %x.1 : Tensor):
  %p : Tensor = prim::GetAttr[name="p"](%self)
  %4 : Tensor = aten::mul(%p, %x.1) # ./3-ex.py:12:15
  return (%4)

----------
def forward(self,
    x: Tensor) -> Tensor:
  p = self.p
  return torch.mul(p, x)
"""

if __name__ == "__main__":
    test_my_model()
