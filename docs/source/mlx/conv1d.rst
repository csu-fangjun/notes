conv1d
=======

There is no nn.functional.conv1d in mlx, use ``mx.core.conv1d``.

The weight matrix in pytorch is ``(out_channels, in_channels, kernel_size)``,
The weight matrix in mlx is ``(out_channels, kernel_size, in_channels)``,

The input in pytorch is ``(N, C, L)``.

The input in mlx is ``(N, L, C)``

