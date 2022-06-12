#!/usr/bin/env python3
import socket
import threading

# nc localhost 6006


def run_server():
    sock = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(("", 6006))
    sock.listen(2)  # backlog is 2
    while True:
        client_sock, addr = sock.accept()
        assert isinstance(client_sock, socket.socket)
        assert isinstance(addr, tuple)
        assert isinstance(addr[0], str)
        assert isinstance(addr[1], int)
        print("Connected from", addr)  # Connected from ('127.0.0.1', 54266)
        threading.Thread(target=handle_client, args=(client_sock,)).start()


def handle_client(sock: socket.socket):
    while True:
        data = sock.recv(1024)
        if not data:
            break
        sock.sendall(data.decode("utf-8").upper().encode())
    print("Disconnected from", sock.getpeername())
    sock.close()


if __name__ == "__main__":
    run_server()
