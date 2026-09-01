inet_ntop
=========

Network address to representation format.

See `<https://man7.org/linux/man-pages/man3/inet_ntop.3.html>`_

.. literalinclude:: ./code/inet_ntop.c
   :language: cpp
   :linenos:
   :lines: 1-21
   :caption: ./code/inet_ntop.c

Its implementation can be found at
`<https://github.com/bminor/glibc/blob/master/resolv/inet_ntop.c>`_

.. literalinclude:: ./code/inet_ntop_impl.c
   :language: cpp
   :linenos:
   :caption: ./code/inet_ntop_impl.c
