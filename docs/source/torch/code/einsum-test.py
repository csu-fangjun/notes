#!/usr/bin/env python3

import torch


# mat multiply
def test_case1():
    a = torch.rand(2, 3)
    b = torch.rand(3, 5)
    c = torch.matmul(a, b)
    d = torch.einsum("ij,jk", a, b)
    assert torch.allclose(c, d)

    # ->ik is optional
    e = torch.einsum("ij,jk->ik", a, b)
    assert torch.allclose(c, e)

    # also transpose the output
    f = torch.einsum("ij,jk->ki", a, b)
    assert torch.allclose(c.t(), f)
    print(c)
    print(d)
    print(e)
    print(f)


# extract diagonal
def test_case2():
    a = torch.arange(25).reshape(5, 5)

    # extract diagonal of a square matrix
    b = torch.einsum("ii->i", a)
    c = torch.diag(a, diagonal=0)
    assert torch.equal(b, c)
    print(a)
    print(b)
    print(c)
    print(a.shape, b.shape, c.shape, a.dtype, b.dtype, c.dtype)


# element-wise product
def test_case3():
    a = torch.rand(3, 5)
    b = torch.rand(3, 5)

    # element-wise product
    c = torch.einsum("ij,ij->ij", a, b)

    assert a.shape == b.shape == c.shape, (a.shape, b.shape, c.shape)

    d = a * b

    assert torch.allclose(c, d)

    #  a**3
    e = torch.einsum("ij,ij,ij->ij", a, a, a)
    f = a**3
    assert torch.allclose(e, f)


def my_einsum(a, b, c):
    return torch.einsum("ijkl, ijlm, ikml -> ijkm", a, b, c)


def test_einsum():
    i = 2
    j = 3
    k = 4
    l = 5
    m = 6
    a = torch.rand(i, j, k, l)
    b = torch.rand(i, j, l, m)
    c = torch.rand(i, k, m, l)

    scores = torch.einsum("ijkl, ijlm, ikml -> ijkm", a, b, c)
    m = torch.compile(my_einsum)
    scores_2 = m(a, b, c)

    assert torch.allclose(scores, scores_2)

    m3 = torch.compile(torch.einsum)
    scores_3 = m3("ijkl, ijlm, ikml -> ijkm", a, b, c)
    assert torch.allclose(scores, scores_3)


def main():
    #  test_case1()
    #  test_case2()
    #  test_case3()
    test_einsum()


if __name__ == "__main__":
    torch.manual_seed(20250623)
    main()
