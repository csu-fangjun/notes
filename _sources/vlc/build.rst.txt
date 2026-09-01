build
------

.. code-block:: bash

   sudo apt-get install flex gettext bison autopoint libtool
   git clone https://github.com/videolan/vlc
   cd vlc
   ./bootstrap
   ./configure --prefix=$PWD/my-install
   make install
