package com.k2fsa.sherpa.ncnn

class Hello {
  companion object {
    init {
        System.loadLibrary("hello")
    }
  }

  external fun getText()
}
