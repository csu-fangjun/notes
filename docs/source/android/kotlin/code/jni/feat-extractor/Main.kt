fun main() {
  var fbank_opts = FbankOptions()
  fbank_opts.mel_opts.num_bins = 80

	var online_fbank = OnlineFbank(fbank_opts)

	var samples = WaveReader.readWave("./1089-134686-0001.wav", 16000.0f)
	if(samples != null) {
		online_fbank.acceptWaveform(samples)
	}
	online_fbank.inputFinished()
}
