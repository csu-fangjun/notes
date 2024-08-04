Install
=======

Free pascal
-----------

macos
~~~~~

Visit `<https://www.freepascal.org/>`_ to download a ``*.pkg`` file for macOS.
After installing, we will get an executable ``fpc`` in the command line.

``which fpc`` prints ``/usr/local/bin/fpc``.

``/usr/local/share/src/fpc-3.2.2/demo`` contains examples.

Linux
~~~~~

Visit `<https://www.freepascal.org/>`_ to download a ``*.tar`` file for Linux.

After unzipping, we get::

  (py311) fangjun@ubuntu23-04:/mnt/sdb/shared/fpc-3.2.2.x86_64-linux$ ls
  binary.x86_64-linux.tar  demo.tar.gz  doc-pdf.tar.gz  install.sh

Run ``./install.sh``.

  1. Install prefix ``/mnt/sdb/shared/fpc-3.2.2``
  2. Install documentation
  3. Install demo to ``/mnt/sdb/shared/fpc-3.2.2/share/doc/fpc-3.2.2/examples``
  4. Add ``/mnt/sdb/shared/fpc-3.2.2/bin`` to ``PATH``

.. code-block:: bash

  mkdir t
  cd t
  cp /mnt/sdb/shared/fpc-3.2.2/share/doc/fpc-3.2.2/examples/text/hello.pp .
  fpc ./hello.pp
  file ./hello

  hello: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), statically linked, for GNU/Linux 2.4.0, stripped

  ls -lh hello
  -rwxrwxr-x 1 fangjun fangjun 187K Aug  4 15:18 hello

  ./hello
  Hello world

Note that it is statically linked!

