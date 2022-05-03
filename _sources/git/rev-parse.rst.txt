rev-parse
---------

It is quite common to get the root directory of the repository with the command:

.. code-block::

    git rev-parse --show-toplevel

For instance, the above command executed in this repository prints something like
as follows::

    /xxx/notes

The following shows its usage in a Python script:

.. literalinclude:: ./code/rev-parse.py
   :language: python

It can also be used in bash script:

.. code-block:: bash

  root_dir=$(git rev-parse --show-toplevel)
  echo "root_dir ${root_dir}"

  


``help git-rev-parse`` outputs helpful information for ``git rev-parse``. In
particular, it explains the differences among ``HEAD~``, ``HEAD~n``, ``HEAD^``,
and ``HEAD^n``. The following shows the help information about it:

.. literalinclude:: ./code/rev-parse-help.txt
