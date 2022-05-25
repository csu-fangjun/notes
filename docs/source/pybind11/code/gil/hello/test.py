#!/usr/bin/env python3

import main

import threading


def f():
    print("hello")
    print(main.add(10, 20))
    print(main.add(10, 20))
    print(main.add(10, 20))


def f2():
    while True:
        print("f2")
        import time

        time.sleep(1)


if __name__ == "__main__":
    threading.Thread(target=f).start()
    threading.Thread(target=f2).start()
    #  threading.Thread(target=f).start()
    print(main.add(1, 2))
