class WaveReader {

  companion object {
    // Read a mono wave file.
    // No resampling is made.
    external fun readWave(filename: String, expected_sample_rate: Float = 16000.0f) : FloatArray?

    init {
      System.loadLibrary("sherpa-ncnn")
    }
  }
}
