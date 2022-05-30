inet_pton
=========

`<https://man7.org/linux/man-pages/man3/inet_pton.3.html>`_

Representation format to network address.

The resulting network address is in network order, i.e., big endian.


.. literalinclude:: ./code/inet_pton.c
   :language: cpp
   :linenos:
   :lines: 1-21
   :caption: ./code/inet_pton.c

Its implementation can be found at
`<https://github.com/bminor/glibc/blob/master/resolv/inet_pton.c>`_

.. literalinclude:: ./code/inet_pton_impl.c
   :language: cpp
   :linenos:
   :caption: ./code/inet_pton_impl.c
