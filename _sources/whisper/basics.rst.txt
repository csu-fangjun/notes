Basics
======

https://github.com/microsoft/onnxruntime/issues/15235#issuecomment-1487609280

https://medium.com/microsoftazure/build-and-deploy-fast-and-portable-speech-recognition-applications-with-onnx-runtime-and-whisper-5bf0969dd56b

transforms
----------

.. code-block::

   from transformers import AutoProcessor, pipeline
   model_path = "optimum/whisper-tiny.en"
   processor = WhisperProcessor.from_pretrained(model_path)


`<https://huggingface.co/optimum/whisper-tiny.en/blob/main/preprocessor_config.json>`_
defines the preprocessor.


optimum
-------
