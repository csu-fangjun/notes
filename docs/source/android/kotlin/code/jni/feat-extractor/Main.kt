fun main() {
  var fbank_opts = FbankOptions()
  fbank_opts.mel_opts.num_bins = 80

	var online_fbank = OnlineFbank(fbank_opts)

	var samples = WaveReader.readWave("./1089-134686-0001.wav", 16000.0f)
	if(samples != null) {
		online_fbank.acceptWaveform(samples)
	}
	online_fbank.inputFinished()

	var modelConfig = ModelConfig(
			encoderParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/encoder_jit_trace-epoch-30-avg-10-pnnx.ncnn.param",
			encoderBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/encoder_jit_trace-epoch-30-avg-10-pnnx.ncnn.bin",
			decoderParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/decoder_jit_trace-epoch-30-avg-10-pnnx.ncnn.param",
			decoderBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/decoder_jit_trace-epoch-30-avg-10-pnnx.ncnn.bin",
			joinerParam="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/joiner_jit_trace-epoch-30-avg-10-pnnx.ncnn.param",
			joinerBin="./sherpa-ncnn-conv-emformer-transducer-2022-12-04/joiner_jit_trace-epoch-30-avg-10-pnnx.ncnn.bin",
			numThreads=4,
	)
	var model = Model(modelConfig)
	println("segment: ${model.segment}")
	println("offset: ${model.offset}")
}
