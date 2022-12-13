fun main() {
  var fbank_opts = FbankOptions()
  fbank_opts.mel_opts.num_bins = 80

	var online_fbank = OnlineFbank(fbank_opts)
	println(online_fbank.opts)
	println(online_fbank.dim)
	println(online_fbank.frameShiftInSeconds)
	println(online_fbank.numFramesReady)
	println(online_fbank.isLastFrame(0))

  var samples = FloatArray(1 * 16000) { it.toFloat() / 16000 }
  online_fbank.acceptWaveform(samples)
	println(online_fbank.numFramesReady)

  online_fbank.acceptWaveform(samples)
	println(online_fbank.numFramesReady)
	var f = online_fbank.getFrame(0)
  for (i in f) {print("$i, ")}
  println()
	f = online_fbank.getFrame(1)
  for (i in f) {print("$i, ")}
  println()
}
