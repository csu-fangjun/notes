star visionfive 2
=================

boot mode settings:

  - `<https://doc-en.rvspace.org/VisionFive2/Quick_Start_Guide/VisionFive2_SDK_QSG/boot_mode_settings.html>`_
  - RGPIO_1: low, RGPI_0: high for sd card

Note: The network interface name of the board is end1 and end0

  - QR CODE -> end0
  - FLY_CORE FC-11Q280 2307 -> end1, I have set static IP address for it: 192.168.1.100

Login:

  - username: ``user``
  - password: ``starfive`` (the same password for root)


Install toolchains:

.. code-block:: bash

  sudo apt-get install -y gcc-riscv64-linux-gnu

Setup proxy:

.. code-block:: bash

  # on my macOS
  Host starfive
    Hostname 192.168.1.100
    User user
    IdentityFile ~/.ssh/starfive
    RemoteForward 8080 localhost:8080

.. code-block:: bash

   # on the board
   export http_proxy=http://localhost:8080
   export HTTP_PROXY=http://localhost:8080

   sudo touch /etc/apt/apt.conf.d/proxy.conf
   sudo vi /etc/apt/apt.conf.d/proxy.conf

   # Add one line to proxy.conf
   Acquire::http::Proxy "http://user:password@proxy.server:port/";
   Acquire::https::Proxy "http://user:password@proxy.server:port/";

Python proxy server

.. code-block::  bash

  https://github.com/csukuangfj/python-proxy-server

Free space:

.. code-block:: bash

   df -h
   cd /usr/share
   sudo rm -rf help
   sudo rm -rf doc

install usb:

.. code-block:: bash

   wget https://snapshot.debian.org/archive/debian-ports/20221225T084846Z/pool-riscv64/main/u/usbutils/usbutils_014-1+b1_riscv64.deb

   sudo apt-get install ./usbutils*.deb

   wget https://snapshot.debian.org/archive/debian-ports/20221225T084846Z/pool-riscv64/main/n/net-tools/net-tools_2.10-0.1_riscv64.deb
   sudo apt-get install ./net-tools*.deb

.. code-block:: bash

   lsusb
   cat /proc/asound/cards
   lsmod

Compile the kernel by ourselves:

  See `<https://github.com/starfive-tech/VisionFive2>`_

.. code-block:: bash

   git clone https://github.com/starfive-tech/VisionFive2

   sudo apt-get install build-essential g++ git autoconf automake autotools-dev texinfo bison xxd curl flex gawk gdisk gperf libgmp-dev libmpfr-dev libmpc-dev libz-dev libssl-dev libncurses-dev libtool patchutils python3 screen texinfo unzip zlib1g-dev libyaml-dev wget cpio bc dosfstools mtools device-tree-compiler libglib2.0-dev libpixman-1-dev kpartx

   sudo apt-get install git-lfs

   cd ~/VisionFive2/
   git checkout JH7110_VisionFive2_devel
   git submodule update --init --recursive
   cd buildroot && git checkout --track origin/JH7110_VisionFive2_devel && cd ..
   cd u-boot && git checkout --track origin/JH7110_VisionFive2_devel && cd ..
   cd linux && git checkout --track origin/JH7110_VisionFive2_devel && cd ..
   cd opensbi && git checkout master && cd ..
   cd soft_3rdpart && git checkout JH7110_VisionFive2_devel && cd ..

   cd ~/VisionFive2/soft_3rdpart/IMG_GPU/out
   git lfs pull

   cd ~/VisionFive2/
   make -j$(nproc)
   make buildroot_rootfs -j$(nproc)
   make img

   # The generated file is work/sdcard.img
   # username: root
   # password: starfive
   # The inner network interface is eth1, i.e., the inerface with name FLY_CORE
   # The outer network interface is eth0, i.e., the interface with a QR code

.. code-block::

   # after login with root
   vi /etc/network/interfaces

   # iface eth1 inet dhcp
   #   pre-up /etc/network/nfs_check
   #   wait-delay 15
   #   hostname $(hostname)
   iface eth1 inet static
       address 192.168.1.100
       netmask 255.255.255.0

.. code-block:: bash

    /etc/init.d/S40network restart

To show the current directory in the terminal:

.. code-block:: bash

   PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\W\[\033[00m\]\$ '

