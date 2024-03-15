Lichee Pi 4A
============

Refer to :ref:`raspberry pi` to setup a DHCP server


After the board gets an IP, ssh to it.


.. code-block:: bash

   /sbin/ifconfig


It shows two interfaces: ``end0`` and ``end1``. We don't use ``lo`` and ``wlan0``.

``end0`` is for Ehternet0 and ``end1`` for Ethernet1.

Now we assign a static address to ``end0``.

.. code-block:: bash

   sudo vim /etc/network/interfaces

The default content is:

.. code-block:: bash

   source /etc/network/interfaces.d/*

We append the following to ``/etc/network/interfaces``:

.. code-block:: bash

   # this is a comment line
   # iface eth0 inet dhcp
   auto end0
   iface eth0 inet static
       address 192.168.1.8
       netmask 255.255.255.0


.. code-block:: bash

  sudo /etc/init.d/networking restart

Power off the board and connect ``end0`` to my mac.

Create a user:

.. code-block:: bash

   sudo adduser fangjun
   sudo usermod -a -G sudo fangjun

openKylin
---------

`<https://wiki.sipeed.com/hardware/zh/lichee/th1520/lpi4a/3_images.html#openKylin>`_

Download address `<https://www.openkylin.top/downloads/index-cn.html>`_. Select
``openKylin 2.0 alpha RISC-V`` for LiCheePi4A.

.. code-block::

   -rw-rw-r-- 1 fangjun fangjun 2.8G Mar  7 04:06 openKylin-2.0-alpha-licheepi4a.tar.xz

Power off the board, press the ``BOOT`` key and don't release it, power on, and then
release it. In virtual box, select the USB device ``T-HEAD USB download gadget [0223]``.

scp ``openKylin-2.0-alpha-licheepi4a.tar.xz`` to my virtual machine.

.. code-block:: bash

  scp -P 1234 openKylin-2.0-alpha-licheepi4a.tar.xz localhost:/mnt/sdb/shared


Refer to
`<https://docs.openkylin.top/zh/%E7%A4%BE%E5%8C%BA%E5%BC%80%E5%8F%91%E6%8C%87%E5%8D%97/riscv%E4%B8%8A%E5%AE%89%E8%A3%85openKylin>`_

On virtual machine::

  mkdir t
  cd t
  tar xf ../openKylin-2.0-alpha-licheepi4a.tar.xz
  cd openkylin-2.0-alpha-licheepi4a/fastboot/linux/

.. code-block:: bash

  $ lsusb
  Bus 002 Device 003: ID 2345:7654 T-HEAD USB download gadget

.. code-block:: bash

   sudo ./fastboot/linux/fastboot flash ram ./images/8G/u-boot-nonsec-2020.10-r0-noswap.bin

    Warning: skip copying ram image avb footer (ram partition size: 0, ram image size: 957544).
    Sending 'ram' (935 KB)                             OKAY [  0.384s]
    Writing 'ram'                                      OKAY [  0.008s]
    Finished. Total time: 0.444s

.. code-block:: bash

   sudo ./fastboot/linux/fastboot reboot

    Rebooting                                          OKAY [  0.031s]
    Finished. Total time: 1.451s

.. code-block:: bash

   sleep 1

   sudo ./fastboot/linux/fastboot flash uboot ./images/8G/u-boot-nonsec-2020.10-r0-noswap.bin

    Warning: skip copying uboot image avb footer (uboot partition size: 0, uboot image size: 957544).
    Sending 'uboot' (935 KB)                           OKAY [  0.259s]
    Writing 'uboot'                                    OKAY [  0.081s]
    Finished. Total time: 0.403s

.. code-block:: bash

   sudo ./fastboot/linux/fastboot flash boot ./images/8G/boot.ext4

    Warning: skip copying boot image avb footer (boot partition size: 409600, boot image size: 61440000).
    Sending 'boot' (60000 KB)                          OKAY [ 14.813s]
    Writing 'boot'                                     OKAY [  0.462s]
    Finished. Total time: 15.335s

.. code-block:: bash

    sudo ./fastboot/linux/fastboot flash root ./images/openkylin-2.0-alpha-licheepi4a-riscv64.ext4

Sending sparse 'root' 1/64 (113621 KB)             OKAY [ 28.396s]
Writing 'root'                                     OKAY [  1.437s]
Sending sparse 'root' 2/64 (114573 KB)             OKAY [ 28.678s]
Writing 'root'                                     OKAY [  1.119s]
Sending sparse 'root' 3/64 (114465 KB)             OKAY [ 31.803s]
Writing 'root'                                     OKAY [  3.088s]
Sending sparse 'root' 4/64 (114687 KB)             OKAY [ 29.581s]
Writing 'root'                                     OKAY [  1.332s]
Sending sparse 'root' 5/64 (114686 KB)             OKAY [ 29.088s]
Writing 'root'                                     OKAY [  1.243s]
Sending sparse 'root' 6/64 (114684 KB)             OKAY [ 28.922s]
Writing 'root'                                     OKAY [  0.926s]
Sending sparse 'root' 7/64 (110724 KB)             OKAY [ 27.861s]
Writing 'root'                                     OKAY [  0.868s]
Sending sparse 'root' 8/64 (106020 KB)             OKAY [ 26.523s]
Writing 'root'                                     OKAY [  0.905s]
Sending sparse 'root' 9/64 (114685 KB)             OKAY [ 29.080s]
Writing 'root'                                     OKAY [  0.990s]
Sending sparse 'root' 10/64 (113701 KB)            OKAY [ 28.919s]
Writing 'root'                                     OKAY [  1.000s]
Sending sparse 'root' 11/64 (114152 KB)            OKAY [ 29.780s]
Writing 'root'                                     OKAY [  1.916s]
Sending sparse 'root' 12/64 (113537 KB)            OKAY [ 29.624s]
Writing 'root'                                     OKAY [  1.600s]
Sending sparse 'root' 13/64 (113881 KB)            OKAY [ 29.739s]
Writing 'root'                                     OKAY [  1.634s]
Sending sparse 'root' 14/64 (113118 KB)            OKAY [ 28.989s]
Writing 'root'                                     OKAY [  1.169s]
Sending sparse 'root' 15/64 (106670 KB)            OKAY [ 27.178s]
Writing 'root'                                     OKAY [  1.157s]
Sending sparse 'root' 16/64 (114685 KB)            OKAY [ 29.728s]
Writing 'root'                                     OKAY [  1.656s]
Sending sparse 'root' 17/64 (112204 KB)            OKAY [ 28.763s]
Writing 'root'                                     OKAY [  0.990s]
Sending sparse 'root' 18/64 (114547 KB)            OKAY [ 30.126s]
Writing 'root'                                     OKAY [  1.495s]
Sending sparse 'root' 19/64 (111451 KB)            OKAY [ 28.567s]
Writing 'root'                                     OKAY [  1.276s]
Sending sparse 'root' 20/64 (114651 KB)            OKAY [ 29.283s]
Writing 'root'                                     OKAY [  1.380s]
Sending sparse 'root' 21/64 (104981 KB)            OKAY [ 27.260s]
Writing 'root'                                     OKAY [  1.565s]
Sending sparse 'root' 22/64 (108444 KB)            OKAY [ 28.772s]
Writing 'root'                                     OKAY [  1.958s]
Sending sparse 'root' 23/64 (112916 KB)            OKAY [ 27.882s]
Writing 'root'                                     OKAY [  0.964s]
Sending sparse 'root' 24/64 (110055 KB)            OKAY [ 28.402s]
Writing 'root'                                     OKAY [  1.373s]
Sending sparse 'root' 25/64 (114686 KB)            OKAY [ 29.349s]
Writing 'root'                                     OKAY [  1.308s]
Sending sparse 'root' 26/64 (109020 KB)            OKAY [ 28.892s]
Writing 'root'                                     OKAY [  1.883s]
Sending sparse 'root' 27/64 (113813 KB)            OKAY [ 30.411s]
Writing 'root'                                     OKAY [  2.091s]
Sending sparse 'root' 27/64 (113813 KB)            OKAY [ 30.411s]
Writing 'root'                                     OKAY [  2.091s]
Sending sparse 'root' 28/64 (112541 KB)            OKAY [ 28.959s]
Writing 'root'                                     OKAY [  1.048s]
Sending sparse 'root' 29/64 (108317 KB)            OKAY [ 27.795s]
Writing 'root'                                     OKAY [  0.927s]
Sending sparse 'root' 30/64 (103881 KB)            OKAY [ 26.063s]
Writing 'root'                                     OKAY [  0.883s]
Sending sparse 'root' 31/64 (112380 KB)            OKAY [ 28.106s]
Writing 'root'                                     OKAY [  0.923s]
Sending sparse 'root' 32/64 (113912 KB)            OKAY [ 28.863s]
Writing 'root'                                     OKAY [  0.887s]
Sending sparse 'root' 33/64 (107545 KB)            OKAY [ 27.507s]
Writing 'root'                                     OKAY [  0.901s]
Sending sparse 'root' 34/64 (108964 KB)            OKAY [ 27.396s]
Writing 'root'                                     OKAY [  0.924s]
Sending sparse 'root' 35/64 (114685 KB)            OKAY [ 28.831s]
Writing 'root'                                     OKAY [  1.052s]
Sending sparse 'root' 36/64 (114635 KB)            OKAY [ 29.927s]
Writing 'root'                                     OKAY [  1.857s]
Sending sparse 'root' 37/64 (106582 KB)            OKAY [ 34.001s]
Writing 'root'                                     OKAY [  4.941s]
Sending sparse 'root' 38/64 (112349 KB)            OKAY [ 28.087s]
Writing 'root'                                     OKAY [  1.019s]
Sending sparse 'root' 39/64 (114597 KB)            OKAY [ 28.444s]
Writing 'root'                                     OKAY [  1.003s]
Sending sparse 'root' 40/64 (113833 KB)            OKAY [ 28.063s]
Writing 'root'                                     OKAY [  0.955s]
Sending sparse 'root' 41/64 (111932 KB)            OKAY [ 27.982s]
Writing 'root'                                     OKAY [  0.852s]
Sending sparse 'root' 42/64 (114656 KB)            OKAY [ 29.274s]
Writing 'root'                                     OKAY [  0.919s]
Sending sparse 'root' 43/64 (114409 KB)            OKAY [ 28.753s]
Writing 'root'                                     OKAY [  1.011s]
Sending sparse 'root' 44/64 (112007 KB)            OKAY [ 28.708s]
Writing 'root'                                     OKAY [  1.232s]
Sending sparse 'root' 45/64 (114687 KB)            OKAY [ 29.922s]
Writing 'root'                                     OKAY [  1.978s]
Sending sparse 'root' 46/64 (114684 KB)            OKAY [ 28.482s]
Writing 'root'                                     OKAY [  0.903s]
Sending sparse 'root' 47/64 (111932 KB)            OKAY [ 28.518s]
Writing 'root'                                     OKAY [  0.917s]
Sending sparse 'root' 48/64 (106984 KB)            OKAY [ 26.597s]
Writing 'root'                                     OKAY [  0.869s]
Sending sparse 'root' 49/64 (114684 KB)            OKAY [ 28.722s]
Writing 'root'                                     OKAY [  0.888s]
Sending sparse 'root' 50/64 (113296 KB)            OKAY [ 27.990s]
Writing 'root'                                     OKAY [  0.901s]
Sending sparse 'root' 51/64 (114685 KB)            OKAY [ 28.955s]
Writing 'root'                                     OKAY [  1.035s]
Sending sparse 'root' 52/64 (114684 KB)            OKAY [ 28.549s]
Writing 'root'                                     OKAY [  0.906s]
Sending sparse 'root' 53/64 (114685 KB)            OKAY [ 29.215s]
Writing 'root'                                     OKAY [  1.025s]
Sending sparse 'root' 54/64 (102348 KB)            OKAY [ 24.596s]
Writing 'root'                                     OKAY [  1.030s]
Sending sparse 'root' 55/64 (113644 KB)            OKAY [ 28.859s]
Writing 'root'                                     OKAY [  0.899s]
Sending sparse 'root' 56/64 (111648 KB)            OKAY [ 28.154s]
Writing 'root'                                     OKAY [  0.940s]
Sending sparse 'root' 57/64 (105900 KB)            OKAY [ 26.766s]
Writing 'root'                                     OKAY [  0.832s]
Sending sparse 'root' 58/64 (104752 KB)            OKAY [ 26.516s]
Writing 'root'                                     OKAY [  0.832s]
Sending sparse 'root' 59/64 (114684 KB)            OKAY [ 28.399s]
Writing 'root'                                     OKAY [  0.963s]
Sending sparse 'root' 60/64 (114684 KB)            OKAY [ 28.732s]
Writing 'root'                                     OKAY [  0.912s]
Sending sparse 'root' 61/64 (110325 KB)            OKAY [ 27.705s]
Writing 'root'                                     OKAY [  0.991s]
Sending sparse 'root' 62/64 (114684 KB)            OKAY [ 28.856s]
Writing 'root'                                     OKAY [  0.897s]
Sending sparse 'root' 63/64 (109388 KB)            OKAY [ 27.435s]
Writing 'root'                                     OKAY [  0.860s]
Sending sparse 'root' 64/64 (24856 KB)             OKAY [  6.347s]
Writing 'root'                                     OKAY [  0.205s]
Finished. Total time: 1929.583s

.. code-block::

   username: openkylin
   password: openkylin

The network interfaces on openKylin is ``eth0`` and ``eth1``. The oringial
content of ``/etc/network/interfaces`` are::

  auto lo iface lo inet loopback
  auto eth0 iface eth0 inet dhcp

Change it to::

  auto lo iface lo inet loopback
  # auto eth0 iface eth0 inet dhcp
  iface eth0 inet static
    address 192.168.1.8
    netmask 255.255.255.0
