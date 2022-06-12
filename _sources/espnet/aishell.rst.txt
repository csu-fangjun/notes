aishell
=======

AM training
-----------

The first one was added on 2019-02-01.

``asr_train.py`` is in ``espnet/bin/asr_train.py``, which invokes
``espnet.asr.pytorch_backend.asr.train``.

The model is from ``espnet.asr.pytorch_backend..e2e_asr.E2E``.

Command is:

.. code-block:: bash

   asr_train.py \
     --config conf/train.yaml \
     --preprocess-conf \
     --ngpu 1 \
     --backend pytorch \
     --outdir exp/xxx \
     --debugmode 1 \
     --dict data/lang_char/train_sp_units.txt
     --minibatches 0 \
     --verbose 0 \
     --resume \
     --train-json  xxx/data.json \
     --valid-json  yyy/data.json



