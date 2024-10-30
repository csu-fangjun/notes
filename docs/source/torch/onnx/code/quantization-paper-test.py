#!/usr/bin/env python3

import math


def test_asymmetric_quant():
    # We use the notation from
    # https://arxiv.org/pdf/2004.09602
    # equation 1 and 2
    #
    # f(x) = sx + z
    # it is called asymmetric because
    # float_low != -float_high
    # and
    # int_low != -int_high
    #
    # It is also called affine quantization in this paper

    float_low = -3
    float_high = 4

    int_low = -128
    int_high = 127

    s = (int_high - int_low) / (float_high - float_low)  # 36.4285
    z1 = -float_low * s - 127  # -17.71
    z = -round(float_low * s) - 127  # -18
    print(s, z1, z)

    f = lambda x: round(s * x) + z

    print(f(float_low), f(float_high), f(1))  # -127, 128, 18


def test_symmetric_quant():
    # We use the notation from
    # https://arxiv.org/pdf/2004.09602
    # equation 1 and 2
    #
    # f(x) = sx + z, where z is 0
    # it is called symmetric because
    # float_low == -float_high
    # and
    # int_low == -int_high
    #
    # It is also called affine quantization in this paper

    float_low = -4
    float_high = 4

    int_low = -127
    int_high = 127

    s = (int_high - int_low) / (float_high - float_low)  # 36.4285
    z1 = -float_low * s - 127  # -17.71
    z = -round(float_low * s) - 127  # -18
    print(s, z1, z)  # 31.75  0.0 0

    f = lambda x: round(s * x) + z

    print(f(float_low), f(float_high), f(1))  # -127, 127, 32


def main():
    print("---asymmetric---")
    test_asymmetric_quant()
    print("---symmetric---")
    test_symmetric_quant()


if __name__ == "__main__":
    main()
