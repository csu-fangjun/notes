Install
=======

.. code-block:: bash

   pip install aqtinstall
   aqt list-qt mac desktop --arch 6.2.0

   # It prints:
    clang_64 wasm_32

.. code-block:: bash

  aqt list-qt mac desktop --modules 6.2.0 clang_64

  # It prints:
  debug_info qt3d qt5compat qtcharts qtconnectivity qtdatavis3d qtimageformats qtlottie qtmultimedia qtnetworkauth qtpositioning qtquick3d qtquicktimeline qtremoteobjects qtscxml qtsensors qtserialbus qtserialport qtshadertools qtvirtualkeyboard qtwebchannel qtwebengine qtwebsockets qtwebview

.. code-block:: bash

    aqt install-qt mac desktop 6.2.0 clang_64 -m all
    aqt install-qt mac desktop 6.2.0 -m multimedia

It creates ``./6.2.0`` and installs everything inside.

.. code-block:: bash

    aqt install-qt mac desktop 6.2.0 --archives qtbase
