Android
=======


libcdsprpc.so
-------------

.. code-block:: bash

  <uses-native-library
              android:name="libcdsprpc.so"
              android:required="false"/>

``libcdsprpc.so`` is located in ``/vendor/lib64`` on my Xiaomi 17 Pro.

`<https://github.com/google-ai-edge/LiteRT/blob/01113f67fba44fb9547496500c804b400a90a571/litert/kotlin/src/main/AndroidManifest.xml#L47>`_
also uses this for QualComm NPU. It also has two lines for MTK NPU.

`<https://github.com/zhuqingquan/notes/blob/103d806170130164d1f918761d5c7f6f54ddb85b/%E6%B7%B1%E5%BA%A6%E5%AD%A6%E4%B9%A0-%E7%A5%9E%E7%BB%8F%E7%BD%91%E7%BB%9C-%E4%BA%BA%E5%B7%A5%E6%99%BA%E8%83%BD-AI/%E5%9F%BA%E7%A1%80%E7%9F%A5%E8%AF%86%E7%82%B9%E5%A4%87%E5%BF%98.md#%E9%83%A8%E7%BD%B2%E5%88%B0android%E6%89%8B%E6%9C%BA%E4%B8%AD%E8%BF%90%E8%A1%8C>`_ has some explanations about ``libcdsprpc.so``.



`<https://github.com/dengzii/rwkv_dart/>`_ has a dart example about it. See also
`<https://github.com/MollySophia/rwkv-mobile>`_

rwkv-mobile also has examples for coreml using c++!
