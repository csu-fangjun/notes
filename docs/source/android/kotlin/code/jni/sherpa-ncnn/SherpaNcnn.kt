data class FrameExtractionOptions(
  var samp_freq: Float = 16000.0f,
  var frame_shift_ms: Float = 10.0f,
  var frame_length_ms: Float = 25.0f,
  var dither: Float = 0.0f,
  var preemph_coeff: Float = 0.97f,
  var remove_dc_offset: Boolean = true,
  var window_type: String = "povey",
  var round_to_power_of_two: Boolean = true,
  var blackman_coeff: Float = 0.42f,
  var snip_edges: Boolean = true,
  var max_feature_vectors: Int = -1
)

data class MelBanksOptions(
  var num_bins : Int = 25,
  var low_freq : Float = 20.0f,
  var high_freq : Float = 0.0f,
  var vtln_low : Float = 100.0f,
  var vtln_high : Float = -500.0f,
  var debug_mel : Boolean = false,
  var htk_mode : Boolean = false,
)

data class FbankOptions(
  var frame_opts: FrameExtractionOptions = FrameExtractionOptions(),
  var mel_opts: MelBanksOptions = MelBanksOptions(),
  var use_energy: Boolean = false,
  var energy_floor: Float = 0.0f,
  var raw_energy: Boolean = true,
  var htk_compat: Boolean = false,
  var use_log_fbank: Boolean = true,
  var use_power: Boolean = true,
)

data class ModelConfig(
  var encoderParam: String,
  var encoderBin: String,
  var decoderParam: String,
  var decoderBin: String,
  var joinerParam: String,
  var joinerBin: String,
  var numThreads: Int = 4,
)

class SherpaNcnn(var modelConfig: ModelConfig, var fbankConfig: FbankOptions, var tokens: String) {
  private var ptr: Long

  init {
    ptr = new(modelConfig, fbankConfig, tokens)
  }

  protected fun finalize() {
    delete(ptr)
  }

  fun decodeSamples(samples: FloatArray) = decodeSamples(ptr, samples, sample_rate=fbankConfig.frame_opts.samp_freq)
  fun inputFinished() = inputFinished(ptr)

	var text: String = ""
			// get() = String(getText(ptr), charset("UTF-8"))
	    get() = getText(ptr).decodeToString()

  private external fun new(modelConfig: ModelConfig, fbankConfig: FbankOptions, tokens: String): Long
  private external fun delete(ptr: Long)
  private external fun decodeSamples(ptr: Long, samples: FloatArray, sample_rate: Float)
  private external fun inputFinished(ptr: Long)
  private external fun getText(ptr: Long): ByteArray

  companion object {
    init {
      System.loadLibrary("sherpa-ncnn")
    }
  }
}
