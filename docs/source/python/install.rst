Install from Source
===================

Go to `<https://www.python.org/ftp/python/>` to downalod python, e.g.,

.. code-block:: bash

  wget https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tar.xz
  wget https://www.python.org/ftp/python/3.9.0/Python-3.9.0.tar.xz
  wget https://www.python.org/ftp/python/3.10.0/Python-3.10.0.tar.xz

  mkdir -p $HOME/software/python
  tar xvf Python-3.8.0.tar.xz
  cd Python-3.8.0
  ./configure --help
  ./configure --prefix=$HOME/software/python/3.8.0 --enable-shared --enable-optimizations
