fun main() {
  var frame_opts  = FrameExtractionOptions()
	frame_opts.samp_freq = 1200.0f
	frame_opts.window_type = "abc"
  var mel_opts  = MelBanksOptions()
  var fbank_opts = FbankOptions(frame_opts, mel_opts, use_energy=true, energy_floor=10.2f)

	fbank_opts.use_energy = true
	var fbank_computer = FbankComputer(fbank_opts)
	print(fbank_computer.opts)
}
