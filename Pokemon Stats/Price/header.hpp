#pragma once
#include <string>
#include <iostream>

class Price {
  int pennies;
public:
  std::string toString() const;
  Price(double);
  Price();
  Price & operator+=(const Price &);
  Price & operator-=(const Price &);
};
std::ostream & operator<<(std::ostream &, const Price &);
Price operator+(const Price & p1, const Price & p2);
Price operator-(const Price & p1, const Price & p2);
std::istream & operator>>(std::istream &, Price &);