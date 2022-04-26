Decoding
========

.. code-block::

  CompactLattice compact_lat;
  decoder.GetLattice(true, &compact_lat);

  CompactLattice compact_best_path;
  CompactLatticeShortestPath(compact_lat, &compact_best_path);

  Lattice best_path;
  ConvertLattice(compact_best_path, best_path);

  std::vector<int32_t> tokens;
  std::vector<int32_t> words;
  LatticeWeight weight;
  GetLinearSymbolSequence(best_path, &tokens, &words, &weight);

- ``decoder/simple-decoder.{h,cc}``
