#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <iterator>
#include <cstdint>

std::vector<int> GetSequence(uint64_t seed) {
  std::mt19937_64 gen{seed};
  std::uniform_int_distribution<> dist(10, 99);
  std::vector<int> random_numbers(20);
  std::ranges::generate(random_numbers, [&](){return dist(gen);});
  return random_numbers;
}

void PrintSequence(std::vector<int> const & vec) {
  std::ostream_iterator<int> cout_iter(std::cout, " ");
  std::ranges::copy(vec, cout_iter);
  std::cout << std::endl;
}

int main() {
  std::vector<uint64_t> seeds(1000);
  std::ranges::iota(seeds, 0);
  std::vector<std::vector<int>> number_sequences;
  std::ranges::transform(seeds, std::back_inserter(number_sequences), GetSequence);
  
  std::istream_iterator<int> cin_iter(std::cin);
  std::vector<int> input_sequence(10);
  std::ranges::copy_n(cin_iter, 10, input_sequence.begin());

  // PrintSequence(input_sequence);
  std::vector<std::vector<int>>::iterator match = std::ranges::find_if(number_sequences, 
    [input_sequence](std::vector<int> const & seq){
    return std::equal(input_sequence.begin(), input_sequence.end(), seq.begin());
  });
  std::cout << "Seed: " << std::distance(number_sequences.begin(), match) << std::endl;
  PrintSequence(*match);
  std::cout <<  std::endl;
}
