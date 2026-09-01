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

To install a local package, use ``npm install package-name``. To remove a local package,
use ``npm remove package-name`` or ``npm uninstall package-name``.

To install a global package, use ``npm install -g package-name``. To remove a global package,
use ``npm remove -g package-name`` or ``npm uninstall -g package-name``.


An alternative for ``npm`` is ``yarn``: ``npm install -g yarn``.

We can run ``yarm`` inside the directory containing ``package.json``.

If a project contains a file ``yarn.lock``, then it is using the tool ``yarn``.


.. code-block:: bash

   which node
   which npm

.. code-block::

    /Users/fangjun/software/node-v21.1.0-darwin-x64/bin/node
    /Users/fangjun/software/node-v21.1.0-darwin-x64/bin/npm

Globally installed ``npm`` packages are placed in ``prefix/lib/node_modules``
and executable files are placed in ``prefix/bin``. Use ``-g`` or ``--global``
in ``npm install``.

Locally installed ``npm`` packages are placed in ``pwd/node_modules``
and executable files are placed in ``pwd/node_modules/.bin``.

.. code-block:: bash

   npm install -g eslint
   wchi eslint

prints::

  /Users/fangjun/software/node-v21.1.0-darwin-x64/bin/eslint


To install a specific version, use::

  npm install ejs@2.7.4


``npm i == npm install``.

``npm install --global == npm install -g``.

versions:

  - ``1.2.33``, an exact version
  - ``>1.2.33``
  - ``>=1.2.33`
  - ``<1.2.33`
  - ``<=1.2.33`
  - ``^1.2.33`, the latest compatible major version, i.e., ``<2.0.0``.
  - ``~1.2.33``, the latest version ``<1.3.0``. ``~`` means latest minor number.
  - ``*``, any version


To list locally installed packages::

  npm list

To list globally installed packages::

  npm list --global
  npm list -g


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

process
-------
