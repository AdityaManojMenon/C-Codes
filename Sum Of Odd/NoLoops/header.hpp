#pragma once


#include <vector>
#include <valarray>
#include <complex>

int SumOfOdd(std::vector<int>::const_iterator const & begin, 
  std::vector<int>::const_iterator const & end);

void MakeComplex(std::valarray<std::complex<int>> & numbers);