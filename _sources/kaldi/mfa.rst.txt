mfa
===

.. code-block::

  mfa model download acoustic english_mfa
  mfa model download dictionary english_us_mfa


We can also use::

  wget https://github.com/MontrealCorpusTools/mfa-models/releases/download/acoustic-english_mfa-v3.1.0/english_mfa.zip
  wget https://github.com/MontrealCorpusTools/mfa-models/releases/download/dictionary-english_us_mfa-v3.1.0/english_us_mfa.dict

See also `<https://mfa-models.readthedocs.io/en/latest/acoustic/English/English%20MFA%20acoustic%20model%20v3_1_0.html>`_
`<https://mfa-models.readthedocs.io/en/latest/dictionary/English/English%20%28US%29%20MFA%20dictionary%20v3_1_0.html>`_

.. code-block:: bash

  mfa align_one -t ./temp -j 1 --verbose ./wav2/LJ001-0001.wav ./wav2/LJ001-0001.txt english_us_mfa ./t/english_mfa ./ljs_aligned.txt

- ``command_line/align_one.py``: ``def align_one_cli()``
- ``online/alignment.py``: ``def align_utterance_online()``.
- ``kalpy/fstext/lexicon.py``
