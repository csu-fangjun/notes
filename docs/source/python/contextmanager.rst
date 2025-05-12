contextmanager
==============

.. literalinclude:: ./code/context_manager/main.py
   :language: python
   :linenos:
   :caption: ./code/context_manager/main.py

See also `<https://docs.python.org/3/library/contextlib.html#contextlib.contextmanager>`_

To manipulate a lock:

.. code-block:: python3

   @contextmanager
   def locked(lock):
     lock.acquire()
     try:
       yield
     finally:
       lock.release()

   with locked(lock):
     pass

Or use a class:

.. code-block:: python3

    class locked:
      def __init__(self, lock):
        self.lock = lock

      def __enter__(self):
        self.lock.acquire()

      def __exit__(self, type, value, traceback):
        self.lock.release()
