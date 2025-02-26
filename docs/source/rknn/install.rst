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

wireless network
----------------

.. code-block:: bash

  $ ifconfig
  enP3p49s0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
          inet 192.168.1.9  netmask 255.255.255.0  broadcast 192.168.1.255
          inet6 fe80::e08a:3fa:a528:4b1f  prefixlen 64  scopeid 0x20<link>
          ether c0:74:2b:fd:cd:a1  txqueuelen 1000  (Ethernet)
          RX packets 143  bytes 15875 (15.8 KB)
          RX errors 0  dropped 0  overruns 0  frame 0
          TX packets 111  bytes 41059 (41.0 KB)
          TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

  lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
          inet 127.0.0.1  netmask 255.0.0.0
          inet6 ::1  prefixlen 128  scopeid 0x10<host>
          loop  txqueuelen 1000  (Local Loopback)
          RX packets 0  bytes 0 (0.0 B)
          RX errors 0  dropped 0  overruns 0  frame 0
          TX packets 0  bytes 0 (0.0 B)
          TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

  wlan0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
          ether c0:f5:35:ed:fb:25  txqueuelen 1000  (Ethernet)
          RX packets 0  bytes 0 (0.0 B)
          RX errors 0  dropped 0  overruns 0  frame 0
          TX packets 0  bytes 0 (0.0 B)
          TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

so we have ``wlan0``.

Use ``sudo iwlist wlan0 scan`` to scan available wireless networks.

It prints something like below::

  wlan0     Scan completed :
            Cell 01 - Address: 8C:53:C3:52:CC:3E
                      ESSID:"Xiaomi_CC3D"
                      Mode:Managed
                      Frequency:2.412 GHz (Channel 1)
                      Quality:5/5  Signal level:-55 dBm  Noise level:-81 dBm
                      IE: IEEE 802.11i/WPA2 Version 1
                          Group Cipher : TKIP
                          Pairwise Ciphers (2) : TKIP CCMP
                          Authentication Suites (1) : PSK
                      IE: Unknown: DD7C0050F204104A0001101044000102103B00010310470010BC329E001DD811B286018C53C352CC3E102100067869616F6D6910230002523410240004303030321042000831323334353637381054000800060050F20400011011000C5869616F4D69526F7574657210080002210C103C0001011049000600372A000120
                      IE: WPA Version 1
                          Group Cipher : TKIP
                          Pairwise Ciphers (2) : TKIP CCMP
                          Authentication Suites (1) : PSK
                      Encryption key:on
                      Bit Rates:1 Mb/s; 2 Mb/s; 5.5 Mb/s; 11 Mb/s; 9 Mb/s
                                18 Mb/s; 36 Mb/s; 54 Mb/s; 6 Mb/s; 12 Mb/s
                                24 Mb/s; 48 Mb/s
  Cell 06 - Address: 1A:8C:3A:63:6D:1B
                      ESSID:"meine"
                      Mode:Managed
                      Frequency=2.437 GHz (Channel 6)
                      Quality:5/5  Signal level:-44 dBm  Noise level:-81 dBm
                      IE: IEEE 802.11i/WPA2 Version 1
                          Group Cipher : CCMP
                          Pairwise Ciphers (1) : CCMP
                          Authentication Suites (1) : PSK
                      Encryption key:on
                      Bit Rates:1 Mb/s; 2 Mb/s; 5.5 Mb/s; 11 Mb/s; 6 Mb/s
                                9 Mb/s; 12 Mb/s; 18 Mb/s; 24 Mb/s; 36 Mb/s
                                48 Mb/s; 54 Mb/s


.. code-block:: bash

  $ wpa_passphrase your_wifi_ssid_name your_wifi_password | sudo tee /etc/wpa_supplicant.conf
  $ sudo wpa_supplicant -B -c /etc/wpa_supplicant.conf -i wlan0
  $ sudo dhclient wlan0

Now ``ifconfig wlan0`` should show its IP address.
