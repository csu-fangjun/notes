#!/usr/bin/env python3
import asyncio


#  async def f():
#      await asyncio.sleep(1.0)
#      return 123
#
#
#  async def main():
#      result = await f()
#      return result


async def f():
    return 123


async def f():
    try:
        while True:
            p = await asyncio.sleep(0)
            print("inside p", p)
    except asyncio.CancelledError:
        print("I was cancelled")
    else:
        return 111


coro = f()
p = coro.send(None)
print("p is", p)
coro.send(10)
coro.throw(asyncio.CancelledError)
"""
p is None
inside p None
I was cancelled
Traceback (most recent call last):
  File "./4-coroutine.py", line 34, in <module>
    coro.throw(asyncio.CancelledError)
StopIteration
"""
