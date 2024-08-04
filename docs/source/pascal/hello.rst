Hello
=====

file extensions
---------------

  - ``xx.pp``
  - ``xx.ppu``, binary file, ``u`` is unit. A ``xx.ppu`` must be associated with a ``xx.o`` file to be usable
  - ``xx.pas``
  - ``xx.o``

``fpc ./hello.pp`` will generate two files: ``./hello`` and ``./hello.o``.
We can delete ``./hello.o`` in this case since ``./hello` is an executable.

``fpc hello``

unit search path
----------------

Unit search path::

  -Fu/some/path/to/some/dir

By default, the environment variable ``FPCDIR`` is also on the unit search path.
If ``FPCDIR`` is not set, it is ``/usr/local/lib/fpc/FPCVERSION`` by default.

For instance it is ``/usr/local/lib/fpc/3.2.2`` on my macOS.

.. code-block::

  # on macOS

  ls /usr/local/lib/fpc/3.2.2/units/
  aarch64-darwin i386-darwin    x86_64-darwin

  # on Ubuntu

  fangjun@ubuntu23-04:/mnt/sdb/shared/fpc-3.2.2/lib/fpc/3.2.2$ ls units/
  x86_64-linux


See unit search paths::

  fpc -vu ./hello.pp

To specify a compiler config file::

  fpc @./my.cfg ./hello.pp

where ``./my.cfg`` is something like below::

  -Fu/etc/


include file search path
------------------------

.. code-block::

   -I/some/path
   -Fi/some/path

Both ``-I`` and ``-Fi`` can be used.

Config file
-----------

The default config file ``fpc.cfg`` is

  - ``$PWD/fpc.cfg``
  - ``$HOME/.fpc.cfg``
  - ``$PPC_CONFIG_PATH/fpc.cfg``, where ``PPC_CONFIG_PATH`` is an environment variable
    In the ``etc`` directory above the ``fpc`` ``bin`` directory
  - ``/etc/fpc.cfg``

