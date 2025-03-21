#!/usr/bin/env python3

from contextlib import contextmanager

number = 10


def get_number():
    return number


def set_number(n):
    global number
    number = n


@contextmanager
def process(new_n):
    old_n = get_number()
    set_number(new_n)
    yield
    set_number(old_n)


with process(100):
    # inside this block ,number is changed to 100
    assert number == 100, number

# outside of the above block, number is reset to its original value
assert number == 10, number
