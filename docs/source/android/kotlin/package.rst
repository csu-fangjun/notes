Package
=======


.. code-block::
   // a.kt
   package geometry.shape

   class Rectangle
   fun createUnitRectangle() = Rectangle()

   // b.kt
   import geometry.shape.Rectangle
   import geometry.shape.createUnitRectangle

   // c.kt
   import geometry.shape.*
