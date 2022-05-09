Hello world
===========

comment
-------

.. code-block:: css

   /* this is a comment */

.. code-block:: css

   p { color: red; }

Then, in some html file, use:

.. code-block:: html

   <link href="abc/foo.css" rel="stylesheet">

Selector
--------

- tag name or element name: e.g., ``p`` selects ``<p>``; ``h1`` selects ``<h1>``.
- ID:, e.g., ``#my-id`` selects ``<a id="my-id">`` or ``<p id="my-id">``
- class: e.g., ``.my-class`` selects ``<a class="my-class">`` and ``<p class="my-class">``
- attribute: e.g., ``img[src]`` selects ``<img src="a.png">`` but not ``<img>``

See `<https://developer.mozilla.org/en-US/docs/Learn/Getting_started_with_the_web/CSS_basics#different_types_of_selectors>`_
and `<https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/Selectors>`_ for more.



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
