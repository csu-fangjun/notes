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


class OnlineFbank(var opts: FbankOptions) {
  private var ptr: Long

  init {
    ptr = new(opts)
    println("ptr: $ptr")
  }

  protected fun finalize() {
    delete(ptr)
  }

  val dim: Int
      get() = dim(ptr)

  val frameShiftInSeconds: Float
      get() = frameShiftInSeconds(ptr)

  val numFramesReady: Int
      get() = numFramesReady(ptr)

  fun isLastFrame(i: Int) :Boolean = isLastFrame(ptr, i)
  fun inputFinished() = inputFinished(ptr)
  fun acceptWaveform(samples: FloatArray) = acceptWaveform(ptr, samples, opts.frame_opts.samp_freq)
  fun getFrame(i: Int): FloatArray = getFrame(ptr, i)

  private external fun new(opts: FbankOptions): Long
  private external fun delete(ptr: Long)
  private external fun dim(ptr: Long): Int
  private external fun frameShiftInSeconds(ptr: Long): Float
  private external fun numFramesReady(ptr: Long): Int
  private external fun isLastFrame(ptr: Long, i: Int): Boolean
  private external fun inputFinished(ptr: Long)
  private external fun acceptWaveform(ptr: Long, samples: FloatArray, sample_rate: Float)
  private external fun getFrame(ptr: Long, i: Int): FloatArray

  companion object {
    init {
      System.loadLibrary("online-feature")
    }
  }
}
