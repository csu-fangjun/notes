#!/usr/bin/env python3

import time
import socket


def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(("localhost", 6006))
    for i in range(5):
        sock.send("hello".encode())
        b = sock.recv(1024)
        print(b.decode())
        time.sleep(0.5)


if __name__ == "__main__":
    main()
