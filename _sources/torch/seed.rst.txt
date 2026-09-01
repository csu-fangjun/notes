seed
====

To fix the seed, use::

  import random
  import numpy as np
  import torch

  seed = 20240809
  random.seed(seed)
  np.random.seed(seed)
  torch.manual_seed(seed)
