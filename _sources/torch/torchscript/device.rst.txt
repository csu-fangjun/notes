torch::Device
=============

See

  - `<https://github.com/pytorch/pytorch/blob/master/c10/core/DeviceType.h>`_
  - `<https://github.com/pytorch/pytorch/blob/master/c10/core/Device.h>`_

DeviceType
----------

``torch::DeviceType`` is defined as ``enum class Device: int8_t {...}``.
The most commonly used types are ``torch::DeviceType::CPU`` and ``torch::DeviceType::CUDA``,
which are aliased to ``torch::kCPU`` and ``torch::kCUDA``.

.. literalinclude:: ./code/device/main.cc
   :language: c++
   :linenos:
   :lines: 3-10
   :caption: ./code/device/main.cc

Device
------

A ``torch::Device`` class has two members: a ``torch::DeviceType``
and an ``int8_t index``.

.. literalinclude:: ./code/device/main.cc
   :language: c++
   :linenos:
   :lines: 13-49
   :caption: ./code/device/main.cc (Constructors)
