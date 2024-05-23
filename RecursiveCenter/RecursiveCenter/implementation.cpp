#include "header.hpp"

int center(std::list<int>::const_iterator start, std::list<int>::const_iterator end) {
  std::list<int>::const_iterator end_minus_1 = --end;
  if (end_minus_1 == start) {
    // The iterators are next to each other and the value is pointed at by start
    return *start;
  } 
  std::list<int>::const_iterator start_plus_1 = ++start;
  // Move both iterators closer to the center
  return center(start_plus_1, end_minus_1);
}