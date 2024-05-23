#include "Penultimate.hpp"

Penultimate::Penultimate(std::string initial)
{
  ans.push_back(initial);
}

std::string Penultimate::push_back(std::string input)
{
  std::string res;
  ans.push_back(input);
  int size = ans.size();
  res = ans.at(size-2);
  return res;
}