#pragma once

#include <string>
#include <vector>
#include<iostream>

class Counter {
 public:
  int value_ = 0;
  int initial_value_ = 0;
  std::vector<std::string> log_;
  Counter(int v);
  Counter();
  int Value();
  Counter(const Counter &);
  Counter & operator=(const Counter &);
  ~Counter();
};

std::ostream & operator<<(std::ostream &, Counter &);
Counter operator+(Counter const &, Counter const &);