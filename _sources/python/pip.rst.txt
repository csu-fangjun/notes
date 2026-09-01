pip
===

install pip using::

  python3 -m ensurepip --default-pip

To update pip and setuptools and wheel::

  python3 -m pip install --upgrade pip setuptools wheel



After creating a virtual environment with:

.. code-block:: bash

   python3 -m venv my_env
   source ./my_env/bin/active

We can use:

.. code-block:: bash

   curl https://bootstrap.pypa.io/get-pip.py
   python3 ./get-pip.py

to install pip

Refer to `<https://packaging.python.org/en/latest/tutorials/installing-packages/#optionally-create-a-virtual-environment>`_
