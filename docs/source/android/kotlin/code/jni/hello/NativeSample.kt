class NativeSample {
  companion object {
    init {
        System.loadLibrary("hello")
    }
  }

  external fun sayHello()
  external fun sum(array: FloatArray): Float
}
