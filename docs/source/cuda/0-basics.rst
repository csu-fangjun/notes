0-Basics
========

.. code-block::

   KernelA<<<nBlk, nTid>>(args);

A grid of blocks

  - ``gridDim``, number of blocks in each dim
  - ``blockIdx``, the index of the block in the grid
  - ``blockDim``, number of threads in a block

A block of threads

  - ``threadIdx``, the index of the thread in the block

.. code-block::

   // 1-d
   int global_thread_id = blockDim.x * blockIdx.x + threadIdx.x;

   // 2-d
   int global_x = blockDim.x * blockIdx.x + threadIdx.x;
   int global_y = blockDim.y * blockIdx.y + threadIdx.y;

   // 3-d
   int global_x = blockDim.x * blockIdx.x + threadIdx.x;
   int global_y = blockDim.y * blockIdx.y + threadIdx.y;
   int global_z = blockDim.z * blockIdx.z + threadIdx.z;

.. note::

   There is no ``gridIdx``.

- ``__host__``: default, calls from CPU, runs on CPU
- ``__device__``: calls from GPU, runs on GPU
- ``__global__``: calls from CPU, runs on GPU

.. code-block::

   dim3 dimGrid(32, 1, 1);
   dim3 dimBlock(128, 1, 1);
   vecAddKernel<<<dimGrid, dimBlock>>>(xxxx);
