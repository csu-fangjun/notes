#!/usr/bin/env python3

import socket

print(list(socket.SocketKind))
"""
[<SocketKind.SOCK_STREAM: 1>, <SocketKind.SOCK_DGRAM: 2>,
<SocketKind.SOCK_RAW: 3>, <SocketKind.SOCK_RDM: 4>,
<SocketKind.SOCK_SEQPACKET: 5>, <SocketKind.SOCK_NONBLOCK: 2048>,
<SocketKind.SOCK_CLOEXEC: 524288>]
"""

assert socket.SOCK_STREAM == socket.SocketKind.SOCK_STREAM
assert socket.SOCK_DGRAM == socket.SocketKind.SOCK_DGRAM
