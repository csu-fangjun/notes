audograd
========

See

  - `<https://pytorch.org/docs/stable/notes/autograd.html>`_
  - `<https://dev-discuss.pytorch.org/t/how-to-read-the-autograd-codebase/383>`_
  - `<https://pytorch.org/docs/stable/notes/extending.html>`_


FAQ:
  - pack and unpack hooks for saved tensors. See `<https://pytorch.org/docs/stable/notes/autograd.html#hooks-for-saved-tensors>`_

_saved_self, _saved_other, _saved_result, _saved_exponent
---------------------------------------------------------

1. ``x*2``, multiply with a scalar

.. code-block:: python3

  x = torch.tensor([1.2, 3], requires_grad=True)
  y = x*2
  print(y.grad_fn.__class__)  # '<MulBackward0>'
  print(y.grad_fn._saved_self) # None
  print(y.grad_fn._saved_other) # tensor(2)

2. ``x * a``, multiply with a tensor that requires grad

.. code-block:: python3

  x = torch.tensor([1.2, 3], requires_grad=True)
  a = torch.tensor([10.2], requires_grad=True)
  y = x*a
  print(y.grad_fn.__class__)  # '<MulBackward0>'
  print(y.grad_fn._saved_self) # tensor([1.2, 3], requires_grad=True)
  print(y.grad_fn._saved_other) # tensor([10.2], requires_grad=True)

  print(y.grad_fn._saved_self is x) # True
  print(y.grad_fn._saved_other is a) # True

3. ``x * a``, multiply with a tensor that does not require grad

.. code-block:: python3

  x = torch.tensor([1.2, 3], requires_grad=True)
  a = torch.tensor([10.2])
  y = x*a
  print(y.grad_fn.__class__)  # '<MulBackward0>'
  print(y.grad_fn._saved_self) # None
  print(y.grad_fn._saved_other) # tensor([10.2])

  print(y.grad_fn._saved_other is a) # True

4. ``sin(x)``

.. code-block:: python3

  x = torch.tensor([1.2, 3], requires_grad=True)
  y = x.sin()
  print(y.grad_fn.__class__)  # '<SinBackward0>'
  print(y.grad_fn._saved_self is x) # True

5. ``x.relu``

.. code-block:: python3

  x = torch.tensor([1.2, 3], requires_grad=True)
  y = x.relu()
  print(y.grad_fn.__class__)  # '<ReluBackward0>'
  print(y.grad_fn._saved_result.equal(y)) # True
  print(y.grad_fn._saved_result is y) # False

6. ``x.log()``

.. code-block:: python3

  x = torch.tensor([1.2, 3], requires_grad=True)
  y = x.log()
  print(y.grad_fn.__class__)  # '<LogBackward0>'
  print(y.grad_fn._saved_self is x) # True


Example 1
----------

.. code-block::
  import torch

  x = torch.tensor([1.2, 3], requires_grad=True)
  y = x * 3
  print(y.grad_fn.__class__)  # '<MulBackwad0>'
  print(dir(y.grad_fn))  #
  print(y.grad_fn._saved_other)  #  tensor(3)
  print(y.grad_fn._saved_self)  # None

  print(y.grad_fn._raw_saved_other)  # <torch._C.autograd.SavedTensor object at xxx>
  print(y.grad_fn._raw_saved_self)  #  <torch._C.autograd.SavedTensor object at xxx>
  print(y.grad_fn.next_functions)  # ((<AccumulateGrad object at 0x1032c8a00>, 0), (None, 0))
  print(y.grad_fn.next_functions[0][0])
  print(dir(y.grad_fn.next_functions[0][0]))
  print(y.grad_fn.next_functions[0][0].name()) # torch::autograd::AccumulateGrad
  print(y.grad_fn.next_functions[0][0].variable) # tensor([1.2, 3], requires_grad=True)
  print(y.grad_fn.next_functions[0][0].variable is x)  # True !
  print(y.grad_fn.next_functions[0][0].metadata) # {}
  print(y.grad_fn.next_functions[0][0].next_functions) # ()

Where is Mulbackward0 defined
-----------------------------

- tools/autograd/derivatives.yaml

  See `<https://github.com/pytorch/pytorch/blob/main/tools/autograd/derivatives.yaml#L1197>`_

  After building PyTorch, it generates several files

    - torch/csrc/autograd/generated/Functions.h
    - torch/csrc/autograd/generated/Functions.cpp
