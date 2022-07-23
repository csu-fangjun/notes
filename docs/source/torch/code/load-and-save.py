#!/usr/bin/env python3

import torch
import tempfile


def main():
    a = torch.arange(3)
    with tempfile.NamedTemporaryFile() as f:
        torch.save(a, f)
        f.seek(0)
        b = torch.load(f)
        assert torch.all(torch.eq(a, b)), (a, b)


if __name__ == "__main__":
    main()
