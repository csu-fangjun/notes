Hello world
===========

.. code-block:: css

   p { color: red; }

Then, in some html file, use:

.. code-block:: html

   <link href="abc/foo.css" rel="stylesheet">

Selector
--------

- tag name or element name: e.g., ``p``
- ID:, e.g., `#my-id`
- class: e.g., ``.my-class``



Example with multiple rules:

.. code-block:: css
   :capiton: Example with multiple rules

   p {
     color: red;
     width: 500px;
     border: 1px solid black;
   }

Example with multiple selectors:

.. code-block:: css
   :capiton: Example with multiple selectors

   p, li, h1 { color: red; }
