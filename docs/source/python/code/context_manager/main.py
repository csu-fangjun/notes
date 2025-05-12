#!/usr/bin/env python3

import contextlib
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
    try:
        yield
    finally:
        set_number(old_n)


print(process(1))  # <contextlib._GeneratorContextManager object at 0x108a2ccd0>
print(type(process(1)))  # <class 'contextlib._GeneratorContextManager'>
assert isinstance(process(1), contextlib._GeneratorContextManager), type(process(1))

with process(100):
    # inside this block ,number is changed to 100
    assert number == 100, number

# outside of the above block, number is reset to its original value
assert number == 10, number


class MyProcess:
    def __init__(self, new_n):
        self.new_n = new_n

    def __enter__(self):
        self.old_n = get_number()
        set_number(self.new_n)

    def __exit__(self, type, value, traceback):
        set_number(self.old_n)


with MyProcess(-1):
    assert number == -1, number

assert number == 10, number
