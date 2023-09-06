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

