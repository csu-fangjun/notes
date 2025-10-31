qairt-converter
====================

.. code-block::

  echo "Maintained by k2-fsa" > copyright.txt

  qairt-converter \
    --set_model_version "2025-10-31" \
    --copyright_file ./copyright.txt \
    --input_network ./model-opset-17.onnx \
    --source_model_input_shape 'x' 1,93,560 \
    --source_model_input_shape 'prompt' 1,4 \
    --source_model_input_datatype 'x' float32 \
    --source_model_input_datatype 'prompt' int32

.. literalinclude:: ./code/qairt-convert-help.txt
