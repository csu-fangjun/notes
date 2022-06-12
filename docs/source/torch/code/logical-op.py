#!/usr/bin/env python3

import torch

a = torch.tensor([float("inf")])
b = torch.tensor([float("nan")])
assert torch.isinf(a).item() is True
assert torch.isnan(a).item() is False

assert torch.isinf(b).item() is False
assert torch.isnan(b).item() is True

assert torch.logical_or(torch.isinf(a), torch.isnan(b)).item() is True

assert a.isinf().item() is True
assert a.isnan().item() is False

assert b.isinf().item() is False
assert b.isnan().item() is True
