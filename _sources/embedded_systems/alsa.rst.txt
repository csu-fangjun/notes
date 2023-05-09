ALSA
====

Advanced Linux Sound Architecture (ALSA).

USB microphone for raspberry pi
-------------------------------

.. code-block:: bash

  pi@raspberrypi:~ $ arecord -l
  **** List of CAPTURE Hardware Devices ****
  card 3: UACDemoV10 [UACDemoV1.0], device 0: USB Audio [USB Audio]
    Subdevices: 1/1
    Subdevice #0: subdevice #0

alsa-utils
----------

See `<https://github.com/alsa-project/alsa-utils>`_

.. code-block:: bash

  sudo apt-get install alsa-utils

It contains source code for ``arecord``, ``areplay``, etc.

aplay
^^^^^

List playback devices:

.. code-block:: bash

  aplay -l

  **** List of PLAYBACK Hardware Devices ****
  card 1: vc4hdmi0 [vc4-hdmi-0], device 0: MAI PCM i2s-hifi-0 [MAI PCM i2s-hifi-0]
    Subdevices: 1/1
    Subdevice #0: subdevice #0
  card 2: vc4hdmi1 [vc4-hdmi-1], device 0: MAI PCM i2s-hifi-0 [MAI PCM i2s-hifi-0]
    Subdevices: 1/1
    Subdevice #0: subdevice #0

To play ``foo.wav`` on card 1, device 0, use:

.. code-block:: bash

  aplay -D hw:1,0 foo.wav

arecord
^^^^^^^

.. code-block:: bash

  cat /proc/asound/pcm
  00-00: bcm2835 Headphones : bcm2835 Headphones : playback 8
  01-00: MAI PCM i2s-hifi-0 : MAI PCM i2s-hifi-0 : playback 1
  02-00: MAI PCM i2s-hifi-0 : MAI PCM i2s-hifi-0 : playback 1
  03-00: USB Audio : USB Audio : capture 1

.. code-block:: bash

  arecord -l
  **** List of CAPTURE Hardware Devices ****
  card 3: UACDemoV10 [UACDemoV1.0], device 0: USB Audio [USB Audio]
    Subdevices: 1/1
    Subdevice #0: subdevice #0

.. code-block:: bash

  cat  /proc/asound/card3/stream0

  Jieli Technology UACDemoV1.0 at usb-0000:01:00.0-1.4, full speed : USB Audio

  Capture:
    Status: Stop
    Interface 1
      Altset 1
      Format: S16_LE
      Channels: 1
      Endpoint: 0x83 (3 IN) (ASYNC)
      Rates: 48000
      Bits: 16
      Channel map: MONO



Cross compiling alsa-lib
------------------------

See `<https://github.com/alsa-project/alsa-lib/blob/master/INSTALL>`_

.. code-block:: bash

  git clone --depth 1 https://github.com/alsa-project/alsa-lib
  cd alsa-lib
  CC=aarch64-linux-gnu-gcc ./gitcompile --host=aarch64-linux-gnu

``/bin/bash: plantuml: command not found``: ``sudo apt-get install plantuml``

.. code-block:: bash

  alsa-lib$ find . -name "*.so"

  ./src/.libs/libasound.so
  ./src/topology/.libs/libatopology.so

.. code-block:: bash

  alsa-lib$ find . -name asoundlib.h
  ./include/asoundlib.h

Then copy the ``include`` directory to raspberry pi and rename include
to ``alsa``. Also, copy ``libasound.so`` to raspberry pi.

We can pass ``-I/path/to/alsa/parent`` and ``-lasound`` to  ``g++``
on raspberry pi.

Introduction to Sound Programming with ALSA
-------------------------------------------

.. code-block:: bash

  sudo apt-get install libasound2-dev libasound2


See
 - `<https://www.linuxjournal.com/article/6735>`_.
 - `<https://www.alsa-project.org/alsa-doc/alsa-lib/index.html>`_
 - `<https://vovkos.github.io/doxyrest/samples/alsa/index.html>`_, which
   has more detailed doc for APIs.
 - `A Tutorial on Using the ALSA Audio API <http://equalarea.com/paul/alsa-audio.html>`_
 - `PCM (digital audio) interface <https://vovkos.github.io/doxyrest/samples/alsa/page_pcm.html>`_



- `snd_pcm_open <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1ga8340c7dc0ac37f37afe5e7c21d6c528b>`_
- `snd_strerror <https://vovkos.github.io/doxyrest/samples/alsa/group_Error.html#doxid-group-error-1ga182bbadf2349e11602bc531e8cf22f7e>`_
- `snd_device_name_hint <https://vovkos.github.io/doxyrest/samples/alsa/group_Control.html?highlight=snd_device_name_hint#doxid-group-control-1gadf4ce9117fcfa454c523ed6e6bd8b353>`_
- `snd_pcm_hw_params_malloc <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM_HW_Params.html#doxid-group-p-c-m-h-w-params-1ga6e53d09a9c7cc3f2a692c0af99886237>`_
- `snd_pcm_hw_params_free <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM_HW_Params.html#doxid-group-p-c-m-h-w-params-1ga6e53d09a9c7cc3f2a692c0af99886237>`_
- `snd_pcm_hw_params_any <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM_HW_Params.html#doxid-group-p-c-m-h-w-params-1ga6e2dd8efbb7a4084bd05e6cc458d84f7>`_
- `snd_pcm_hw_params_set_access <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM_HW_Params.html#doxid-group-p-c-m-h-w-params-1ga4c8f1c632931923531ca68ee048a8de8>`_
- `snd_pcm_hw_params_set_format <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM_HW_Params.html#doxid-group-p-c-m-h-w-params-1ga6014e0e1ec7934f8c745290e83e59199>`_
- `snd_pcm_hw_params_set_rate_near <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM_HW_Params.html#doxid-group-p-c-m-h-w-params-1ga6014e0e1ec7934f8c745290e83e59199>`_
- `snd_pcm_hw_params_set_channels <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM_HW_Params.html#doxid-group-p-c-m-h-w-params-1ga3a5b2a05c5d9869cc743dac71c0d270a>`_
- `snd_pcm_hw_params <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1ga1ca0dc120a484965e26cabf966502330>`_
- `snd_async_add_pcm_handler <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1ga5a0c0da6d0d35a3ac9f6a97567ac3b63>`_, which calls ``snd_pcm_prepare`` automatically.
- `snd_pcm_prepare <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1ga788d05de75f2d536f8443cb0306754d0>`_
- `snd_pcm_start <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1ga6bdb88b68a9d9e66015d770f600c6aea>`_
- `snd_pcm_drop <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1ga7000ca6010a1a2739daddff8e2fbb440>`_
- `snd_pcm_drain <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1ga49afc5b8527f30c33fafa476533c9f86>`_
- `snd_pcm_readi <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1ga4c2c7bd26cf221268d59dc3bbeb9c048>`_
- `snd_pcm_readn <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM.html#doxid-group-p-c-m-1gafea175455f1a405f633a43484ded3d8a>`_
- `snd_pcm_format_t <https://vovkos.github.io/doxyrest/samples/alsa/enum_snd_pcm_format_t.html#doxid-group-p-c-m-1gaa14b7f26877a812acbb39811364177f8>`_
- `snd_pcm_hw_params_alloca <https://vovkos.github.io/doxyrest/samples/alsa/group_PCM_HW_Params.html#doxid-group-p-c-m-h-w-params-1ga06b83cb9a788f99b7b09b570b4355cee>`_
