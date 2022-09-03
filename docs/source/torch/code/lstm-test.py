#!/usr/bin/env python3

import torch
import torch.nn as nn


"""
self.lstm = LSTM(
    input_size=2,
    hidden_size=5,
    num_layers=1,
    bias=True,
    proj_size=2,
)

lstm.weight_ih_l0 [20, 2]
lstm.weight_hh_l0 [20, 2]
lstm.bias_ih_l0 [20]
lstm.bias_hh_l0 [20]
lstm.weight_hr_l0 [2, 5]
"""


class Foo(nn.Module):
    def __init__(self):
        super().__init__()
        self.lstm = nn.LSTM(
            input_size=2,
            hidden_size=5,
            num_layers=1,
            bias=True,
            proj_size=2,
        )

    def forward(self, x, h0, c0):
        """
        Args:
          x:
            (T, N, H_in), H_in is input dimension of x
          h0:
            (num_layers, N, H_out), H_out is proj_size
          c0:
            (num_layers, N, H_cell), H_cell is hidden_dim
        """
        y, (hx, cx) = self.lstm(x, (h0, c0))
        return y, hx, cx


@torch.no_grad()
def main():
    f = Foo()
    dim_in = 2
    dim_proj = 2
    dim_hidden = 5
    x = torch.rand(1, 1, dim_in)
    h0 = torch.rand(1, 1, dim_proj)
    c0 = torch.rand(1, 1, dim_hidden)
    y, hx, cx = f(x, h0, c0)

    w_ih = f.state_dict()["lstm.weight_ih_l0"]
    w_hh = f.state_dict()["lstm.weight_hh_l0"]

    b_ih = f.state_dict()["lstm.bias_ih_l0"]
    b_hh = f.state_dict()["lstm.bias_hh_l0"]

    w_hr = f.state_dict()["lstm.weight_hr_l0"]

    w_ii, w_if, w_ig, w_io = w_ih.split(5, dim=0)
    w_hi, w_hf, w_hg, w_ho = w_hh.split(5, dim=0)

    b_ii, b_if, b_ig, b_io = b_ih.split(5, dim=0)
    b_hi, b_hf, b_hg, b_ho = b_hh.split(5, dim=0)

    print(y, hx, cx)

    i_gate = (x @ w_ii.t() + b_ii + h0 @ w_hi.t() + b_hi).sigmoid()
    f_gate = (x @ w_if.t() + b_if + h0 @ w_hf.t() + b_hf).sigmoid()
    g_gate = (x @ w_ig.t() + b_ig + h0 @ w_hg.t() + b_hg).tanh()
    o_gate = (x @ w_io.t() + b_io + h0 @ w_ho.t() + b_ho).sigmoid()
    c = f_gate * c0 + i_gate * g_gate

    h = o_gate * c.tanh()
    h = h @ w_hr.t()

    print(h, h, c)


if __name__ == "__main__":
    torch.manual_seed(20220903)
    main()
