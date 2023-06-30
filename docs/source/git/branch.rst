Branch
======

After renaming ``main`` to ``master``, do the following locally:

.. code-block:: bash

  git branch -m main master
  git fetch origin
  git branch -u origin/master master
  git remote set-head origin -a
