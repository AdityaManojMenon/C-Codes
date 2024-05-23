#include "header.hpp"
#include <vector>
#include <string>
#include <sstream>

std::string LispExpression::PrettyPrint() {
    std::ostringstream oss;
    int indent_level = 0;
    for (std::string const & token : tokens) {
        if (token == ")") {
            --indent_level;
        }
        oss << std::string(indent_level, ' ') << token << std::endl;
        if (token == "(") {
            ++indent_level;
        }  
    }
    return oss.str();
}


LispExpression::LispExpression(std::string const & str) {
    std::istringstream iss(str);
    int number_unclosed_parentheses{0};
    std::string token;
    while (iss >> token) {
        if (token == "(") {
            ++number_unclosed_parentheses;
        } else if (token == ")") {
            --number_unclosed_parentheses;
        }
        tokens.push_back(token);

        if (number_unclosed_parentheses == 0) {
            break;
        }
    }
}
