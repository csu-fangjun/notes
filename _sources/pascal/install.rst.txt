Install
=======

online pascal compiler
----------------------

- `<https://www.onlinegdb.com/online_pascal_compiler>`_

Free pascal
-----------

macos
~~~~~

Visit `<https://www.freepascal.org/>`_ to download a ``*.pkg`` file for macOS.
After installing, we will get an executable ``fpc`` in the command line.

``which fpc`` prints ``/usr/local/bin/fpc``.

``/usr/local/share/src/fpc-3.2.2/demo`` contains examples.

.. code-block:: bash

  mkdir ~/t
  cd ~/t
  cp /usr/local/share/src/fpc-3.2.2/demo/text/hello.pp ./
  fpc ./hello.pp

  It throws the following error::
  Free Pascal Compiler version 3.2.2 [2021/05/16] for x86_64
  Copyright (c) 1993-2021 by Florian Klaempfl and others
  Target OS: Darwin for x86_64
  Compiling ./hello.pp
  Assembling hello
  Linking hello
  ld: library not found for -lc
  An error occurred while linking
  hello.pp(19,27) Error: Error while linking
  hello.pp(19,27) Fatal: There were 1 errors compiling module, stopping
  Fatal: Compilation aborted
  Error: /usr/local/bin/ppcx64 returned an error exitcode

The fix is to run::

  fpc -XR/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/ ./hello.pp

The logs are::

  Free Pascal Compiler version 3.2.2 [2021/05/16] for x86_64
  Copyright (c) 1993-2021 by Florian Klaempfl and others
  Target OS: Darwin for x86_64
  Compiling ./hello.pp
  Assembling hello
  Linking hello
  21 lines compiled, 0.2 sec

The following command::

  fpc -h | grep XR

prints::

  -Xd        Do not search default library path (sometimes required for cross-compiling when not using -XR)
  -XR<x>     Prepend <x> to all linker search paths (BeOS, Darwin, FreeBSD, Linux, Mac OS, Solaris)

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

