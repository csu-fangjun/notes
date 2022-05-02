#!/usr/bin/env python3


def hello():
    print("hello")
    a = yield "world"
    print("a is", a)


h = hello()
if 0 == 10:
    print(next(h))  # world
    print(next(h))  # a is None, and raise StopIteration
elif 1 == 10:
    print(h.send(None))  # None
    print(h.send("aaa"))  # a is aaa, raise StopIteration
elif 2 == 22:
    print(h.close())  # None
elif 3 == 3:
    print(next(h))  # world
    print(h.close())  # None
    print(h.send("bb"))  # raise StopIteration
