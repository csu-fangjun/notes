Hello
=====

.. literalinclude:: ./code/hello/hello.py

.. code-block:: bash

   flask --app hello run

The default filename is ``app.py``. Since ours is ``hello.py`` we have to
use ``--app hello``.

To listen on all public IP addresses, use:

.. code-block:: bash

   flask --app hello run --host=0.0.0.0

To enable debug mode, use ``flask --app hello run --debug``
