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
