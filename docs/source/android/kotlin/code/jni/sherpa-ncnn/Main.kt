fun main() {
  var fbankConfig= FbankOptions()
  fbankConfig.frame_opts.dither = 0.0f
  fbankConfig.mel_opts.num_bins = 80


	var samples = WaveReader.readWave("./sherpa-ncnn-conv-emformer-transducer-2022-12-04/test_wavs/1089-134686-0001.wav", 16000.0f)

	var modelConfig = ModelConfig(
			encoderParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/encoder_jit_trace-epoch-30-avg-10-pnnx.ncnn.param",
			encoderBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/encoder_jit_trace-epoch-30-avg-10-pnnx.ncnn.bin",
			decoderParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/decoder_jit_trace-epoch-30-avg-10-pnnx.ncnn.param",
			decoderBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/decoder_jit_trace-epoch-30-avg-10-pnnx.ncnn.bin",
			joinerParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/joiner_jit_trace-epoch-30-avg-10-pnnx.ncnn.param",
			joinerBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/joiner_jit_trace-epoch-30-avg-10-pnnx.ncnn.bin",
			numThreads=4,
	)

	var tokens = "./sherpa-ncnn-conv-emformer-transducer-2022-12-04/tokens.txt"

  samples = WaveReader.readWave("./sherpa-ncnn-conv-emformer-transducer-2022-12-06/test_wavs/0.wav")
	modelConfig = ModelConfig(
			encoderParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-06/encoder_jit_trace-pnnx.ncnn.param",
			encoderBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-06/encoder_jit_trace-pnnx.ncnn.bin",
			decoderParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-06/decoder_jit_trace-pnnx.ncnn.param",
			decoderBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-06/decoder_jit_trace-pnnx.ncnn.bin",
			joinerParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-06/joiner_jit_trace-pnnx.ncnn.param",
			joinerBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-06/joiner_jit_trace-pnnx.ncnn.bin",
			numThreads=4,
	)
	tokens = "./sherpa-ncnn-conv-emformer-transducer-2022-12-06/tokens.txt"

  println("modelConfig: $modelConfig")

	var model = SherpaNcnn(modelConfig=modelConfig, fbankConfig=fbankConfig, tokens=tokens)
  if (samples != null) {
    model.decodeSamples(samples)
    model.inputFinished()
    var text = model.text
    println("result: $text")
  } else {
    println("empty wave")
  }

}
