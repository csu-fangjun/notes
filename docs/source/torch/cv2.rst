cv2
===

Convert a tensor to an image.

.. code-block:: bash

   pip install opencv-python

.. code-block:: python3

   import cv2
   cv2.imwrite('test.png', bool_tensor.to(torch.int)*255)
