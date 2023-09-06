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
