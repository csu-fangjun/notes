Branch
======

After renaming ``main`` to ``master``, do the following locally:

.. code-block:: bash

  git branch -m main master
  git fetch origin
  git branch -u origin/master master
  git remote set-head origin -a

  git ls-remote --tags origin # view the tags of the remote origin
  git push origin --delete tag master # delete the master tag from the remote origin
