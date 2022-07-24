spaces
======

Install client API
------------------

.. code-block:: bash

   pip install huggingface_hub

.. code-block:: python3

  (py38) kuangfangjun:t$ python3
  Python 3.8.0 (default, Oct 28 2019, 16:14:01)
  [GCC 8.3.0] on linux
  Type "help", "copyright", "credits" or "license" for more information.
  >>> from huggingface_hub import hf_hub_download
  >>> hf_hub_download(repo_id="google/pegasus-xsum", filename="config.json")
  Downloading: 100%|______________________________________________________________________________________________| 1.39k/1.39k [00:00<00:00, 1.12MB/s]
  '/root/fangjun/.cache/huggingface/hub/models--google--pegasus-xsum/snapshots/a0aa5531c00f59a32a167b75130805098b046f9c/config.json'
  >>>


gradio
------

- `<https://huggingface.co/spaces/alphacep/asr>`_
- `<https://huggingface.co/spaces/jonatasgrosman/asr>`_
- `<https://github.com/gradio-app/gradio/issues/1359>`_
- `<https://huggingface.co/spaces/Gradio-Blocks/neon-tts-plugin-coqui/blob/main/app.py>`_, css styles
