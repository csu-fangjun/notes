typed array in javascript
=========================

Typed array is a view into a buffer.

When creating from an array, the array is copied to a newly created buffer.

When creating from a length, a buffer is allocated, which is initialized with 0s.

When creating from a buffer, the buffer is shared.

See
  - `<https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/TypedArray>`_
  - `<https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Typed_arrays>`_

.. literalinclude:: ./code/typed_array.js
   :language: javascript
   :linenos:
   :caption: ./code/typed_array.js

.. literalinclude:: ./code/int8_array.js
   :language: javascript
   :linenos:
   :caption: ./code/int8_array.js


.. literalinclude:: ./code/int32_array.js
   :language: javascript
   :linenos:
   :caption: ./code/int32_array.js
