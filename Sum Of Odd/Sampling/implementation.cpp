#include "header.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include <random>
#include <cstdint>


std::vector<int> SampleWithReplacement(std::vector<int> const & population, int n, std::uint64_t seed) {
  std::mt19937_64 gen(seed);
  std::uniform_int_distribution<> dist(0, population.size() - 1);
  std::vector<int> sample;
  auto random_element = [&](){return population.at(dist(gen));};
  std::generate_n(std::back_inserter(sample), n, random_element);
  return sample;
}
int main() {
	std::vector<int> const population = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5};
	std::vector<int> sample = SampleWithReplacement(population, 20, 123);
  std::ranges::copy(sample, std::ostream_iterator<int>(std::cout, " "));
  // 4 5 5 5 2 2 5 3 5 5 3 5 1 5 5 5 5 5 4 5 

}
