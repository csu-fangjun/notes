data class ModelConfig(
  var encoderParam: String,
  var encoderBin: String,
  var decoderParam: String,
  var decoderBin: String,
  var joinerParam: String,
  var joinerBin: String,
  var numThreads: Int = 4,
)

class Model(var config: ModelConfig) {
  private var ptr: Long

  init {
    ptr = new(config)
  }

  protected fun finalize() {
    delete(ptr)
  }

  val segment: Int
      get() = segment(ptr)

  val offset: Int
      get() = offset(ptr)

  private external fun new(config: ModelConfig): Long
  private external fun delete(ptr: Long)
  private external fun segment(ptr: Long): Int
  private external fun offset(ptr: Long): Int

}
