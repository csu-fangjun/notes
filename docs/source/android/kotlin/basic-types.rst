Basic types
============

Note ``String.length`` and ``Array.size``.

Differences between ``Array<Float>`` and ``FloatArray``:

 - ``Array<Float>`` saves objects
 - ``FloatArray`` is a primitive array
 - ``Array<Float`` to ``FloatArray``: ``.toFloatArray()``
 - ``FloatArray`` to ``Array<Float>``: ``.toTypedArray()``


.. code-block:: bash

	 kotlinc -include-runtime -d hello.jar hello.kt

.. literalinclude:: ./code/basic-types/hello.kt
   :language: kotlin
   :caption: ./code/basic-types/hello.kt

CharSequence
------------

See `<https://github.com/JetBrains/kotlin/blob/0938b46726b9c6938df309098316ce741815bb55/core/builtins/native/kotlin/CharSequence.kt#L22>`_

It is an interface.
