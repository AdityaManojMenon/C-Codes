#pragma once

#include <stack>

template <typename T>
std::stack<T> reverse_stack(std::stack<T> original) {
  std::stack<T> result;
  while (!original.empty()) {
    result.push(original.top());
    original.pop();
  }
  return result;
}