Cross compile
=============

.. code-block:: bash

   go env

.. literalinclude:: ./code/go-env.txt

Build for windows
-----------------

.. code-block:: bash

   GOOS=windows go build

Build for Linux
---------------

.. code-block:: bash

   GOOS=linux go build

Build for macOS
---------------

.. code-block:: bash

   GOOS=darwin go build
