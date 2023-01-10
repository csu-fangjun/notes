Raspberry PI
============

How to connect it to Windows with direct ethernet connection
------------------------------------------------------------

1. Change the firewall on Windows to allow port for DHCP.
   The DHCP server uses port 67, supporting both TCP and UDP

2. Download a DHCP server from `<https://www.dhcpserver.de/cms/download/>`_.
   I have uploaded it to `<https://huggingface.co/csukuangfj/dhcp-server-for-windows>`_

3. Change the IP address of the network interface on Windows to ``192.168.1.2``.

4. Download and install wireshark. Start it to capture the traffic of the network
   interface, on which we will run the DHCP server. We can use the filter ``dhcp``
   to filter out packets.

5. Start the ``dhcpwiz.exe`` to configure the DHCP server. Wet set the starting
   address to ``192.168.1.100``. Note: Don't put ``192.168.1.2`` into the pool
   since it has already been occupied.

6. Use a network cable to connect the windows machine with Raspberry pi.

7. We can see the IP address of the Raspberry pi from the packets captured by wireshark.
