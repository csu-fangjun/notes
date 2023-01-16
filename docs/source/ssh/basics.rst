Basics
======

Use only password:

.. code-block:: bash

  ssh -o PubkeyAuthentication=no -o PreferredAuthentications=password  example.com

Remote forward
--------------

.. code-block:: bash

  # Run it on host2
  ssh -R 6006:localhost:22 foo@host1
  # We can access the port 6006 on host1, which is forwarded to host2's localhost:22

Local forward
-------------

.. code-block:: bash

  # Run it on host2
  ssh -L 6006:localhost:22 foo@host1
  # We can access the 6006 on host2, which is forwarded to host1's localhost:22








