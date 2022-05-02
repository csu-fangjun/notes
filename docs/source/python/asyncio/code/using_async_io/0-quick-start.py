#!/usr/bin/env python3

import asyncio
import time


async def main():
    print(f"{time.ctime()} hello")
    await asyncio.sleep(1.0)
    print(f"{time.ctime()} world")


print(type(main))
print(type(main()))
