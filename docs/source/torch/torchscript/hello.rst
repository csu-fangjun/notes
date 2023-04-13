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

``torch.Value`` has the following attributes (output of ``dir()``):

.. code-block:: bash

  ['__class__', '__delattr__', '__dir__', '__doc__', '__eq__', '__format__',
  '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__',
  '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__',
  '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__',
  '__str__', '__subclasshook__', 'copyMetadata', 'debugName', 'inferTypeFrom',
  'isCompleteTensor', 'node', 'offset', 'replaceAllUsesAfterNodeWith',
  'replaceAllUsesWith', 'requiresGrad', 'requires_grad', 'setDebugName',
  'setType', 'setTypeAs', 'toIValue', 'type', 'unique', 'uses']

.. literalinclude:: ./code/1-ex.py
   :language: python
   :linenos:
   :lines: 40-74
   :emphasize-lines: 6,8,10-11,13,16
   :caption: ./code/1-ex.py

``torch.Node`` has the following attributes (output from ``dir()``):

.. code-block:: bash

    ['__class__', '__delattr__', '__dir__', '__doc__', '__eq__', '__format__',
    '__ge__', '__getattribute__', '__getitem__', '__gt__', '__hash__', '__init__',
    '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__',
    '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__',
    '__str__', '__subclasshook__', 'addBlock', 'addInput', 'addOutput',
    'attributeNames', 'blocks', 'c', 'c_', 'cconv', 'copyAttributes', 'copyMetadata',
    'destroy', 'eraseOutput', 'f', 'f_', 'findAllNodes', 'findNode', 'fs',
    'fs_', 'g', 'g_', 'getModuleHierarchy', 'gs', 'gs_', 'hasAttribute',
    'hasAttributes', 'hasMultipleOutputs', 'hasUses', 'i', 'i_', 'input',
    'inputs', 'inputsAt', 'inputsSize', 'insertAfter', 'insertBefore', 'is',
    'isAfter', 'isBefore', 'isNondeterministic', 'is_', 'ival', 'ival_', 'kind',
    'kindOf', 'matches', 'moveAfter', 'moveBefore', 'mustBeNone', 'namedInput',
    'output', 'outputs', 'outputsAt', 'outputsSize', 'owningBlock', 'prev',
    'pyname', 'pyobj', 'removeAllInputs', 'removeAttribute', 'removeInput',
    'replaceAllUsesWith', 'replaceInput', 'replaceInputWith', 's', 's_', 'scalar_args',
    'schema', 'scopeName', 'sourceRange', 'ss', 'ss_', 't', 't_', 'ts', 'ts_',
    'ty_', 'tys_', 'z', 'z_', 'zs', 'zs_']

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

trace a module
--------------

.. literalinclude:: ./code/trace/ex0.py
   :language: python
   :linenos:
   :caption: ./code/trace/ex0.py



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



