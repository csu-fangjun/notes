Matcha-TTS
==========

The model has 3 inputs:

  - x: ``(batch_size, max_num_tokens)``
  - x_lengths: ``(batch_size,)``
  - spks: ``None``, or of shape ``(batch_size,)``

If spks is not ``None``, then it uses a embedding layer to convert it to a tensor
of shape ``(batch_size, spk_embedding_dim)``.

x, x_lengths, spks, are sent to the TextEncoder.

Inside the TextEncoder, x is sent to another embedding layer, the output is a tensor
of shape ``(batch_size, max_num_tokens, embedding_dim)``, then it is transposed to
(batch_size, embedding_dim, max_num_tokens)

It builds a mask from x_lengths. The mask is of shape ``(batch_size, max_num_tokens)``.
Valid positions in the mask is True. Padded positions in the mask is False.

The mask is then reshaped to ``(batch_size, 1, max_num_tokens)``.

Then x is sent to a ``prenet``.

Prenet contains 3 blocks. Each block consists of: Conv1D, LayerNorm, ReLU, Dropout.
The last layer of a prenet is Conv1D, which is equivalent to a Linear layer.
The advantage of use a Conv1D to replace Linear is that it does not need to transpose
x. Also note that the LayerNorm in Prenet is user-implemented, which can save two transpose operations.

Prenet also contains a residual connection, which means the input channels and output
channels have to be the same.

Note: Inside Prenet, only the input of the Conv1D is multiplied with the mask.
Also, the output of Prenet is also multiplied with the mask.

After the Prenet, it concatenates x and spk embeddings, so the resulting x is of shape
``(batch_size, embedding_dim + spk_embedding_dim, max_num_tokens)``.

At this point, we only need to process x and mask, where

  - x: ``(batch_size, embedding_dim + spk_embedding_dim, max_num_tokens)``
  - mask: ``(batch_size, 1, max_num_tokens)``

The next part is ``Encoder`` inside the  ``TextEncoder``.

``attn_mask`` is of shape ``(1, 1, max_num_tokens, max_num_tokens)`` and is generated
from ``mask``.

The Encoder in the TextEncoder is a Transformer encoder.

After processing with the Encoder, it uses a Conv1D to convert the dim to ``n_feats``.

The duration predictor outputs a tensor of shape ``(batch_size, 1, max_num_tokens)``.

Note that the duration predictor predicts log durations of each token.
In the end, it uses ``exp`` to get the duration for each token.

It then uses ``ceil`` to get integral durations. It can optionally use ``length_scale``
to scale the duration of each token.

It uses ``sum`` to compute the total duration of each utterance.

``fix_len_compatibility()``: Convert to the next multiple of 4 if it is not a multiple of 4

``generate_path``: It actually returns a mask of shape ``(batch, max_num_tokens, max_y)``.

The decoder model
-----------------

Its input:

  - x: ``(batch_size, num_feats, max_y)``
  - mask: ``(batch_size, 1, max_y)``
  - t: a scalar tensor

First, an embedding is computed from ``t`` using ``SinusoidPosEmb``. Note that
it is not a standard Sinusoid positional encoding. The shape of the embedding is
``(batch_size, in_channels)``.

The embedding is processed by ``TimestepEmbedding``, which contains a linear layer,
an activation layer, and a linear layer. The output shape is ``(batch_size, time_embed_dim)``.
