#pragma once
#include <vector>
#include <string>

class LispExpression {
    std::vector<std::string> tokens;
  public:
    LispExpression(std::string const &);
    std::string PrettyPrint();
};
