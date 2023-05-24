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
