passes
======

_jit_pass_fuse_add_relu
-----------------------

See `<https://github.com/pytorch/pytorch/blob/master/torch/csrc/jit/passes/fuse_relu.cpp>`_

.. literalinclude:: ./code/passes/fuse_add_relu.py
   :language: python
   :linenos:
   :caption: ./code/passes/fuse_add_relu.py

.. literalinclude:: ./code/passes/fuse_add_relu-before.txt
   :linenos:
   :caption: ./code/passes/fuse_add_relu-before.txt

.. literalinclude:: ./code/passes/fuse_add_relu-after.txt
   :linenos:
   :caption: ./code/passes/fuse_add_relu-after.txt

in_place relu_
^^^^^^^^^^^^^^

.. literalinclude:: ./code/passes/fuse_add_relu_.py
   :language: python
   :linenos:
   :caption: ./code/passes/fuse_add_relu_.py

.. literalinclude:: ./code/passes/fuse_add_relu_-before.txt
   :linenos:
   :caption: ./code/passes/fuse_add_relu_-before.txt

.. literalinclude:: ./code/passes/fuse_add_relu_-after.txt
   :linenos:
   :caption: ./code/passes/fuse_add_relu_-after.txt


_jit_pass_fuse_linear
---------------------

See `<https://github.com/pytorch/pytorch/blob/master/torch/csrc/jit/passes/fuse_linear.cpp>`_

.. literalinclude:: ./code/passes/fuse_linear.py
   :language: python
   :linenos:
   :caption: ./code/passes/fuse_linear.py

.. literalinclude:: ./code/passes/fuse_linear-before.txt
   :linenos:
   :caption: ./code/passes/fuse_linear-before.txt

.. literalinclude:: ./code/passes/fuse_linear-after.txt
   :linenos:
   :caption: ./code/passes/fuse_linear-after.txt
