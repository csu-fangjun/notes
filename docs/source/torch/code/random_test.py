#!/usr/bin/env python3

import torch


class Foo(torch.nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, x):
        y = torch.rand(*x.shape).to(x.device)
        return torch.nn.functional.dropout(x + y, p=0.3)


def test_cpu():
    f = Foo()

    x1 = torch.rand(3, 5)
    x2 = x1.clone()
    x3 = x1.clone()

    cpu_state = torch.get_rng_state()
    y1 = f(x1)
    print("y1", y1, y1.sum(), y1.mean())
    with torch.random.fork_rng(devices=[]):
        y2 = f(x2)

    with torch.random.fork_rng(devices=[]):
        torch.set_rng_state(cpu_state)
        y3 = f(x3)

    print("y2", y2, y2.sum(), y2.mean())
    print("y3", y3, y3.sum(), y3.mean())


def test_cuda():
    f = Foo()
    device = torch.device("cuda", 0)

    x1 = torch.rand(3, 5).to(device)
    x2 = x1.clone()
    x3 = x1.clone()

    cpu_state = torch.get_rng_state()
    cuda_state = torch.cuda.get_rng_state(device)
    print(
        "cuda_state",
        type(cuda_state),
        cuda_state.device,
        cuda_state.dtype,
        cuda_state.shape,
    )

    y1 = f(x1)
    print("y1", y1, y1.sum(), y1.mean())
    with torch.random.fork_rng(devices=[]):
        y2 = f(x2)

    with torch.random.fork_rng(devices=[device]):
        torch.set_rng_state(cpu_state)
        torch.cuda.set_rng_state(cuda_state, device)
        y3 = f(x3)

    print("y2", y2, y2.sum(), y2.mean())
    print("y3", y3, y3.sum(), y3.mean())


def main():
    test_cpu()
    print(torch.cuda.is_available())
    if torch.cuda.is_available():
        test_cuda()


if __name__ == "__main__":
    torch.manual_seed(20241030)
    main()

"""
----------macos----------
y1 tensor([[1.8172, 0.9755, 1.4394, 1.3970, 0.0000],
        [1.0299, 2.4723, 1.1365, 0.0000, 0.7647],
        [2.0160, 1.8454, 1.9144, 1.8337, 1.5052]]) tensor(20.1471) tensor(1.3431)
y2 tensor([[2.1100, 0.6028, 0.9254, 0.0000, 1.3935],
        [1.9948, 0.0000, 1.4811, 1.2179, 0.8196],
        [2.1118, 1.3885, 1.5176, 1.2972, 2.2623]]) tensor(19.1227) tensor(1.2748)
y3 tensor([[1.8172, 0.9755, 1.4394, 1.3970, 0.0000],
        [1.0299, 2.4723, 1.1365, 0.0000, 0.7647],
        [2.0160, 1.8454, 1.9144, 1.8337, 1.5052]]) tensor(20.1471) tensor(1.3431)
False
----------Linux----------
y1 tensor([[1.8172, 0.9755, 1.4394, 1.3970, 0.0000],
        [1.0299, 2.4723, 1.1365, 0.0000, 0.7647],
        [2.0160, 1.8454, 1.9144, 1.8337, 1.5052]]) tensor(20.1471) tensor(1.3431)
y2 tensor([[2.1100, 0.6028, 0.9254, 0.0000, 1.3935],
        [1.9948, 0.0000, 1.4811, 1.2179, 0.8196],
        [2.1118, 1.3885, 1.5176, 1.2972, 2.2623]]) tensor(19.1227) tensor(1.2748)
y3 tensor([[1.8172, 0.9755, 1.4394, 1.3970, 0.0000],
        [1.0299, 2.4723, 1.1365, 0.0000, 0.7647],
        [2.0160, 1.8454, 1.9144, 1.8337, 1.5052]]) tensor(20.1471) tensor(1.3431)
True
cuda_state <class 'torch.Tensor'> cpu torch.uint8 torch.Size([16])
y1 tensor([[1.2276, 0.0716, 0.0000, 0.5980, 1.4526],
        [1.5889, 0.5063, 0.0000, 1.0267, 1.5081],
        [1.7808, 1.3360, 1.5424, 1.8120, 0.0000]], device='cuda:0') tensor(14.4510, device='cuda:0') tensor(0.9634, device='cuda:0')
y2 tensor([[1.8274, 0.0000, 1.1841, 0.6805, 1.0811],
        [1.4730, 1.7636, 1.4561, 1.1214, 0.0000],
        [1.6906, 1.0212, 1.7333, 1.2885, 2.6000]], device='cuda:0') tensor(18.9209, device='cuda:0') tensor(1.2614, device='cuda:0')
y3 tensor([[1.2276, 0.0716, 0.0000, 0.5980, 1.4526],
        [1.5889, 0.5063, 0.0000, 1.0267, 1.5081],
        [1.7808, 1.3360, 1.5424, 1.8120, 0.0000]], device='cuda:0') tensor(14.4510, device='cuda:0') tensor(0.9634, device='cuda:0')
"""
