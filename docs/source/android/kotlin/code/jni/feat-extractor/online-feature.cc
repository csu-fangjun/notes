#include "online-feature.h"
#include "kaldi-native-fbank/csrc/online-feature.h"

JNIEXPORT jlong JNICALL Java_OnlineFbank_new(JNIEnv *env, jobject /*obj*/,
                                             jobject opts) {
  jclass cls = env->GetObjectClass(opts);
  jfieldID fid;

  // https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/types.html
  // https://courses.cs.washington.edu/courses/cse341/99wi/java/tutorial/native1.1/implementing/field.html

  knf::FbankOptions fbank_opts;

  fid = env->GetFieldID(cls, "use_energy", "Z");
  fbank_opts.use_energy = env->GetBooleanField(opts, fid);

  fid = env->GetFieldID(cls, "energy_floor", "F");
  fbank_opts.energy_floor = env->GetFloatField(opts, fid);

  fid = env->GetFieldID(cls, "raw_energy", "Z");
  fbank_opts.raw_energy = env->GetBooleanField(opts, fid);

  fid = env->GetFieldID(cls, "htk_compat", "Z");
  fbank_opts.htk_compat = env->GetBooleanField(opts, fid);

  fid = env->GetFieldID(cls, "use_log_fbank", "Z");
  fbank_opts.use_log_fbank = env->GetBooleanField(opts, fid);

  fid = env->GetFieldID(cls, "use_power", "Z");
  fbank_opts.use_power = env->GetBooleanField(opts, fid);

  fid = env->GetFieldID(cls, "frame_opts", "LFrameExtractionOptions;");

  jobject frame_opts = env->GetObjectField(opts, fid);
  jclass frame_opts_cls = env->GetObjectClass(frame_opts);

  fid = env->GetFieldID(frame_opts_cls, "samp_freq", "F");
  fbank_opts.frame_opts.samp_freq = env->GetFloatField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "frame_shift_ms", "F");
  fbank_opts.frame_opts.frame_shift_ms = env->GetFloatField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "frame_length_ms", "F");
  fbank_opts.frame_opts.frame_length_ms = env->GetFloatField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "dither", "F");
  fbank_opts.frame_opts.dither = env->GetFloatField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "preemph_coeff", "F");
  fbank_opts.frame_opts.preemph_coeff = env->GetFloatField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "remove_dc_offset", "Z");
  fbank_opts.frame_opts.remove_dc_offset =
      env->GetBooleanField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "window_type", "Ljava/lang/String;");
  jstring window_type = (jstring)env->GetObjectField(frame_opts, fid);
  const char *p_window_type = env->GetStringUTFChars(window_type, nullptr);
  fbank_opts.frame_opts.window_type = p_window_type;
  env->ReleaseStringUTFChars(window_type, p_window_type);

  fid = env->GetFieldID(frame_opts_cls, "round_to_power_of_two", "Z");
  fbank_opts.frame_opts.round_to_power_of_two =
      env->GetBooleanField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "blackman_coeff", "F");
  fbank_opts.frame_opts.blackman_coeff = env->GetFloatField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "snip_edges", "Z");
  fbank_opts.frame_opts.snip_edges = env->GetBooleanField(frame_opts, fid);

  fid = env->GetFieldID(frame_opts_cls, "max_feature_vectors", "I");
  fbank_opts.frame_opts.max_feature_vectors = env->GetIntField(frame_opts, fid);

  fid = env->GetFieldID(cls, "mel_opts", "LMelBanksOptions;");
  jobject mel_opts = env->GetObjectField(opts, fid);
  jclass mel_opts_cls = env->GetObjectClass(mel_opts);

  fid = env->GetFieldID(mel_opts_cls, "num_bins", "I");
  fbank_opts.mel_opts.num_bins = env->GetIntField(mel_opts, fid);

  fid = env->GetFieldID(mel_opts_cls, "low_freq", "F");
  fbank_opts.mel_opts.low_freq = env->GetFloatField(mel_opts, fid);

  fid = env->GetFieldID(mel_opts_cls, "high_freq", "F");
  fbank_opts.mel_opts.high_freq = env->GetFloatField(mel_opts, fid);

  fid = env->GetFieldID(mel_opts_cls, "vtln_low", "F");
  fbank_opts.mel_opts.vtln_low = env->GetFloatField(mel_opts, fid);

  fid = env->GetFieldID(mel_opts_cls, "vtln_high", "F");
  fbank_opts.mel_opts.vtln_high = env->GetFloatField(mel_opts, fid);

  fid = env->GetFieldID(mel_opts_cls, "debug_mel", "Z");
  fbank_opts.mel_opts.debug_mel = env->GetBooleanField(mel_opts, fid);

  fid = env->GetFieldID(mel_opts_cls, "htk_mode", "Z");
  fbank_opts.mel_opts.htk_mode = env->GetBooleanField(mel_opts, fid);

  auto online_fbank = new knf::OnlineFbank(fbank_opts);

  return (jlong)online_fbank;
}

JNIEXPORT void JNICALL Java_OnlineFbank_delete(JNIEnv *env, jobject obj,
                                               jlong ptr) {
  delete reinterpret_cast<knf::OnlineFbank *>(ptr);
}

JNIEXPORT jint JNICALL Java_OnlineFbank_dim(JNIEnv *env, jobject obj,
                                            jlong ptr) {
  return reinterpret_cast<const knf::OnlineFbank *>(ptr)->Dim();
}

JNIEXPORT jfloat JNICALL Java_OnlineFbank_frameShiftInSeconds(JNIEnv *env,
                                                              jobject obj,
                                                              jlong ptr) {
  return reinterpret_cast<const knf::OnlineFbank *>(ptr)->FrameShiftInSeconds();
}

JNIEXPORT jint JNICALL Java_OnlineFbank_numFramesReady(JNIEnv *env, jobject obj,
                                                       jlong ptr) {
  return reinterpret_cast<const knf::OnlineFbank *>(ptr)->NumFramesReady();
}

JNIEXPORT jboolean JNICALL Java_OnlineFbank_isLastFrame(JNIEnv *env,
                                                        jobject obj, jlong ptr,
                                                        jint i) {
  return reinterpret_cast<const knf::OnlineFbank *>(ptr)->IsLastFrame(i);
}

JNIEXPORT void JNICALL Java_OnlineFbank_inputFinished(JNIEnv *env, jobject obj,
                                                      jlong ptr) {
  reinterpret_cast<knf::OnlineFbank *>(ptr)->InputFinished();
}

JNIEXPORT void JNICALL Java_OnlineFbank_acceptWaveform(JNIEnv *env, jobject obj,
                                                       jlong ptr,
                                                       jfloatArray samples,
                                                       jfloat sample_rate) {
  jfloat *p = env->GetFloatArrayElements(samples, nullptr);
  jsize n = env->GetArrayLength(samples);

  reinterpret_cast<knf::OnlineFbank *>(ptr)->AcceptWaveform(sample_rate, p, n);

  env->ReleaseFloatArrayElements(samples, p, JNI_ABORT);
}

JNIEXPORT jfloatArray JNICALL Java_OnlineFbank_getFrame(JNIEnv *env,
                                                        jobject obj, jlong ptr,
                                                        jint i) {
  auto online_fbank = reinterpret_cast<const knf::OnlineFbank *>(ptr);
  auto frame = online_fbank->GetFrame(i);
  auto dim = online_fbank->Dim();

  jfloatArray ans = env->NewFloatArray(dim);
  env->SetFloatArrayRegion(ans, 0, dim, frame);

  return ans;
}

JNIEXPORT jfloatArray JNICALL Java_OnlineFbank_getFrames(JNIEnv *env,
                                                         jobject /*obj*/,
                                                         jlong ptr, jint start,
                                                         jint n) {
  auto online_fbank = reinterpret_cast<const knf::OnlineFbank *>(ptr);
  auto dim = online_fbank->Dim();

  if (start + n > online_fbank->NumFramesReady()) {
    return nullptr;
  }

  jfloatArray ans = env->NewFloatArray(n * dim);
  for (int32_t i = 0; i != n; ++i) {
    auto frame = online_fbank->GetFrame(start + i);
    env->SetFloatArrayRegion(ans, i * dim, dim, frame);
  }

  return ans;
}
