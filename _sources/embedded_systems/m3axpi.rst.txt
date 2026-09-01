m3axpi
======

- `<https://wiki.sipeed.com/hardware/zh/maixIII/ax-pi/basic_usage.html>`_

How to setup date
-----------------

.. code-block:: bash

  # If network is not available, then setup the http proxy
  #
  # export http_proxy=http://localhost:6009
  # export HTTP_PROXY=http://localhost:6009
  sudo date -s "$(wget --no-cache -S -O /dev/null google.com 2>&1 | \
    sed -n -e '/  *Date: */ {' -e s///p -e q -e '}')"

  # or use
  sudo date -s "$(wget --no-cache -S -O /dev/null bing.com 2>&1 | \
    sed -n -e '/  *Date: */ {' -e s///p -e q -e '}')"

Python proxy server
-------------------

.. code-block::  bash

  https://github.com/csukuangfj/python-proxy-server

