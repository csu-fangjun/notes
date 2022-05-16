Hello
=====

See `<https://pytorch.org/tutorials/beginner/Intro_to_TorchScript_tutorial.html>`_.


``torch.jit.script`` as a decorator
-----------------------------------

.. literalinclude:: ./code/1-ex.py
   :language: python
   :linenos:
   :lines: 6-37
   :emphasize-lines: 6,8,10-11,13,16
   :caption: ./code/1-ex.py

``torch.jit.script`` as a function
----------------------------------

.. literalinclude:: ./code/2-ex.py
   :language: python
   :linenos:
   :lines: 5-23
   :emphasize-lines: 6-8
   :caption: ./code/2-ex.py

torchscript a module
--------------------

.. literalinclude:: ./code/3-ex.py
   :language: python
   :linenos:
   :lines: 6-36
   :emphasize-lines: 12-13,15
   :caption: ./code/3-ex.py

.. _export and ignore methods:

Export and ignore methods
^^^^^^^^^^^^^^^^^^^^^^^^^

1. Use ``@torch.jit.export`` decorator to export a method.

2. Use ``torch.jit.export`` function call to export a method.

3. Use ``@torch.jit.ignore`` decorator to ignore a method.

4. Use ``torch.jit.ignore`` function call to ignore a method.

5. Use ``@torch.jit.unused`` or ``torch.jit.unused`` to ignore a method.

See :ref:`Load in CPP` to load the saved file.

.. literalinclude:: ./code/4-ex.py
   :language: python
   :linenos:
   :lines: 6-60
   :caption: ./code/4-ex.py

