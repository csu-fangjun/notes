#!/usr/bin/env python3

import mlx.core as mx
import mlx.nn as nn
import numpy as np
import torch
from mlx.utils import tree_flatten, tree_map, tree_unflatten


class TorchLstm(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.lstm = torch.nn.LSTM(
            input_size=2, hidden_size=5, num_layers=3, batch_first=True
        )

    def forward(self, x, h=None, c=None):
        if h is not None:
            y, (h, c) = self.lstm(x, (h, c))
        else:
            y, (h, c) = self.lstm(x)
        return y, h, c


class MlxLstm(nn.Module):
    def __init__(self):
        super().__init__()
        self.lstm = []
        input_size = 2
        hidden_size = 5
        for i in range(3):
            in_size = input_size if i == 0 else hidden_size
            self.lstm.append(nn.LSTM(input_size=in_size, hidden_size=hidden_size))

    def forward(self, x, states=None):
        """
        Args:
          x: (N, L, C)
          states: None or a list containing 2*num_layers tensors
            - states[2*i] is the h of the i-th layer, of shape (N, C)
            - states[2*i+1] is the c of the i-th layer, of shape (N, C)
        Returns:
          y: (N, L, C)
          states: a list containing 2*num_layers tensors
            - states[2*i] is the h of the i-th layer, of shape (N, C)
            - states[2*i+1] is the c of the i-th layer, of shape (N, C)

        """

        if states is None:
            states = [None] * (len(self.lstm) * 2)

        new_states = []
        for i, layer in enumerate(self.lstm):
            h = states[2 * i]
            c = states[2 * i + 1]
            x, c = layer(x, h, c)
            new_states.append(x[:, -1, :])
            new_states.append(c[:, -1, :])
        return x, new_states


def test_with_seq_len(torch_lstm, mx_lstm, N, T):
    x = torch.rand(N, T, 2)
    print("x", x.shape)

    y, h, c = torch_lstm(x)
    assert y.shape == (N, T, 5), y.shape
    assert h.shape == (3, N, 5), h.shape  # 3 is number of layers
    assert c.shape == (3, N, 5), h.shape

    ix = mx.array(x)
    mx_y, states = mx_lstm.forward(ix)

    assert mx_y.shape == (N, T, 5), mx_y.shape
    assert torch.allclose(y, torch.from_numpy(np.array(mx_y)))

    for i in range(3):
        assert torch.allclose(h[i], torch.from_numpy(np.array(states[2 * i])))
        assert torch.allclose(c[i], torch.from_numpy(np.array(states[2 * i + 1])))
    print("mx_y", mx_y.shape, [s.shape for s in states])

    # now with states
    y, h, c = torch_lstm(x, h, c)
    assert y.shape == (N, T, 5), y.shape
    assert h.shape == (3, N, 5), h.shape  # 3 is number of layers
    assert c.shape == (3, N, 5), h.shape

    mx_y, states = mx_lstm.forward(ix, states)
    assert torch.allclose(y, torch.from_numpy(np.array(mx_y)))

    for i in range(3):
        assert torch.allclose(h[i], torch.from_numpy(np.array(states[2 * i])))
        assert torch.allclose(c[i], torch.from_numpy(np.array(states[2 * i + 1])))
    print("mx_y", mx_y.shape, [s.shape for s in states])


def test_multi_layers():
    torch_lstm = TorchLstm()
    mx_lstm = MlxLstm()
    #  mx.eval(mx_lstm.parameters())

    # ['lstm.weight_ih_l0', 'lstm.weight_hh_l0', 'lstm.bias_ih_l0',
    # 'lstm.bias_hh_l0', 'lstm.weight_ih_l1', 'lstm.weight_hh_l1',
    # 'lstm.bias_ih_l1', 'lstm.bias_hh_l1', 'lstm.weight_ih_l2',
    # 'lstm.weight_hh_l2', 'lstm.bias_ih_l2', 'lstm.bias_hh_l2']
    print(list(torch_lstm.state_dict().keys()))
    for k, v in torch_lstm.state_dict().items():
        print(k, v.shape)
    """
    lstm.weight_ih_l0 torch.Size([12, 2])
    lstm.weight_hh_l0 torch.Size([12, 3])
    lstm.bias_ih_l0 torch.Size([12])
    lstm.bias_hh_l0 torch.Size([12])
    lstm.weight_ih_l1 torch.Size([12, 3])
    lstm.weight_hh_l1 torch.Size([12, 3])
    lstm.bias_ih_l1 torch.Size([12])
    lstm.bias_hh_l1 torch.Size([12])
    lstm.weight_ih_l2 torch.Size([12, 3])
    lstm.weight_hh_l2 torch.Size([12, 3])
    lstm.bias_ih_l2 torch.Size([12])
    lstm.bias_hh_l2 torch.Size([12])
    """

    # lstm
    print(mx_lstm.parameters().keys())
    assert isinstance(mx_lstm.parameters()["lstm"], list)
    assert len(mx_lstm.parameters()["lstm"]) == 3, len(mx_lstm.parameters())

    # dict_keys(['Wx', 'Wh', 'bias'])
    print(mx_lstm.parameters()["lstm"][0].keys())
    for k, v in mx_lstm.parameters()["lstm"][0].items():
        print(k, v.shape)

    """
    Wx (12, 2)
    Wh (12, 3)
    bias (12,)
    """
    print(mx_lstm.parameters()["lstm"][1].keys())
    for k, v in mx_lstm.parameters()["lstm"][1].items():
        print(k, v.shape)
    """
    Wx (12, 3)
    Wh (12, 3)
    bias (12,)
    """
    # a list of tuple
    # [('lstm.0.Wx', array(...)),
    #  ('lstm.1.Wh', array(...)) ]
    #  print(tree_flatten(mx_lstm.parameters()))

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
        k = basename + "." + ln[1:] + "." + new_name
        new_state_dict[k] = v

    # convert torch.tensor to mx.array
    new_state_dict = tree_map(mx.array, new_state_dict)
    mx_lstm.update(tree_unflatten(list(new_state_dict.items())))
    print("updated")

    for N in [1, 2, 3]:
        for T in [1, 2, 3]:
            test_with_seq_len(torch_lstm=torch_lstm, mx_lstm=mx_lstm, N=N, T=T)


@torch.no_grad()
def main():
    test_multi_layers()


if __name__ == "__main__":
    torch.manual_seed(20250716)
    main()
