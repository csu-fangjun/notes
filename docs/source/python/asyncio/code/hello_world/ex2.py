#!/usr/bin/env python3

import asyncio
import time


loop = asyncio.get_event_loop()


@asyncio.coroutine
def hello():
    print(f"hello {time.strftime('%X')}")
    yield from asyncio.sleep(1)
    print(f"world {time.strftime('%X')}")


if __name__ == "__main__":
    loop.run_until_complete(hello())
