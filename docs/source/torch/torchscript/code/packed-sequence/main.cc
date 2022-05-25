#include "torch/all.h"

static void TestPadPackedSequence() {
  torch::Tensor t = torch::tensor({
      {{10, 20, 30}, {0, 0, 0}},
      {{1, 2, 3}, {4, 5, 6}},
  });
  torch::Tensor lengths = torch::tensor({1, 2});
  torch::nn::utils::rnn::PackedSequence packed_seq =
      torch::nn::utils::rnn::pack_padded_sequence(
          t, lengths, /*batch_first*/ true, /*enforce_sorted*/ false);
  std::cout << "data: " << packed_seq.data() << "\n";
  std::cout << "batch_sizes: " << packed_seq.batch_sizes() << "\n";
  std::cout << "sorted_indices: " << packed_seq.sorted_indices() << "\n";
  std::cout << "unsorted_indices: " << packed_seq.unsorted_indices() << "\n";
}
/*
data:   1   2   3
 10  20  30
  4   5   6
[ CPULongType{3,3} ]
batch_sizes:  2
 1
[ CPULongType{2} ]
sorted_indices:  1
 0
[ CPULongType{2} ]
unsorted_indices:  1
 0
[ CPULongType{2} ]
 */

int main() { TestPadPackedSequence(); }
