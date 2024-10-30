#!/usr/bin/env python3

import warnings

warnings.filterwarnings("ignore")

import torch


# sign: 1
# exp: 5
# significand: 10
def test_f16_subnormal():
    # For subnormal numbers, the exponent is always 0
    #
    # (-1)**sign_bit * 2**(-14) * 0.significantbits

    # use little endian
    b = b"\x00\x00"
    t = torch.frombuffer(b, dtype=torch.float16)

    # the smallest positive subnormal number
    b = b"\x01\x00"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = 2 ** (-14) * (0 + 1 / 1024)
    assert t == expected, (t, expected, t - expected)
    # t is about 0.000000059604645 = 5.9604645*1e-8

    # Use little endian, \x80 means the sign bit is 1
    b = b"\x01\x80"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = -1 * 2 ** (-14) * (0 + 1 / 1024)
    assert t == expected, (t, expected, t - expected)

    b = b"\xff\x03"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = 2 ** (-14) * (0 + 1023 / 1024)
    assert t == expected, (t, expected, t - expected)
    # t is about 0.000060975552 = 6.0975552*1e-5

    b = b"\xff\x83"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = -1 * 2 ** (-14) * (0 + 1023 / 1024)
    assert t == expected, (t, expected, t - expected)
    # -6.097555160522461e-05


# sign: 1
# exp: 5
# significand: 10
def test_f16_normal():
    # smallest positive normal number
    b = b"\x00\x04"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = 2 ** (-14) * (1 + 0 / 1024)  # 6.103515625e-05
    assert t == expected, (t, expected, t - expected)

    # largest number less than 1
    b = b"\xff\x3b"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = 2 ** (-1) * (1 + 1023 / 1024)  # 0.99951171875
    assert t == expected, (t, expected, t - expected)

    # 1
    # 0b 0 01111 0000000000
    # 0b 0011 1100 0000 0000
    # 0x 3c00
    b = b"\x00\x3c"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = 1
    assert t == expected, (t, expected, t - expected)

    # smallest number larger than 1
    b = b"\x01\x3c"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = 2 ** (0) * (1 + 1 / 1024)  # 1.0009765625
    assert t == expected, (t, expected, t - expected)

    # largest normal number
    # 0b 0 11110 1111111111
    # 0b 0111 1011 1111 1111
    # 0x7c ff
    b = b"\xff\x7b"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = 2 ** (15) * (1 + 1023 / 1024)  # 65504
    assert t == expected, (t, expected, t - expected)

    # -2
    # 0b 1 10000 0000000000
    # 0b 1100 0000 0000 0000
    # 0xc0 00
    b = b"\x00\xc0"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = -2
    assert t == expected, (t, expected, t - expected)

    b = b"\xff\xfb"
    t = torch.frombuffer(b, dtype=torch.float16).item()
    expected = (-1) * 2 ** (15) * (1 + 1023 / 1024)  # -65504
    assert t == expected, (t, expected, t - expected)


def main():
    test_f16_subnormal()
    test_f16_normal()


if __name__ == "__main__":
    main()
