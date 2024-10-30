#!/usr/bin/env python3

import struct

def main():
    # by default it uses native format, e.g., little endian on my mac
    # a is in little endian and occupies 4 bytes
    a = struct.pack('i', 20)
    assert a == b'\x14\x00\x00\x00', a

    # Use little endian < explicitly
    b = struct.pack('<i', 20)
    assert b == b'\x14\x00\x00\x00', b

    # Use big endian c explicitly
    c = struct.pack('>i', 20)
    assert c == b'\x00\x00\x00\x14', c



if __name__ == '__main__':
    main()
