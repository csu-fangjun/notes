Functions
=========

See `<https://kotlinlang.org/docs/functions.html>`_

typealias:

  .. code-block::

    // https://kotlinlang.org/docs/type-aliases.html
    typealias ClickHandler = (Button, ClickEvent) -> Unit

.. code-block:: bash

	 kotlinc -include-runtime -d hello.jar hello.kt

.. literalinclude:: ./code/functions/hello.kt
   :language: kotlin
   :caption: ./code/functions/hello.kt
