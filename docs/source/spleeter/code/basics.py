#!/usr/bin/env python3

#  from spleeter.utils.configuration import load_configuration
#
#  print(load_configuration("spleeter:2stems"))
#  # Available sources can be found at
#  # https://github.com/deezer/spleeter/tree/master/spleeter/resources
#  # For spleeter:2stems, it means to use 2stems.json
#  params = load_configuration("spleeter:2stems")
#  print(params["sample_rate"])

import tensorflow as tf
import numpy as np
from tensorflow.signal import hann_window, stft
import torch

tf.compat.v1.enable_eager_execution(True)


def generate_waveform():
    np.random.seed(20230821)
    waveform = np.random.rand(60 * 44100).astype(np.float32)

    # (num_samples, num_channels)
    waveform = waveform.reshape(-1, 2)
    return waveform


def test_stft_torch():
    x = generate_waveform()
    x = torch.from_numpy(x)
    y = torch.stft(
        x.t(),
        n_fft=4096,
        hop_length=1024,
        window=torch.hann_window(4096, periodic=True),
        center=False,
        onesided=True,
        return_complex=True,
    )
    # (2, 2049, 1288)

    y = y.permute(0, 2, 1)
    # now y is (2, 1288, 2049)

    y = y.permute(1, 2, 0)
    # now y is (1288, 2049, 2) == (T, dim, num_channels)

    tensor_size = y.shape[0] - int(y.shape[0] / 512) * 512
    pad_size = 512 - tensor_size
    y = torch.nn.functional.pad(y, (0, 0, 0, 0, 0, pad_size))
    # Now y is (1536, 2049, 2)
    num_splits = int(y.shape[0] / 512)
    y = y.reshape([num_splits, 512] + list(y.shape[1:]))
    # Now y is (3, 512, 2049, 2)

    y = y[:, :, :1024, :]
    # Now y is (3, 512, 1024, 2)
    y = y.abs()
    # Now y is (3, 512, 1024, 2)
    print(y[1, 100, :10, 0])


def test_stft_tf():
    x = generate_waveform()
    x = tf.convert_to_tensor(x)

    # x (1323000, 2)

    # Since fft_length is None, it is set to 4096, the next power of 2 that
    # encloses frame_length
    y = stft(
        tf.transpose(x),
        frame_length=4096,
        frame_step=1024,
        fft_length=None,
        #  window_fn=None,
        window_fn=lambda frame_length, dtype: hann_window(
            frame_length, periodic=True, dtype=tf.float32
        ),
        pad_end=True,
    )
    # Since we use pad_end=True, it uses ceil(1323000 / 1024) = 1292
    # y: complex64, (2, 1292, 2049)
    # 2049 = 4096/2 + 1 = fft_unique_bins

    y = tf.transpose(y, perm=(1, 2, 0))
    # now y is (1292, 2049, 2) == (T, dim, num_channels)

    # pad and partition
    # Note that the implementation comment in spleeter is not correct
    tensor_size = tf.math.floormod(y.shape[0], 512)
    # 268 = 1292 - floor(1292 / 512) * 512
    pad_size = 512 - tensor_size

    padded = tf.pad(y, [[0, pad_size]] + [[0, 0]] * (len(y.shape) - 1))
    # padded: (1536, 2049, 2 )
    split = int(padded.shape[0] / 512)
    stft_feat = tf.reshape(padded, [split, 512] + padded.shape[1:])
    # stft_feat now is (3, 512, 2049, 2)

    spectrogram = tf.abs(stft_feat)[:, :, :1024, :]
    # Now spectrogram is (3, 512, 1024, 2) = (num_splits, T, F, num_channels)
    print("stft", tf.math.reduce_sum(spectrogram))


# https://blog.metaflow.fr/tensorflow-how-to-freeze-a-model-and-serve-it-with-a-python-api-d4f3596b3adc
def load_graph(frozen_graph_filename):
    # We load the protobuf file from the disk and parse it to retrieve the
    # unserialized graph_def
    with tf.compat.v1.gfile.GFile(frozen_graph_filename, "rb") as f:
        graph_def = tf.compat.v1.GraphDef()
        graph_def.ParseFromString(f.read())

    # Then, we import the graph_def into a new Graph and returns it
    with tf.Graph().as_default() as graph:
        # The name var will prefix every op/nodes in your graph
        # Since we load everything in a new graph, this is not needed
        #  tf.import_graph_def(graph_def, name="prefix")
        tf.import_graph_def(graph_def, name="")
    return graph


def test():
    from spleeter.utils.tensor import pad_and_partition

    #  a = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    a = np.array([[1, 2, 3], [4, 5, 6]])
    x = tf.convert_to_tensor(a)
    y = pad_and_partition(x, 2)


def test2():
    graph = load_graph("./frozen_model.pb")
    #  for op in graph.get_operations():
    #      print(op.name)
    x = graph.get_tensor_by_name("waveform:0")
    #  y = graph.get_tensor_by_name("Reshape:0")
    y = graph.get_tensor_by_name("strided_slice_3:0")
    print(x)
    print(y)
    with tf.compat.v1.Session(graph=graph) as sess:
        y_out = sess.run(y, feed_dict={x: generate_waveform()})
        print(y_out.shape)
        print(y_out.sum())


if __name__ == "__main__":
    #  generate_waveform()
    test_stft_tf()
    #  test_stft_torch()
    test2()
