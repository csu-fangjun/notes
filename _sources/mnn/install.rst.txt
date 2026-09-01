Install
=======

Refer to
`<https://mnn-docs.readthedocs.io/en/latest/compile/engine.html>`_

.. code-block:: bash

   ./schema/generate.sh
   mkdir build
   cd build
   cmake  -DMNN_BUILD_CONVERTER=ON -DMNN_SUPPORT_DEPRECATED_OP=OFF -DMNN_BUILD_TORCH=ON ..
   make -j 10

.. note::

    Use ``CPLUS_INCLUDE_PATH`` and ``C_INCLUDE_PATH`` to add additional paths
    for searching.

Python
------

See `<https://mnn-docs.readthedocs.io/en/latest/compile/pymnn.html>`_

To build a python package, use:

.. code-block:: bash

   cd pymnn/pip_package/
   python3 ./build_deps.py
   python3 setup.py bdist_wheel --version 2.1.1
   # We can get the version from include/MNN/MNNDefine.h
   # or we can give it an arbitrary version string.
   pip install ./dist/MNN-2.1.1-cp38-cp38-linux_x86_64.whl
   cd $HOME
   python3 -c "import MNN; print(dir(MNN))"
