pyenv
=====

.. code-block:: bash

  #!/usr/bin/env bash

  export PYENV_ROOT=/star-fj/fangjun/open-source/pyenv
  export PATH=$PYENV_ROOT/bin:$PATH
  export PATH=$PYENV_ROOT/shims:$PATH

  if command -v pyenv >/dev/null; then
    eval "$(pyenv init -)";
  fi

  export PYTHON_CONFIGURE_OPTS="--enable-shared"


.. code-block:: bash

  python3 -m venv ./py38

We can edit ``/mnt/data-ssd/user/omni/fj/open-source/pyenv/plugins/python-build/share/python-build/3.10.16``
to specify a local file by using ``file:///path/to/Python-3.10.6.tar.xz``
