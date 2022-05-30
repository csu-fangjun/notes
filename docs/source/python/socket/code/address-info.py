#!/usr/bin/env python3

import socket

print(list(socket.AddressInfo))
"""
[<AddressInfo.AI_PASSIVE: 1>, <AddressInfo.AI_CANONNAME: 2>,
<AddressInfo.AI_NUMERICHOST: 4>, <AddressInfo.AI_V4MAPPED: 8>,
<AddressInfo.AI_ALL: 16>, <AddressInfo.AI_ADDRCONFIG: 32>,
<AddressInfo.AI_NUMERICSERV: 1024>]
"""
assert socket.AI_PASSIVE == socket.AddressInfo.AI_PASSIVE
