#pragma once

#include <vector>

std::vector<int>::const_iterator FindSmallestIndexRange(
    std::vector<int> const & data, int begin_pos, int end_pos);

template <typename Iterator>
void DoubleIteratorRange(Iterator begin, Iterator end) {
  for (Iterator iter = begin; iter != end; ++iter) {
    *iter *= 2;
  }
}