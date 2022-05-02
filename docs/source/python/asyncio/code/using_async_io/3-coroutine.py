#!/usr/bin/env python3
import inspect


async def f():
    return 123


print(type(f))  # <class 'function'>
print(inspect.iscoroutinefunction(f))  # True

coro = f()
print(type(coro))  # <class 'coroutine'>

try:
    coro.send(None)
except StopIteration as e:
    # When the coroutine returns, it raises StopIteration
    print(f"The answer is {e.value}")  # The answer is 123
