#!/usr/bin/env python3

import asyncio

f = asyncio.Future()
print(f.done())  # False
f.set_result("hello")
print(f.result())  # hello
print(f.done())  # True
print(f.cancelled())  # False

g = asyncio.Future()
print(g.cancelled())  # False
g.cancel()
print(g.cancelled())  # True

h = asyncio.Future()
