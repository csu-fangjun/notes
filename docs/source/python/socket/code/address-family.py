#!/usr/bin/env python3

import socket

print(list(socket.AddressFamily))
"""
[<AddressFamily.AF_UNSPEC: 0>, <AddressFamily.AF_UNIX: 1>,
<AddressFamily.AF_INET: 2>, <AddressFamily.AF_AX25: 3>,
<AddressFamily.AF_IPX: 4>, <AddressFamily.AF_APPLETALK: 5>,
<AddressFamily.AF_NETROM: 6>, <AddressFamily.AF_BRIDGE: 7>,
<AddressFamily.AF_ATMPVC: 8>, <AddressFamily.AF_X25: 9>,
<AddressFamily.AF_INET6: 10>, <AddressFamily.AF_ROSE: 11>,
<AddressFamily.AF_NETBEUI: 13>, <AddressFamily.AF_SECURITY: 14>,
<AddressFamily.AF_KEY: 15>, <AddressFamily.AF_NETLINK: 16>,
<AddressFamily.AF_PACKET: 17>, <AddressFamily.AF_ASH: 18>,
<AddressFamily.AF_ECONET: 19>, <AddressFamily.AF_ATMSVC: 20>,
<AddressFamily.AF_RDS: 21>, <AddressFamily.AF_SNA: 22>,
<AddressFamily.AF_IRDA: 23>, <AddressFamily.AF_PPPOX: 24>,
<AddressFamily.AF_WANPIPE: 25>, <AddressFamily.AF_LLC: 26>,
<AddressFamily.AF_CAN: 29>, <AddressFamily.AF_TIPC: 30>,
<AddressFamily.AF_BLUETOOTH: 31>, <AddressFamily.AF_ALG: 38>,
<AddressFamily.AF_VSOCK: 40>, <AddressFamily.AF_QIPCRTR: 42>]
"""

assert socket.AF_UNIX == socket.AddressFamily.AF_UNIX
assert socket.AF_INET == socket.AddressFamily.AF_INET
