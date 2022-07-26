#!/usr/bin/env python3

import asyncio

loop = asyncio.get_event_loop()
future = loop.create_future()
stop_future = loop.create_future()


async def func1():
    global future
    await asyncio.sleep(1)
    future.set_result(10)


async def func2():
    global stop_future
    await asyncio.sleep(2)
    stop_future.set_result(3)


async def main():
    global future, stop_future
    task = asyncio.create_task(func1())
    task2 = asyncio.create_task(func2())
    await task
    await task2
    r = await future
    print(r)
    await stop_future


asyncio.run(main())
loop = asyncio.get_running_loop()
print(loop)
