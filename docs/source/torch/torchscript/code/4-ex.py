#!/usr/bin/env python3

import torch


class MyModel(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.p = torch.nn.Parameter(torch.tensor([2.0]))

    def foobar(self, x: torch.Tensor):
        return x + 3

    def foo(self, x: torch.Tensor):
        return self.foobar(x)

    def bar(self, x: torch.Tensor):
        return self.p - x

    @torch.jit.export
    def baz(self, x: torch.Tensor):
        return self.p + x + 2

    def forward(self, x: torch.Tensor):
        return self.p * x


def test_my_model():
    MyModel.foo = torch.jit.export(MyModel.foo)  # manually export

    # Note: forward is exported by default. We ignore it here manually
    MyModel.forward = torch.jit.ignore(MyModel.forward)

    model = MyModel()
    scripted_model = torch.jit.script(model)
    assert hasattr(scripted_model, "foo")
    assert hasattr(scripted_model, "baz")
    assert hasattr(scripted_model, "foobar")  # because it is called by `foo`
    assert not hasattr(scripted_model, "bar")

    scripted_model.save("foo.pt")

    m = torch.jit.load("foo.pt")
    print(m.foo(torch.tensor([1])))
    print(m.baz(torch.tensor([1])))


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
