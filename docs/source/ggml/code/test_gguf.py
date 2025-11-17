#!/usr/bin/env python3

# https://huggingface.co/rgerganov/yolo-gguf/blob/main/yolov3-tiny.gguf

import struct


def main():
    f = open("./yolov3-tiny.gguf", "rb")
    header = f.read(4)
    print(header.decode())

    version = f.read(4)

    print(version)
    print(struct.unpack("I", version))

    num_tensors = f.read(8)
    print(struct.unpack("q", num_tensors))

    kv = f.read(8)
    print(struct.unpack("q", kv))


if __name__ == "__main__":
    main()
