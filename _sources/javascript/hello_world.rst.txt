Hello world
===========

- case sensitive
- numbers (all numbers are 64-bit floating type)
- strings (``''`` and ``""``), there is no character type
- Like python, strings are immutable
- strings uses utf-16, like c#
- array
- boolean, ``true`` and ``false``
- ``null`` and ``undefined``
- string interpolation

    .. code-block::

      `hello ${someVariable}`

- semicolon is optional. Better to always add it
- garbage collector
- ``==`` supports type conversion
- ``===`` does not support type conversion. (Recommended to use this one)

.. code-block:: javascript

  console.log('hello world')
  console.log(eval('3 + 5'))

To write multi-line javascript, use shift + Enter for a new line.

.. code-block:: javascript

  (function(){
    "use strict";
    /* Start of your code */
    function greetMe(yourName) {
      alert('Hello ' + yourName);
    }

    greetMe('World');
    /* End of your code */
  })();

It is case sensitive. Statements are separated by ``;``. Comments are the same as in C/C++.

variables
---------

.. literalinclude:: ./code/hello_world/variables.js
   :language: javascript
   :linenos:
   :caption: ./code/hello_world/variables.js

array
-----

.. literalinclude:: ./code/hello_world/array.js
   :language: javascript
   :linenos:
   :caption: ./code/hello_world/array.js

Note that there are two ways to iterate an array:

  - ``for(let x of array)``
  - ``for(let i = 0; i != array.length; ++i) { ... }``

To run the above code, use:

.. code-block:: bash

   node array.js

class
-----

.. literalinclude:: ./code/hello_world/class.js
   :language: javascript
   :linenos:
   :caption: ./code/hello_world/class.js

It defines a ``Point`` class with two fields ``x``, ``y``. ``Point`` has
two methods: a constructor and a method ``distance()``.

Note that class names are by convention capitalized.

template strings
----------------

.. literalinclude:: ./code/hello_world/template_strings.js
   :language: javascript
   :linenos:
   :caption: ./code/hello_world/template_strings.js

Note that it is similar to the ``F-string``, ``f" "``, ``f' '``,
``f""" """``, ``f''' '''``` in Python.

functions
---------

.. literalinclude:: ./code/hello_world/functions.js
   :language: javascript
   :linenos:
   :caption: ./code/hello_world/functions.js

Note that it does not have keyword arguments.
