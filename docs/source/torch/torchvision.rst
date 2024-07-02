torchvision
===========

1. How is the C++ code compiled and how is it loaded in PyTorch.

``from torchvision.io import read_file`` to read a binary file and it returns
a 1-d tensor of dtype ``torch.uint8``.

There is also a ``write_file`` to write a 1-d tensor of dtype ``torch.uint8``.

``from torchvision.io import read_image`` to read an image. Supported formats are
``jpg``, ``png``, ``gif``.

Color images are represented as a uint8 tensor of shape ``(channels, height, width)``.

``transforms.v2._utils`` contains functions for checking and parsing sizes, paddings, fill.

Use ``v2.ToDtype(torch.float32, scale=True)`` to convert dtype.

- ``RandomAffine`` calls ``F.affine``. ``RandomAffine`` is in ``transforms/v2/_geometry.py``.
  Affine has 4 parameters: angle for rotation, translate, scale, shear. RandomAffine._get_params()
  just return the 4 parameters. Note that we can call the class method ``RandomAffine.get_params()``, which
  is defined in ``transform/transform.py``

- ``F.affine()`` is defined in ``transforms/v2/functional/_geometry.py`` with name ``def affine_image``
  ``_get_inverse_affine_matrix()`` is used to get the matrix for affine transform.

  Inside ``F.affine()``, it calls ``_affine_grid`` to get a grid from the affine transform matrix
  and then use ``_apply_grid_transform`` to transform the input.

TODO: look at torch.nn.functional.affine_grid() and grid_sample(). See also
https://github.com/wuneng/WarpAffine2GridSample/blob/master/main.py#L56

`Deep Learning Paper Implementations: Spatial Transformer Networks - Part I <https://kevinzakka.github.io/2017/01/10/stn-part1/>`_
