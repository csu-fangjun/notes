#include "sherpa-ncnn.h"

#include "sherpa-ncnn/csrc/decode.h"
#include "sherpa-ncnn/csrc/features.h"
#include "sherpa-ncnn/csrc/model.h"
#include "sherpa-ncnn/csrc/symbol-table.h"
#include "sherpa-ncnn/csrc/wave-reader.h"

namespace sherpa_ncnn {
class SherpaNcnn {
 public:
  SherpaNcnn(const ModelConfig &model_config,
             const knf::FbankOptions &fbank_config, const std::string &tokens)
      : model_(Model::Create(model_config)),
        feature_extractor_(fbank_config),
        sym_(tokens) {
    // Initialize decoder_output
    int32_t context_size = model_->ContextSize();
    int32_t blank_id = 0;

    ncnn::Mat decoder_input(context_size);
    for (int32_t i = 0; i != context_size; ++i) {
      static_cast<int32_t *>(decoder_input)[i] = blank_id;
    }

    decoder_out_ = model_->RunDecoder(decoder_input);

    hyp_.resize(context_size, 0);
  }

  void DecodeSamples(float sample_rate, const float *samples, int32_t n) {
    feature_extractor_.AcceptWaveform(sample_rate, samples, n);
    Decode();
  }

  void InputFinished() {
    feature_extractor_.InputFinished();
    Decode();
  }

  std::string GetText() const {
    int32_t context_size = model_->ContextSize();
    std::string text;
    for (int32_t i = context_size; i != static_cast<int32_t>(hyp_.size());
         ++i) {
      text += sym_[hyp_[i]];
    }
    return text;
  }

 private:
  void Decode() {
    int32_t segment = model_->Segment();
    int32_t offset = model_->Offset();

    ncnn::Mat encoder_out;
    while (feature_extractor_.NumFramesReady() - num_processed_ >= segment) {
      ncnn::Mat features =
          feature_extractor_.GetFrames(num_processed_, segment);
      num_processed_ += offset;

      std::tie(encoder_out, states_) = model_->RunEncoder(features, states_);

      GreedySearch(model_.get(), encoder_out, &decoder_out_, &hyp_);
    }
  }

 private:
  std::unique_ptr<Model> model_;
  FeatureExtractor feature_extractor_;
  sherpa_ncnn::SymbolTable sym_;

  std::vector<int32_t> hyp_;
  ncnn::Mat decoder_out_;
  std::vector<ncnn::Mat> states_;

  // number of processed frames
  int32_t num_processed_ = 0;
};

static ModelConfig GetModelConfig(JNIEnv *env, jobject config) {
  ModelConfig model_config;

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

  return model_config;
}

static knf::FbankOptions GetFbankOptions(JNIEnv *env, jobject opts) {
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

  return fbank_opts;
}

}  // namespace sherpa_ncnn

JNIEXPORT jlong JNICALL Java_SherpaNcnn_new(JNIEnv *env, jobject /*obj*/,
                                            jobject _model_config,
                                            jobject _fbank_config,
                                            jstring tokens) {
  sherpa_ncnn::ModelConfig model_config =
      sherpa_ncnn::GetModelConfig(env, _model_config);

  knf::FbankOptions fbank_opts =
      sherpa_ncnn::GetFbankOptions(env, _fbank_config);

  const char *p_tokens = env->GetStringUTFChars(tokens, nullptr);
  auto model = new sherpa_ncnn::SherpaNcnn(model_config, fbank_opts, p_tokens);
  env->ReleaseStringUTFChars(tokens, p_tokens);

  return (jlong)model;
}

JNIEXPORT void JNICALL Java_SherpaNcnn_delete(JNIEnv *env, jobject /*obj*/,
                                              jlong ptr) {
  delete reinterpret_cast<sherpa_ncnn::SherpaNcnn *>(ptr);
}

JNIEXPORT void JNICALL Java_SherpaNcnn_decodeSamples(JNIEnv *env,
                                                     jobject /*obj*/, jlong ptr,
                                                     jfloatArray samples,
                                                     jfloat sample_rate) {
  auto model = reinterpret_cast<sherpa_ncnn::SherpaNcnn *>(ptr);

  jfloat *p = env->GetFloatArrayElements(samples, nullptr);
  jsize n = env->GetArrayLength(samples);

  model->DecodeSamples(sample_rate, p, n);

  env->ReleaseFloatArrayElements(samples, p, JNI_ABORT);
}

JNIEXPORT void JNICALL Java_SherpaNcnn_inputFinished(JNIEnv *env,
                                                     jobject /*obj*/,
                                                     jlong ptr) {
  reinterpret_cast<sherpa_ncnn::SherpaNcnn *>(ptr)->InputFinished();
}

JNIEXPORT jbyteArray JNICALL Java_SherpaNcnn_getText(JNIEnv *env,
                                                     jobject /*obj*/,
                                                     jlong ptr) {
  // see
  // https://stackoverflow.com/questions/11621449/send-c-string-to-java-via-jni
  auto text = reinterpret_cast<sherpa_ncnn::SherpaNcnn *>(ptr)->GetText();

  int n = text.size();
  jbyte *p = (jbyte *)text.c_str();
  jbyteArray bytes = env->NewByteArray(n);
  env->SetByteArrayRegion(bytes, 0, n, p);

  return bytes;
}
