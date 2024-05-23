#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <complex>
#include <valarray>
#include "header.hpp"

int SumOfOdd(std::vector<int>::const_iterator const & begin, 
  std::vector<int>::const_iterator const & end) {
  std::vector<int> vec(begin, end);
  std::vector<int>::iterator end_of_even = std::remove_if(
    vec.begin(), vec.end(), [](int i){return i % 2 == 0;});
  return std::accumulate(vec.begin(), end_of_even, 0);
}

void MakeComplex(std::valarray<std::complex<int>> & numbers) {
  std::ranges::replace_if(numbers, [](std::complex<int> const & num) {
    return num.imag() == 0;
  }, std::complex<int>(0, 1));
}

int main() {
	std::vector<int> const numbers = {1, 2, 3, 4, 5, 6, 8, 5, 2, 2, 5, 101};
	std::cout << SumOfOdd(numbers.cbegin(), numbers.cend()) << std::endl;
	std::cout << SumOfOdd(numbers.begin(), numbers.end()) << std::endl;

  std::valarray<std::complex<int>> complex_numbers = {{{1, 2}, {3, 0}, {0, 7}, {-45, -68}}};
  MakeComplex(complex_numbers);
  std::ranges::copy(complex_numbers, std::ostream_iterator<std::complex<int>>(std::cout, " "));
  // (1,2) (0,1) (0,7) (-45,-68)

}
