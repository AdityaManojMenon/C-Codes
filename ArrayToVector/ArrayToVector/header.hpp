#ifndef ArrayToVector_HPP
#define ArrayToVector_HPP

#include <vector>

template <typename T>
std::vector<T>ArrayToVector(const T * const arr, int size)
{
  std::vector<T>vec;
  for(int i = 0; i < size; ++i)
  {
    vec.push_back(arr[i]);
  }
  delete [] arr;
  return vec;
}

#endif