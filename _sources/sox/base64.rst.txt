base64
======

.. code-block:: python3

  import base64
  encode_string = base64.b64encode(open("audio.wav", "rb").read())
  wav_file = open("temp.wav", "wb")
  decode_string = base64.b64decode(encode_string)
  wav_file.write(decode_string)
