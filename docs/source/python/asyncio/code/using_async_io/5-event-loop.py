#!/usr/bin/env python3
import asyncio


async def f():
    await asyncio.sleep(0)
    return 111


loop = asyncio.get_event_loop()
coro = f()
r = loop.run_until_complete(coro)
assert isinstance(r, int)
assert r == 111
