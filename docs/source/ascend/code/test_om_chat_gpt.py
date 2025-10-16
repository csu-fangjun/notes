#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import acl
import numpy as np
import librosa
import kaldi_native_fbank as knf

# -----------------------------
# 特征提取
# -----------------------------
def compute_feat(filename):
    sample_rate = 16000
    samples, _ = librosa.load(filename, sr=sample_rate)
    opts = knf.FbankOptions()
    opts.frame_opts.dither = 0
    opts.frame_opts.snip_edges = False
    opts.frame_opts.samp_freq = sample_rate
    opts.mel_opts.num_bins = 80

    online_fbank = knf.OnlineFbank(opts)
    online_fbank.accept_waveform(sample_rate, (samples * 32768).tolist())
    online_fbank.input_finished()

    features = np.stack([online_fbank.get_frame(i) for i in range(online_fbank.num_frames_ready)])
    assert features.data.contiguous is True
    assert features.dtype == np.float32

    window_size = 7
    window_shift = 6
    T = (features.shape[0] - window_size) // window_shift + 1
    features = np.lib.stride_tricks.as_strided(
        features,
        shape=(T, features.shape[1] * window_size),
        strides=((window_shift * features.shape[1]) * 4, 4),
    )
    return np.copy(features)

# -----------------------------
# Acoustic embedding
# -----------------------------
def get_acoustic_embedding(alpha: np.array, hidden: np.array):
    alpha = alpha.tolist()
    acc = 0
    embeddings = []
    cur_embedding = np.zeros((hidden.shape[1],), dtype=np.float32)

    for i, w in enumerate(alpha):
        acc += w
        if acc >= 1:
            overflow = acc - 1
            remain = w - overflow
            cur_embedding += remain * hidden[i]
            embeddings.append(cur_embedding)
            cur_embedding = overflow * hidden[i]
            acc = overflow
        else:
            cur_embedding += w * hidden[i]

    if len(embeddings) == 0:
        raise ValueError("No speech in the audio file")
    return np.array(embeddings)

# -----------------------------
# Tokens
# -----------------------------
def load_tokens():
    ans = dict()
    i = 0
    with open("tokens.txt", encoding="utf-8") as f:
        for line in f:
            ans[i] = line.strip().split()[0]
            i += 1
    return ans

# -----------------------------
# ACL 模型加载
# -----------------------------
ACL_MEM_MALLOC_NORMAL_ONLY = 0
ACL_MEMCPY_HOST_TO_DEVICE = 0
ACL_MEMCPY_DEVICE_TO_HOST = 1

def load_om_model(path):
    model_id, ret = acl.mdl.load_from_file(path)
    if ret != 0:
        raise RuntimeError(f"Load model failed: {path}, ret={ret}")
    model_desc = acl.mdl.create_desc()
    acl.mdl.get_desc(model_desc, model_id)
    return model_id, model_desc

# -----------------------------
# 单输入模型推理
# -----------------------------
def run_model_single_input(model_id, model_desc, input_array):
    input_size = input_array.nbytes
    input_buf, _ = acl.rt.malloc(input_size, ACL_MEM_MALLOC_NORMAL_ONLY)
    acl.rt.memcpy(input_buf, input_size, input_array.ctypes.data, input_size, ACL_MEMCPY_HOST_TO_DEVICE)

    input_dataset = acl.mdl.create_dataset()
    input_db = acl.create_data_buffer(input_buf, input_size)
    acl.mdl.add_dataset_buffer(input_dataset, input_db)

    output_size = acl.mdl.get_output_size_by_index(model_desc, 0)
    output_buf, _ = acl.rt.malloc(output_size, ACL_MEM_MALLOC_NORMAL_ONLY)
    output_dataset = acl.mdl.create_dataset()
    output_db = acl.create_data_buffer(output_buf, output_size)
    acl.mdl.add_dataset_buffer(output_dataset, output_db)

    ret = acl.mdl.execute(model_id, input_dataset, output_dataset)
    if ret != 0:
        raise RuntimeError(f"Execute failed, ret={ret}")

    output_host, _ = acl.rt.malloc_host(output_size)
    acl.rt.memcpy(output_host, output_size, output_buf, output_size, ACL_MEMCPY_DEVICE_TO_HOST)
    output_data = np.frombuffer(acl.util.ptr_to_bytes(output_host, output_size), dtype=np.float32)

    acl.rt.free(input_buf)
    acl.rt.free(output_buf)
    acl.rt.free_host(output_host)
    acl.mdl.destroy_dataset(input_dataset)
    acl.mdl.destroy_dataset(output_dataset)

    return output_data

# -----------------------------
# 多输入 decoder 推理
# -----------------------------
def run_model_decoder(model_id, model_desc, encoder_out, acoustic_embedding, mask):
    # 准备输入 Dataset
    input_dataset = acl.mdl.create_dataset()

    # encoder_out
    buf1, _ = acl.rt.malloc(encoder_out.nbytes, ACL_MEM_MALLOC_NORMAL_ONLY)
    acl.rt.memcpy(buf1, encoder_out.nbytes, encoder_out.ctypes.data, encoder_out.nbytes, ACL_MEMCPY_HOST_TO_DEVICE)
    db1 = acl.create_data_buffer(buf1, encoder_out.nbytes)
    acl.mdl.add_dataset_buffer(input_dataset, db1)

    # acoustic_embedding
    buf2, _ = acl.rt.malloc(acoustic_embedding.nbytes, ACL_MEM_MALLOC_NORMAL_ONLY)
    acl.rt.memcpy(buf2, acoustic_embedding.nbytes, acoustic_embedding.ctypes.data, acoustic_embedding.nbytes, ACL_MEMCPY_HOST_TO_DEVICE)
    db2 = acl.create_data_buffer(buf2, acoustic_embedding.nbytes)
    acl.mdl.add_dataset_buffer(input_dataset, db2)

    # mask
    buf3, _ = acl.rt.malloc(mask.nbytes, ACL_MEM_MALLOC_NORMAL_ONLY)
    acl.rt.memcpy(buf3, mask.nbytes, mask.ctypes.data, mask.nbytes, ACL_MEMCPY_HOST_TO_DEVICE)
    db3 = acl.create_data_buffer(buf3, mask.nbytes)
    acl.mdl.add_dataset_buffer(input_dataset, db3)

    # 输出
    output_size = acl.mdl.get_output_size_by_index(model_desc, 0)
    output_buf, _ = acl.rt.malloc(output_size, ACL_MEM_MALLOC_NORMAL_ONLY)
    output_dataset = acl.mdl.create_dataset()
    output_db = acl.create_data_buffer(output_buf, output_size)
    acl.mdl.add_dataset_buffer(output_dataset, output_db)

    # 执行
    ret = acl.mdl.execute(model_id, input_dataset, output_dataset)
    if ret != 0:
        raise RuntimeError(f"Decoder execute failed, ret={ret}")

    # 拷贝回 host
    output_host, _ = acl.rt.malloc_host(output_size)
    acl.rt.memcpy(output_host, output_size, output_buf, output_size, ACL_MEMCPY_DEVICE_TO_HOST)
    output_data = np.frombuffer(acl.util.ptr_to_bytes(output_host, output_size), dtype=np.float32)

    # 释放
    acl.rt.free(buf1)
    acl.rt.free(buf2)
    acl.rt.free(buf3)
    acl.rt.free(output_buf)
    acl.rt.free_host(output_host)
    acl.mdl.destroy_dataset(input_dataset)
    acl.mdl.destroy_dataset(output_dataset)

    return output_data

# -----------------------------
# 主函数
# -----------------------------
def main():
    acl.init()
    device_id = 0
    acl.rt.set_device(device_id)
    context, _ = acl.rt.create_context(device_id)

    # 特征
    features = compute_feat("./1.wav")
    if features.shape[0] >= 83:
        features = features[:83]
    else:
        padding = features[-(83 - features.shape[0]):]
        features = np.concatenate([features, padding])
    features = features[None, ...]  # batch=1

    # 加载 OM 模型
    enc_id, enc_desc = load_om_model("encoder.om")
    pred_id, pred_desc = load_om_model("predictor.om")
    dec_id, dec_desc = load_om_model("decoder.om")

    # encoder
    encoder_out = run_model_single_input(enc_id, enc_desc, features)
    encoder_out = encoder_out.reshape(-1, 512)
    print("encoder_out", encoder_out.shape, encoder_out.sum(), encoder_out.mean())

    # predictor
    alpha = run_model_single_input(pred_id, pred_desc, encoder_out)
    print("alpha", alpha.shape, alpha.sum(), alpha.mean())

    # acoustic embedding
    acoustic_embedding = get_acoustic_embedding(alpha, encoder_out)
    print('acoustic_embedding', acoustic_embedding.shape)
    num_tokens = acoustic_embedding.shape[0]
    print('num_tokens', num_tokens)
    padding = np.zeros((83 - num_tokens, 512), dtype=np.float32)
    acoustic_embedding = np.concatenate([acoustic_embedding, padding], axis=0)
    mask = np.zeros((83,), dtype=np.float32)
    mask[:num_tokens] = 1
    print('mask', mask.sum(), mask.shape)

    decoder_input = acoustic_embedding[None, ...]

    # decoder
    decoder_out = run_model_decoder(dec_id, dec_desc, encoder_out, decoder_input, mask)
    decoder_out = decoder_out.reshape(83, -1)

    print("decoder_out", decoder_out.shape, decoder_out.sum(), decoder_out.mean())

    # 输出文字
    yseq = decoder_out[:num_tokens].argmax(axis=-1).tolist()
    print('yseq', yseq)
    tokens = load_tokens()
    words = [tokens[i] for i in yseq if i not in (1,2)]
    text = "".join(words)
    print("Recognized text:", text)

    # 卸载模型 & 清理
    for mid, mdesc in [(enc_id, enc_desc), (pred_id, pred_desc), (dec_id, dec_desc)]:
        acl.mdl.unload(mid)
        acl.mdl.destroy_desc(mdesc)

    acl.rt.destroy_context(context)
    acl.rt.reset_device(device_id)
    acl.finalize()

if __name__ == "__main__":
    main()
