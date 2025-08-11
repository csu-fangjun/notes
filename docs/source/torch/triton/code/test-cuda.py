#!/usr/bin/env python3

import torch

"""
L2_cache_size: 6291456
gcnArchName: Tesla V100-PCIE-32GB
is_integrated: 0
is_multi_gpu_board: 0
major: 7
max_threads_per_multi_processor: 2048
minor: 0
multi_processor_count: 80
name: Tesla V100-PCIE-32GB
regs_per_multiprocessor: 65536
shared_memory_per_block: 49152
shared_memory_per_block_optin: 98304
shared_memory_per_multiprocessor: 98304
total_memory: 34079899648
uuid: 2e9d29fc-608b-1348-6c9d-c190dc3bddbe
warp_size: 32
"""


def test():
    #  print(help(torch.cuda.get_device_properties("cuda:0")))
    props = torch.cuda.get_device_properties(0)
    for attr in dir(props):
        # skip internal/private attributes
        if not attr.startswith("_"):
            print(f"{attr}: {getattr(props, attr)}")


def main():
    test()


if __name__ == "__main__":
    main()
