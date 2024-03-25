.. _node_js:

node
====

Go to `<https://nodejs.org/en/download/>`_ to download pre-built binaries:

.. code-block::

   wget https://nodejs.org/dist/v16.15.1/node-v16.15.1-linux-x64.tar.xz
   tar xvf node-v16.15.1-linux-x64.tar.xz

and then add ``/path/to/node-v16.15.1-linux-x64/bin/`` to ``PATH``.

.. code-block:: bash

   node -v

to show the version, e.g., ``v18.16.0``.

It also contains the executable ``npm``. In python we have ``requirements.txt``
and we can use ``pip install -r ./requirements.txt``. Similarly, there is
``package.json`` in javascript and we can use ``npm install`` in the folder
containing ``package.json``.

To create a new project, run ``npm init -y``, it will generate ``package.json``.

To install a package, use ``npm install package-name``. To remove a package,
use ``npm remove package-name``.

An alternative for ``npm`` is ``yarn``: ``npm install -g yarn``.

We can run ``yarm`` inside the directory containing ``package.json``.

If a project contains a file ``yarn.lock``, then it is using the tool ``yarn``.


glibc 2.32 on ubuntu 18.04
--------------------------

.. code-block:: bash

  # see also https://github.com/nodesource/distributions/issues/1392
  sudo apt install -y gawk

  wget https://github.com/bminor/glibc/archive/refs/tags/glibc-2.32.tar.gz
  tar xvf glibc-2.32.tar.gz
  mkdir glibc-build
  cd glibc-build
  cd glibc-glibc-2.32/
  unset LD_LIBRARY_PATH
  unset CFLAGS
  unset CPPFLAGS
  unset CXXFLAGS
  ../configure --prefix=/star-fj/fangjun/software/glibc-2.32
  make install
  apt install -y patchelf
  patchelf --set-interpreter /star-fj/fangjun/software/glibc-2.32/lib/ld-linux-x86-64.so.2 --set-rpath /star-fj/fangjun/software/glibc-2.32/lib:/usr/lib/x86_64-linux-gnu:/lib/x86_64-linux-gnu ./node
