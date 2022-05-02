sort
====

Sort files in the folder ``t``. The filename has the patter ``xxx.n.txt``,
where ``n`` is some numerical value. Also, exclude ``xxx.100.txt``.

.. code-block::

  find ./t -name "xxx*.txt" ! -name "xxx.100.txt" -print0 | sort -z -t. -k2 -n | xargs -r0
