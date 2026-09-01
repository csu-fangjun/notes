Hello
=====

Create a simple torchscript model:

.. literalinclude:: ./code/hello/ex1.py
   :language: python
   :linenos:
   :caption: ./code/hello/ex1.py

.. code-block:: bash

  MNNConvert -f TORCH --modelFile ./ex1.pt --MNNModel ex1.mnn --bizCode MNN

It prints:

.. code-block:: bash

  Start to Convert Other Model Format To MNN Model...
  Start to Optimize the MNN Net...
  inputTensors : [ x.1, ]
  outputTensors: [ 2, ]
  Converted Success!

We can use:

.. code-block:: bash

   netron ex1.mnn --port 6006

to view it::

  Serving 'ex1.mnn' at http://localhost:6006

To convert the model to ``json``, use:

.. code-block:: bash

   MNNDump2Json ./ex1.mnn ./ex1.json

which generates:

.. literalinclude:: ./code/hello/ex1.json
   :language: json
   :linenos:
   :caption: ./code/hello/ex1.json

To convert ``ex1.json`` back to a ``.mnn`` file, use:

.. code-block:: bash

  MNNRevert2Buffer ex1.json ex11.mnn

To show the information of the model:

.. code-block:: bash

   MNNConvert --framework MNN --modelFile ./ex1.mnn --info

It prints:

.. code-block:: bash

  Model default dimensionFormat is NCHW
  Model Inputs:
  [ x.1 ]: dimensionFormat: NCHW, size: [ ], type is float
  Model Outputs:
  [ 2 ]
  Model Version: 2.1.1

To run it with ``MNN`` in Python:

.. literalinclude:: ./code/hello/test-ex1-mnn.py
   :language: python
   :linenos:
   :caption: ./code/hello/test-ex1-mnn.py

It prints:

.. code-block::

  input_tensor.getShape() (3,)
  input_tensor.getNumpyData() [ 1.  -2.5  3.2]
  output_tensor.getNumpyData() [1.  0.  3.2]
  output_data.getNumpyData() [1.  0.  3.2]

