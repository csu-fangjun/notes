qairt-quantizer
===============

.. code-block::

  if [ ! -f input0-en.raw ]; then
  wget https://modelscope.cn/models/csukuangfj/2025-10-14/resolve/master/2025-10-29-qnn/input0-en.raw
  wget https://modelscope.cn/models/csukuangfj/2025-10-14/resolve/master/2025-10-29-qnn/input1-en.raw
  fi

  if [ ! -f input0.raw ]; then
  wget https://modelscope.cn/models/csukuangfj/2025-10-14/resolve/master/2025-10-29-qnn/input0.raw
  wget https://modelscope.cn/models/csukuangfj/2025-10-14/resolve/master/2025-10-29-qnn/input1.raw
  fi

  echo "/content/input0-en.raw /content/input1-en.raw" > input_list.txt
  echo "/content/input0.raw /content/input1.raw" >> input_list.txt

  cat input_list.txt

  qairt-quantizer \
    --input_dlc ./model-opset-17.dlc \
    --output_dlc ./model-opset-17-quantized.dlc \
    --input_list ./input_list.txt \
    --use_native_input_files

.. literalinclude:: ./code/qairt-quantizer-help.txt
