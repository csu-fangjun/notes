ai-pro
======

- `<http://www.orangepi.cn/html/hardWare/computerAndMicrocontrollers/service-and-support/Orange-Pi-AIpro.html>`_
- `<http://www.orangepi.org/html/hardWare/computerAndMicrocontrollers/service-and-support/Orange-Pi-AIpro(8-12t).html>`_

user1
-----

- username: root
- password: Mind@123


user2
----

- username: HwHiAiUser
- password: Mind@123

static ip
---------

.. code-block:: bash

   ifconfig

shows ``eth0``.

Now we assign a static address to ``eth0``.

Use ``nmcli connection show`` to list current connections, which
displays::

  NAME                          UUID       TYPE        DEVICE
  Wired connection 1            xxxx       ethernet    eth0

Then run ``nmcli connection mod "Wired connection 1" ipv4.addresses "192.168.1.10/24" ipv4.method "manual"

Then run ``sudo reboot``.

Power off the board and connect it to my mac.

npu
----

- ACL: Ascend computing language
- CANN: Compute architecture for neural networks
