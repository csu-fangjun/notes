LSTM
====


- LSTM in mlx does not support multi-layers
- batch is always at the 0 dim, i.e., batch first is always True
- also, does not support bidrectional  lstm
- there is only a single bias, if not None

`<https://github.com/ml-explore/mlx-examples/blob/main/encodec/encodec.py#L14>`_
has a meta kernel implementation for LSTM.

.. literalinclude:: ./code/test_lstm_1_layer.py
   :language: python
   :linenos:
   :caption: ./code/test_lstm_1_layer.py

.. literalinclude:: ./code/test_lstm_multi_layers.py
   :language: python
   :linenos:
   :caption: ./code/test_lstm_multi_layers
