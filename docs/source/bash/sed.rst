sed
====


.. code-block::

   find . -name *.yaml -type f -exec sed -i.bak 's/1\.10\.17/1\.10\.18/g' {} \;
