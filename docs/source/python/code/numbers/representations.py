#!/usr/bin/env python3

print(bin(1))  # 0b1
print(bin(3))  # 0b11
print(bin(255))  # 0b11111111
print(bin(256))  # 0b100000000
assert isinstance(bin(1), str)
assert int("11", base=2) == 3
assert int("0b11", base=0) == 3
assert hex(2) == "0x2"
assert hex(10) == "0xa"

assert oct(10) == "0o12"
assert int("12", base=8) == 10
assert int("0o12", base=0) == 10

assert 1_000 == 1000
assert 1_000_000 == 1000000
