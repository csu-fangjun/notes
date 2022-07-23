Internals
=========

`<https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/core/QuantizerBase.h>`_
defines the base class ``Quantizer``.

`<https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/quantized/Quantizer.h>`_
defines the subclasses of ``Quantizer``, such as

  - ``PerTensorAffineQuantizer`` - qscheme is ``kPerTensorAffine``.

QScheme
-------

See `<https://github.com/pytorch/pytorch/blob/master/c10/core/QScheme.h>`_

.. literalinclude:: ./code/qscheme/main.cc
   :language: c++
   :linenos:
   :caption: ./code/qscheme/main.cc

PerTensorAffineQuantizer
------------------------

It has 4 important methods:

  - ``QScheme qscheme() const``, always returns ``kPerTensorAffine``.
  - ``double scale() const``
  - ``int64_t zero_point() const``
  - ``ScalarType scalar_type() const``

It uses `quantize_tensor_per_tensor_affine_cpu <https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/native/quantized/cpu/kernels/QuantizedOpKernels.cpp#L3199>`_ when `FBGEMM <https://github.com/pytorch/FBGEMM>`_
is available.

Otherwise, it uses `quantize_tensor_per_tensor_affine_cpu <https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/native/quantized/cpu/kernels/QuantizedOpKernels.cpp#L3533>`_.

  - For arm, it uses `quantize_tensor_arm <https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/native/quantized/cpu/kernels/QuantizedOpKernels.cpp#L3274>`_. It is a template with many specializations.

  - For x86, it uses ``quantize_val``

    - If `FBGEMM <https://github.com/pytorch/FBGEMM>`_ is available, it uses
      `quantize_val <https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/native/quantized/AffineQuantizerBase.cpp#L39>`_
    - Otherwise, it uses `quantize_val <https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/native/quantized/AffineQuantizerBase.cpp#L100>`_

      .. code-block:: c++

        template <typename T>
        T quantize_val(double scale, int64_t zero_point, float value) {
          // std::nearbyint results in nearest integer value according to the current
          // rounding mode and the default rounding mode is rounds to even in half-way
          // cases in most popular processor architectures like x86 and ARM. This is
          // typically faster than an alternatives like std::round that rounds half-way
          // cases away from zero, and can be consistent with SIMD implementations for
          // example in x86 using _mm512_cvtps_epi32 or mm512_round_ps with
          // _MM_FROUND_CUR_DIRECTION option that also follow the current rounding mode.
          int64_t qvalue;
          constexpr int64_t qmin = std::numeric_limits<typename T::underlying>::min();
          constexpr int64_t qmax = std::numeric_limits<typename T::underlying>::max();
          float inv_scale = 1.0f / static_cast<float>(scale);
          qvalue = static_cast<int64_t>(zero_point + Round(value * inv_scale));
          qvalue = std::max<int64_t>(qvalue, qmin);
          qvalue = std::min<int64_t>(qvalue, qmax);
          return static_cast<T>(qvalue);
        }

`dequantize_val <https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/native/quantized/AffineQuantizerBase.cpp#L164>`_ is defined as:

.. code-block:: c++

  template <typename T>
  TORCH_API float dequantize_val(double scale, int64_t zero_point, T value) {
    return static_cast<float>(scale) * (value.val_ - static_cast<int32_t>(zero_point));
  }
