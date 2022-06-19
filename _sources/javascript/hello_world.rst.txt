Hello world
===========

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
