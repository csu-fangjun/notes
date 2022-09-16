#!/usr/bin/env python3

import torch


class Foo(torch.nn.Module):
    def forward(self, x):
        return torch.nn.functional.relu(x)


f = Foo()
x = torch.rand(2)
m = torch.jit.trace(f, x)
m.save("ex1.pt")
print(m.graph)
