#include <string>
#include <cmath>
#include <iostream>
#include "header.hpp"

std::string Price::toString() const {
  int dollars = pennies / 100;
  int cents = pennies % 100;
  std::string result = "$";
  result += std::to_string(dollars);
  result += '.';
  if (cents < 10) {
    result += '0';
  }
  result += std::to_string(cents);
  return result;
}

Price::Price() : pennies(0) {}
Price::Price(double d) {
  pennies = static_cast<int>(std::trunc(d * 100));
}

std::ostream & operator<<(std::ostream & out, const Price & p) {
  return out << p.toString();
}

Price & Price::operator+=(const Price & other) {
  pennies += other.pennies;
  return *this;
}

Price operator+(const Price & p1, const Price & p2) {
  Price result(p1);
  result += p2;
  return result;
}

Price & Price::operator-=(const Price & other) {
  pennies += -1 * other.pennies;
  return *this;
}

Price operator-(const Price & p1, const Price & p2) {
  Price result(p1);
  result -= p2;
  return result;
}

std::istream & operator>>(std::istream & in, Price & p) {
  in.get(); // Remove $
  double price_as_double;
  in >> price_as_double;
  p = Price(price_as_double);
  return in;
}