Basics
======

Environment variables
---------------------

``go env VARIABLE_NAME`` to view the value of the go environment variable
with name ``VARIABLE_NAME``.

.. code-block:: bash

   go env GOPATH
   go env GOARCH # example value: amd64, 386, arm
   go env GOOS # example value: linux, darwin, windows

``go help environment``

Hello world
-----------

See `<https://go.dev/doc/tutorial/getting-started>`_

.. code-block:: bash

   go mod init example/hello

The above command will create a file ``go.mod`` in the current directory.

.. code-block:: bash

  # content of go.mod
  module example/hello

  go 1.20

Note that ``go mod init`` does not create any directories. It only creates
a file ``go.mod`` with the above content.

verbose build
-------------

.. code-block:: bash

   go build -x -v


exported
--------

For non-builtin functions and variables, if the name begin with an uppercase,
then it is exported. Otherwise, it is not exported.

Note that for builtin functions, the above rule does not apply. For instance,
both ``print`` and ``println`` are exported.


