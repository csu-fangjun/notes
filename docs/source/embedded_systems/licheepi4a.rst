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

