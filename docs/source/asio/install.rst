Install
========

.. code-block:: bash

   git clone https://github.com/chriskohlhoff/asio/
   cd asio/asio
   ./autogen.sh
   ./configure --prefix=/ceph-fj/fangjun/software/asio
   make -j 10
   make install

It will create ``include`` and ``lib/pkgconfig/asio.pc`` inside
``/ceph-fj/fangjun/software/asio``. Note that it is a header only library.
