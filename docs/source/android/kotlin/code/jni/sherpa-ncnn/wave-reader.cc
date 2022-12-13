#include "wave-reader.h"
#include "sherpa-ncnn/csrc/wave-reader.h"

JNIEXPORT jfloatArray JNICALL Java_WaveReader_00024Companion_readWave(
    JNIEnv *env, jclass /*cls*/, jstring filename,
    jfloat expected_sample_rate) {
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
