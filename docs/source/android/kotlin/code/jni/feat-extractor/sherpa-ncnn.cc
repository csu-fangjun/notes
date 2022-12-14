#include "sherpa-ncnn.h"
#include "sherpa-ncnn/csrc/model.h"
#include "sherpa-ncnn/csrc/wave-reader.h"
#include <iostream>

JNIEXPORT jfloatArray JNICALL Java_WaveReader_00024Companion_readWave(
    JNIEnv *env, jclass cls, jstring filename, jfloat expected_sample_rate) {

  const char *p_filename = env->GetStringUTFChars(filename, nullptr);

  bool is_ok = false;
  std::vector<float> samples =
      sherpa_ncnn::ReadWave(p_filename, expected_sample_rate, &is_ok);
  env->ReleaseStringUTFChars(filename, p_filename);

  if (!is_ok) {
    return nullptr;
  }

  jfloatArray ans = env->NewFloatArray(samples.size());
  env->SetFloatArrayRegion(ans, 0, samples.size(), samples.data());
  return ans;
}

JNIEXPORT jlong JNICALL Java_Model_new(JNIEnv *env, jobject /*obj*/,
                                       jobject config) {
  sherpa_ncnn::ModelConfig model_config;

  jclass cls = env->GetObjectClass(config);

  jfieldID fid = env->GetFieldID(cls, "encoderParam", "Ljava/lang/String;");
  jstring s = (jstring)env->GetObjectField(config, fid);
  const char *p = env->GetStringUTFChars(s, nullptr);
  model_config.encoder_param = p;
  env->ReleaseStringUTFChars(s, p);

  fid = env->GetFieldID(cls, "encoderBin", "Ljava/lang/String;");
  s = (jstring)env->GetObjectField(config, fid);
  p = env->GetStringUTFChars(s, nullptr);
  model_config.encoder_bin = p;
  env->ReleaseStringUTFChars(s, p);

  fid = env->GetFieldID(cls, "decoderParam", "Ljava/lang/String;");
  s = (jstring)env->GetObjectField(config, fid);
  p = env->GetStringUTFChars(s, nullptr);
  model_config.decoder_param = p;
  env->ReleaseStringUTFChars(s, p);

  fid = env->GetFieldID(cls, "decoderBin", "Ljava/lang/String;");
  s = (jstring)env->GetObjectField(config, fid);
  p = env->GetStringUTFChars(s, nullptr);
  model_config.decoder_bin = p;
  env->ReleaseStringUTFChars(s, p);

  fid = env->GetFieldID(cls, "joinerParam", "Ljava/lang/String;");
  s = (jstring)env->GetObjectField(config, fid);
  p = env->GetStringUTFChars(s, nullptr);
  model_config.joiner_param = p;
  env->ReleaseStringUTFChars(s, p);

  fid = env->GetFieldID(cls, "joinerBin", "Ljava/lang/String;");
  s = (jstring)env->GetObjectField(config, fid);
  p = env->GetStringUTFChars(s, nullptr);
  model_config.joiner_bin = p;
  env->ReleaseStringUTFChars(s, p);

  fid = env->GetFieldID(cls, "numThreads", "I");
  model_config.num_threads = env->GetIntField(config, fid);
  std::cout << model_config.ToString() << "\n";

  auto model = sherpa_ncnn::Model::Create(model_config);

  return (jlong)(model.release());
}

JNIEXPORT void JNICALL Java_Model_delete(JNIEnv *env, jobject /*obj*/,
                                         jlong ptr) {
  delete reinterpret_cast<sherpa_ncnn::Model *>(ptr);
}

JNIEXPORT jint JNICALL Java_Model_segment(JNIEnv *env, jobject /*obj*/,
                                          jlong ptr) {
  return reinterpret_cast<const sherpa_ncnn::Model *>(ptr)->Segment();
}

JNIEXPORT jint JNICALL Java_Model_offset(JNIEnv *env, jobject /*obj*/,
                                         jlong ptr) {
  return reinterpret_cast<const sherpa_ncnn::Model *>(ptr)->Offset();
}
