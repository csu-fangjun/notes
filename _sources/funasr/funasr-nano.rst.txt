FunASR-Nano
============

`<https://modelscope.cn/models/FunAudioLLM/Fun-ASR-Nano-2512/file/view/master/config.yam>`_

Audio encoder is ``SenseVoiceEncoderSmall``.

LLM is ``Qwen3-0.6B``, from ``transformers.AutoModelForCausalLM``. See `<https://huggingface.co/Qwen/Qwen3-0.6B>`_

Audio adaptor is ``Transformer`` from funasr/models/transformer

.. code-block::

  [
    [
      {'role': 'system', 'content': 'You are a helpful assistant.'},
      {'role': 'user', 'content': '语音转写：<|startofspeech|>!/root/.cache/huggingface/hub/models--FunAudioLLM--Fun-ASR-Nano-2512/snapshots/6d5631d3240449810e6dbcf92c9af0ca063e12cb/example/zh.mp3<|endofspeech|>'},
      {'role': 'assistant', 'content': 'null'}
    ]
  ]

