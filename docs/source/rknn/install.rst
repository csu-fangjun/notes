Install
=======

- User manual: `<https://drive.google.com/drive/u/0/folders/1kzMRI95yaXLbQuK86fUbs92NJ6QOYIGO>`_
- Ubuntu images: `<https://drive.google.com/drive/u/0/folders/1qSA5yr_UOll3LKMzdn74i_SCYygnIcJ8>`_
- Android images: `<https://drive.google.com/drive/u/0/folders/1SQcrQI8Qn1MbAcv3ggxhAPyIMTQ2-Xog?usp=sharing>`_

I have downloaded ``Orangepi5max_1.0.0_ubuntu_jammy_server_linux6.1.43.7z``. Unzip it
and we get a folder ``Orangepi5max_1.0.0_ubuntu_jammy_server_linux6.1.43``.

There are two files in the folder: ``Orangepi5max_1.0.0_ubuntu_jammy_server_linux6.1.43.img``
and ``Orangepi5max_1.0.0_ubuntu_jammy_server_linux6.1.43.img.sha``

Go to `<https://etcher.balena.io/#download-etcher>`_ and download it.  Burn the ``.img``
file into a tf card.

After the board gets an IP, ssh to it.

Both the username and password are the same, ``orangepi``.


.. code-block:: bash

   ifconfig

It shows the wired network interface is ``enP3p49s0``

Now we assign a static address to ``enP3p49s0``.

.. code-block:: bash

   sudo vim /etc/network/interfaces

The default content is:

.. code-block:: bash

   source /etc/network/interfaces.d/*
   #
   auto lo
   iface lo inet loopback

We append the following to ``/etc/network/interfaces``:

.. code-block:: bash

   # this is a comment line
   iface enP3p49s0 inet static
       address 192.168.1.9
       netmask 255.255.255.0

.. code-block:: bash

  sudo /etc/init.d/networking restart

If it does not work, use ``nmcli connection show`` to list current connections, which
displays::

  NAME                          UUID       TYPE        DEVICE
  Wired connection 1            xxxx       ethernet    enP3p49s0

Then run ``nmcli connection mod "Wire connection 1" ipv4.addresses "192.168.1.9/24" ipv4.method "manual"

Then run ``sudo reboot``.

Power off the board and connect it to my mac.
