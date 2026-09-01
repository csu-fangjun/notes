Basics
======

- gguf naming convention: `<https://github.com/ggml-org/ggml/blob/master/docs/gguf.md>`_
- safetensors doc: `<https://hf-mirror.com/docs/safetensors/index>`_
- `save_gguf <https://ml-explore.github.io/mlx/build/html/python/_autosummary/mlx.core.save_gguf.html#mlx.core.save_gguf>`_
- `save_safetensors <https://ml-explore.github.io/mlx/build/html/python/_autosummary/mlx.core.save_safetensors.html#mlx.core.save_safetensors>`_
- `savez <https://ml-explore.github.io/mlx/build/html/python/_autosummary/mlx.core.savez.html#mlx.core.savez>`_

mean
----

- torch: keepdim
- mlx: keepdims

- torch: dim
- mlx: axis

cat
---

torch uses cat, while mlx uses concatenate.

torch uses dim in cat, mlx uses axis in concatenate

Sequential
----------

torch users this_layer[0], while mx uses this_layer.layers[0]
