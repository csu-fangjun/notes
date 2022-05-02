#!/usr/bin/env python3

import asyncio

loop = asyncio.get_event_loop()


@asyncio.coroutine
def hello():
    print("hello")
    yield from asyncio.sleep(3)
    print("world")


if __name__ == "__main__":
    loop.run_until_complete(hello())
