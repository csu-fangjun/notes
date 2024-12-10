tag
===

.. code-block:: bash

   # list remote tags
   git ls-remote --tags dan

   # remove the xxx tag
   git push --delete dan refs/tags/xxx

   git push origin :refs/tags/xxx
