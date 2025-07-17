#!/usr/bin/env python3

import mlx.core as mx
import mlx.nn as nn
import numpy as np
import torch
from mlx.utils import tree_flatten, tree_map, tree_unflatten


class TorchLstm(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.lstm = torch.nn.LSTM(input_size=2, hidden_size=6, batch_first=True)

    def forward(self, x, h=None, c=None):
        if h is not None:
            y, (h, c) = self.lstm(x, (h, c))
        else:
            y, (h, c) = self.lstm(x)
        return y, h, c


class MlxLstm(nn.Module):
    def __init__(self):
        super().__init__()
        self.lstm = nn.LSTM(input_size=2, hidden_size=6)

    def forward(self, x, h=None, c=None):
        """
        Args:
          x: (N, L, H)
          h: None or (N, H)
          c: None or (N, H)
        Returns:
          y: (N, L, H)
          h: (N, H)
          c: (N, H)
        """
        if h is None:
            h, c = self.lstm(x)
        else:
            h, c = self.lstm(x, h, c)
        # now both h and c are (N, L, H)

        return h, h[:, -1, :], c[:, -1, :]


def test_with_seq_len(torch_lstm, mx_lstm, N, T):
    x = torch.rand(N, T, 2)
    print("x", x.shape)

    y, h, c = torch_lstm(x)
    assert y.shape == (N, T, 6), y.shape
    assert h.shape == (1, N, 6), h.shape  # 1 is number of layers
    assert c.shape == (1, N, 6), h.shape

    ix = mx.array(x)
    mx_y, mx_h, mx_c = mx_lstm.forward(ix)
    assert mx_y.shape == (N, T, 6), mx_y.shape
    assert mx_h.shape == (N, 6), mx_h.shape
    assert mx_c.shape == (N, 6), mx_c.shape

    assert torch.allclose(y, torch.from_numpy(np.array(mx_y)))
    assert torch.allclose(h[0], torch.from_numpy(np.array(mx_h)))
    assert torch.allclose(c[0], torch.from_numpy(np.array(mx_c)))

    # now with states
    y, h, c = torch_lstm(x, h, c)
    assert y.shape == (N, T, 6), y.shape
    assert h.shape == (1, N, 6), h.shape  # 1 is number of layers
    assert c.shape == (1, N, 6), h.shape

    mx_y, mx_h, mx_c = mx_lstm.forward(ix, mx_h, mx_c)
    assert mx_y.shape == (N, T, 6), mx_y.shape
    assert mx_h.shape == (N, 6), mx_h.shape
    assert mx_c.shape == (N, 6), mx_c.shape

    assert torch.allclose(y, torch.from_numpy(np.array(mx_y)))
    assert torch.allclose(h[0], torch.from_numpy(np.array(mx_h)))
    assert torch.allclose(c[0], torch.from_numpy(np.array(mx_c)))


def test_single_layer():
    torch_lstm = TorchLstm()
    mx_lstm = MlxLstm()

    # ['lstm.weight_ih_l0', 'lstm.weight_hh_l0', 'lstm.bias_ih_l0', 'lstm.bias_hh_l0']
    print(list(torch_lstm.state_dict().keys()))
    for k, v in torch_lstm.state_dict().items():
        print(k, v.shape)
    """
    lstm.weight_ih_l0 torch.Size([24, 6])
    lstm.weight_hh_l0 torch.Size([24, 6])
    lstm.bias_ih_l0 torch.Size([24])
    lstm.bias_hh_l0 torch.Size([24])
    """

    # lstm
    print(mx_lstm.parameters().keys())

    # dict_keys(['Wx', 'Wh', 'bias'])
    print(mx_lstm.parameters()["lstm"].keys())
    for k, v in mx_lstm.parameters()["lstm"].items():
        print(k, v.shape)
    """
    Wx (24, 6)
    Wh (24, 6)
    bias (24,)
    """
    # convert
    state_dict = torch_lstm.state_dict()
    new_state_dict = dict()
    for k, v in state_dict.items():
        basename, pname = k.rsplit(".", 1)
        if "lstm" not in basename:
            # we convert only lstm in this for loop
            continue
        w_or_b, ih_or_hh, ln = pname.split("_")
        if w_or_b == "weight":
            new_name = "Wx" if ih_or_hh == "ih" else "Wh"
        elif w_or_b == "bias" and ih_or_hh == "ih":
            continue
        else:
            v = v + state_dict[k.replace("_hh_", "_ih_")]
            new_name = "bias"
        #  k = basename + "." + ln[1:] + "." + new_name # for multi-layer lstm
        k = basename + "." + new_name  # for multi-layer lstm
        new_state_dict[k] = v
    #  print("here", new_state_dict)
    #  print("here2", list(new_state_dict.items()))
    #  print("here3", tree_unflatten(list(new_state_dict.items())))
    #  print("here4", tree_flatten(tree_unflatten(list(new_state_dict.items()))))

    # convert torch.tensor to mx.array
    new_state_dict = tree_map(mx.array, new_state_dict)
    mx_lstm.update(tree_unflatten(list(new_state_dict.items())))

    for N in [1, 2, 3]:
        for T in [1, 2, 3]:
            test_with_seq_len(torch_lstm=torch_lstm, mx_lstm=mx_lstm, N=N, T=T)


@torch.no_grad()
def main():
    test_single_layer()


if __name__ == "__main__":
    torch.manual_seed(20250716)
    main()
