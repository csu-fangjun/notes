#!/usr/bin/env python3

import torch
import numpy as np


class Foo(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.x = torch.nn.Parameter(torch.tensor([2.5]))

    def forward(self, y: torch.Tensor):
        return self.x + y


@torch.inference_mode()
def main():
    f = Foo()
    print(f(torch.tensor([3.5, 2.0])))

    mean = np.array([1.5, 2.25, -3.8], dtype=np.float32)
    inv_std = np.array([2.5, 225, 380], dtype=np.float32)

    extra_files = dict()
    extra_files["window_size"] = "20"
    extra_files["window_shift"] = "64"
    extra_files["cmvn_dim"] = f"{mean.shape[0]}"
    extra_files["cmvn_mean"] = mean.tobytes()
    extra_files["cmvn_inv_std"] = inv_std.tobytes()

    m = torch.jit.script(f)
    m.save("m.pt", _extra_files=extra_files)

    saved = dict()
    saved["window_size"] = ""
    saved["window_shift"] = ""

    saved["cmvn_dim"] = ""
    saved["cmvn_mean"] = ""
    saved["cmvn_inv_std"] = ""

    m2 = torch.jit.load("m.pt", _extra_files=saved)
    saved["cmvn_mean"] = np.frombuffer(saved["cmvn_mean"], dtype=np.float32)
    saved["cmvn_inv_std"] = np.frombuffer(saved["cmvn_inv_std"], dtype=np.float32)
    print(saved)
    print(type(saved["window_shift"]))  # <class 'bytes'>


"""
tensor([6.0000, 4.5000])
{'window_size': b'20', 'window_shift': b'64', 'cmvn_dim': b'3', 'cmvn_mean': array([ 1.5 ,  2.25, -3.8 ], dtype=float32), 'cmvn_inv_std': array([  2.5, 225. , 380. ], dtype=float32)}
<class 'bytes'>
"""


if __name__ == "__main__":
    main()
