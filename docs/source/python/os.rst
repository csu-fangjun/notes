os
==

Check file extension:

.. code-block:: python3

   a = 'a.jpg'
   assert a.endswith('jpg') is True

   # Note we can also pass a tuple to endswith
   assert a.endswith(('jpg', 'jpeg')) is True

Split extension:

.. code-block:: bash

   os.path.splitext('a.txt.exe') == ('a.txt', '.exe')
