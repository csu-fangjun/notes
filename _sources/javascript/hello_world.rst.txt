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
