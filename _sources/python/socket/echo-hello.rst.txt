Echo Server and Client
======================

Server
------

.. literalinclude:: ./code/echo-hello/server.py
   :language: python
   :linenos:
   :caption: ./code/echo-hello/server.py

To test the server, use ``nc localhost 6006`` or use the following client.

Client
------

.. literalinclude:: ./code/echo-hello/client.py
   :language: python
   :linenos:
   :lines: 7-14
   :caption: ./code/echo-hello/client.py

Server2
-------

With ``concurrent.futures.ThreadPoolExecutor``.

.. literalinclude:: ./code/echo-hello/server2.py
   :language: python
   :linenos:
   :caption: ./code/echo-hello/server2.py
