#!/usr/bin/env python3

import asyncio


async def main(f: asyncio.Future):
    await asyncio.sleep(1)
    f.set_result("I have finished")


loop = asyncio.get_event_loop()
f = asyncio.Future()
print(f.done())  # False
task = loop.create_task(main(f))

r = loop.run_until_complete(f)
print(f.done())  # True
print(type(r))  # <class 'str'>
print(r)  # I have finished
print(f.result())  # I have finished
print(f.done())  # True
