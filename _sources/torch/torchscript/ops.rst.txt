ops
===

aten::add
---------

.. code-block:: bash

   // add_res = a + b * alpha
   %add_res = aten::add(%a, %b, %alpha)

   // add_res = a + b * alpha
   %add_res = aten::add(%a, %b, %alpha, %out)

aten::add_
----------

.. code-block:: bash

   // add_res = a * b * alpha
   %add_res = aten::add_(%a, %b, %alpha)


aten::_add_relu
---------------

.. code-block:: bash

   // res = relu(a + b * alpha)
   %res = aten::_add_relu(%a, %b, %alpha)

   // res = relu(a + b * alpha)
   %res = aten::_add_relu(%a, %b, %alpha, %out)

aten::add_relu_
---------------

.. code-block:: bash

    // res = relu(a + b * alpha)
    %res = aten::_add_relu(%a, %b, %alpha)

aten::_add_relu_
----------------

.. code-block:: bash

    // res = relu(a + b * alpha)
    %res = aten::_add_relu_(%a, %b, %alpha)

aten::relu
----------

.. code-block:: bash

    %res = aten::relu_(%add_res)

