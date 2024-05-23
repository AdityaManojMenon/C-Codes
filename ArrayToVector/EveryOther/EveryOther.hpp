#pragma once

#include <initializer_list>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

template <typename ElementType>
class EveryOther {
 private:
  std::vector<ElementType> vec_;
  bool works_ = true;
  
 public:
  EveryOther()=default;
  EveryOther(std::initializer_list<ElementType> lst) {
    works_ = true;
    for (auto & e : lst) {
      if (works_) 
        vec_.push_back(e);
      works_ = !works_;
    }
  }
  void push_back(ElementType e) {
    if (works_) 
      vec_.push_back(e);
    works_ = !works_;
  }
  int size() {
    return static_cast<int>(vec_.size());
  }
  friend std::ostream& operator<<(std::ostream &out, const EveryOther<ElementType> &eo){
    out << "EveryOther(";
    std::copy(eo.vec_.begin(), eo.vec_.end(),
      std::ostream_iterator<ElementType>(out, ", "));
    out << ")";
    return out;
  }
};