Install
=======

.. code-block:: bash

   git clone --depth 1 https://github.com/qemu/qemu
   cd qemu

qemu-arm
--------

Refer to `<https://github.com/Tencent/ncnn/blob/master/.github/workflows/linux-arm-cpu-gcc.yml>`_

.. code-block:: bash

   # To generate only qemu-arm
   ./configure --prefix=/ceph-fj/fangjun/software/qemu/ --target-list=arm-linux-user --disable-system
   make -j10

   # It genertates the executable: ./build/qemu-arm

   # If we run `make install`, it will generate
   #
   # /ceph-fj/fangjun/software/qemu/bin/qemu-arm
   #
   # Add it to PATH and use it!

To run it, we have to download some cross-compile toochain, e.g,

Go to `<https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads/8-3-2019-03>`_ to download the toolchain.

.. code-block:: bash

  mkdir /ceph-fj/fangjun/software
  cd /ceph-fj/fangjun/software
  tar xvf /path/to/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf.tar.xz

  export PATH=/ceph-fj/fangjun/software/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin:$PATH


If we have built an executable using the above toolchain, we can run it with ``qemu-arm``:

.. code-block:: bash

   ./build/qemu-arm /path/to/sherpa-ncnn

It throws the following error:

.. code-block:: bash

  qemu-arm: Unable to reserve 0xfffff000 bytes of virtual address space at
  0x1000 (Success) for use as guest address space (check your virtual memory
  ulimit setting, min_mmap_addr or reserve less using -R option)

We can use

.. code-block:: bash

  ./build/qemu-arm -B 0x10000000 /path/to/sherpa-ncnn

which throws the following new error:

.. code-block:: bash

  (py38) kuangfangjun:qemu$ find /ceph-fj/fangjun/software/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/ -name "ld-linux-armhf.so.3"
  /ceph-fj/fangjun/software/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/arm-linux-gnueabihf/libc/lib/ld-linux-armhf.so.3
  (py38) kuangfangjun:qemu$ export QEMU_LD_PREFIX=/ceph-fj/fangjun/software/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/arm-linux-gnueabihf/libc

Now we can restart:

.. code-block:: bash

  ./build/qemu-arm -B 0x10000000 /path/to/sherpa-ncnn

