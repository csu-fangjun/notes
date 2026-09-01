sort
====

Sort files in the folder ``t``. The filename has the patter ``xxx.n.txt``,
where ``n`` is some numerical value. Also, exclude ``xxx.100.txt``.

.. code-block::

  find ./t -name "xxx*.txt" ! -name "xxx.100.txt" -print0 | sort -z -t. -k2 -n | xargs -r0

  # -z line delimiter is NUL, not new line
  # -t filed separator
  # -k sort via a key
  # -n numeric sort

Convert 32-bit floating pcm to wave:

.. code-block:: bash

   # sample rate: 22050
   # c: channel
   sox -t raw -r 22050 -b 32 -e floating-point -c 1 ./t.pcm ./t.wav
