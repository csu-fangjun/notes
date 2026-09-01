nano-pi
=======

- user: pi, password pi
- user: root, password: fa

How to assign a static IP on Ubuntu 16.04:

.. code-block::

   ifconfig # it shows eth0

   sudo vim /etc/network/interfaces

The default content is:

.. code-block:: bash

   auto lo
   iface lo inet loopback

Add the following:

.. code-block:: bash

   # this is a comment line
   # iface eth0 inet dhcp
   iface eth0 inet static
       address 192.168.1.100
       netmask 255.255.255.0

.. code-block:: bash

  sudo /etc/init.d/networking restart


Recording:

.. code-block:: bash

   arecord -l
   arecord -Dhw:0,1 -f S16_LE -r 16000 -d 10 -c 2 -t wav test.wav

Install cmake from source:

.. code-block:: bash

     ./configure -- -DCMAKE_USE_OPENSSL=OFF -DBUILD_TESTING=OFF

.. code-block:: bash

   sudo apt-get install cmake
   sudo apt-get install libasound2-dev alsa-utils


ssh config on macos:

.. code-block:: bash

  Host nano-pi
    Hostname 192.168.1.3
    User pi
    IdentityFile ~/.ssh/pi
    RemoteForward 8080 localhost:8080

.. code-block:: bash

   sudo ifup eth0
