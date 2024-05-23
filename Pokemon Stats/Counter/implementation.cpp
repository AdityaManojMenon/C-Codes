#include "header.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

Counter::Counter(int v) : value_(v), initial_value_(v), log_() {
  log_.push_back("Constructor called with a " + std::to_string(value_));
}

int Counter::Value() {
  int result = value_--;
  log_.push_back("Value called. Returned a " + std::to_string(result));
  return result;
}

std::ostream & operator<<(std::ostream & o, Counter & c) {
  o << "Counter(" << c.initial_value_ << ")@" << c.value_;
  c.log_.push_back("<< called.");
  return o;
}

Counter operator+(Counter const & a, Counter const & b) {
  Counter c(a.initial_value_ + b.initial_value_);
  c.value_ = a.value_ + b.value_;
  c.log_.push_back("+ called.");
  return c;
}

Counter::Counter() : value_(0), initial_value_(0), log_() {
  log_.push_back("Default Constructor called.");
}

Counter::~Counter() {
  log_.push_back("~ called.");
}

Counter & Counter::operator=(const Counter & c) {
    log_ = c.log_;
    value_ = c.value_;
    initial_value_ = c.initial_value_;
    log_.push_back("= called.");
    return *this;
}

Counter::Counter(const Counter & c) {
    log_ = c.log_;
    value_ = c.value_;
    initial_value_ = c.initial_value_;
    log_.push_back("Copy Constructor called.");
}
