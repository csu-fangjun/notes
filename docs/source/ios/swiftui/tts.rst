TTS
===

- Extend Speech Synthesis with personal and custom voices

  `<https://developer.apple.com/videos/play/wwdc2023/10033/>`_

- Creating an audio unit extension

  `<https://developer.apple.com/documentation/avfaudio/audio_engine/audio_units/creating_an_audio_unit_extension>`_

  It describes how to set a parameter from the host app

- `<https://appmakers.dev/bcp-47-language-codes-list/>`_

xcode, create project, select ios or macos, select Audio Unit Extension App

  1. Product name: sherpa-onnx-tts
  2. Team: None
  3. Organization identifier: org.k2-fsa
  4. Organization name: Next-gen Kaldi
  5. Audio unit type: Speech synthesizer
  6. Subtype code: k2k2
  7. Manufacturer code: k2k2
  8. User interface: No user interface
  9. Include tests: Don't check it

example::

  public override var internalRenderBlock: AUInternalRenderBlock {
         return { [weak self]
             actionFlags, timestamp, frameCount, outputBusNumber, outputAudioBufferList, _, _ in
             guard let self else { return kAudio_ParamError }

             // This is the audio buffer we are going to fill up
             var unsafeBuffer = UnsafeMutableAudioBufferListPointer(outputAudioBufferList)[0]
             let frames = unsafeBuffer.mData!.assumingMemoryBound(to: Float32.self)

             var sourceBuffer = UnsafeMutableAudioBufferListPointer(self.currentBuffer!.mutableAudioBufferList)[0]
             let sourceFrames = sourceBuffer.mData!.assumingMemoryBound(to: Float32.self)

             for frame in 0..<frameCount {
                 if frames.count > frame && sourceFrames.count > self.framePosition {
                     frames[Int(frame)] = sourceFrames[Int(self.framePosition)]
                     self.framePosition += 1
                     if self.framePosition >= self.currentBuffer!.frameLength {
                         break
                     }
                 }
             }

             return noErr
         }
