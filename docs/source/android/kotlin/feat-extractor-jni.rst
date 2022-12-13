Binding kaldi-native-fbank for kotlin
=====================================

This note shows how to bind `<https://github.com/csukuangfj/kaldi-native-fbank>`_
for kotlin.

.. literalinclude:: ./code/jni/feat-extractor/Makefile
   :language: makefile
   :caption: ./code/jni/feat-extractor/Makefile

.. literalinclude:: ./code/jni/feat-extractor/online-feature.h
   :language: c++
   :caption: ./code/jni/feat-extractor/online-feature.h

.. literalinclude:: ./code/jni/feat-extractor/online-feature.cc
   :language: c++
   :caption: ./code/jni/feat-extractor/online-feature.cc

.. literalinclude:: ./code/jni/feat-extractor/sherpa-ncnn.h
   :language: c++
   :caption: ./code/jni/feat-extractor/sherpa-ncnn.h

.. literalinclude:: ./code/jni/feat-extractor/sherpa-ncnn.cc
   :language: c++
   :caption: ./code/jni/feat-extractor/sherpa-ncnn.cc

.. literalinclude:: ./code/jni/feat-extractor/Main.kt
   :language: java
   :caption: ./code/jni/feat-extractor/Main.kt

.. literalinclude:: ./code/jni/feat-extractor/OnlineFeature.kt
   :language: java
   :caption: ./code/jni/feat-extractor/OnlineFeature.kt

.. literalinclude:: ./code/jni/feat-extractor/WaveReader.kt
   :language: java
   :caption: ./code/jni/feat-extractor/WaveReader.kt

.. literalinclude:: ./code/jni/feat-extractor/Model.kt
   :language: java
   :caption: ./code/jni/feat-extractor/Model.kt
