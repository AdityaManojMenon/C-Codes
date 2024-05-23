#include <string>

std::string::size_type Find_Number(std::string const & text, std::string const & number) {
  std::string lowercase_text;
  for (char const & letter : text) {
    lowercase_text.push_back(std::tolower(letter));
  }
  return lowercase_text.find(number);
}

void ReplaceNumber(std::string & text, std::string const & seek, std::string const & replacement) {
  for (std::string::size_type pos = Find_Number(text, seek); pos != std::string::npos; pos = Find_Number(text, seek)) {
    text.replace(pos, seek.size(), replacement);
  } 
}

void To_Digits(std::string & input) {
  ReplaceNumber(input, "zero", "0");
  ReplaceNumber(input, "one", "1");
  ReplaceNumber(input, "two", "2");
  ReplaceNumber(input, "three", "3");
  ReplaceNumber(input, "four", "4");
  ReplaceNumber(input, "five", "5");
  ReplaceNumber(input, "six", "6");
  ReplaceNumber(input, "seven", "7");
  ReplaceNumber(input, "eight", "8");
  ReplaceNumber(input, "nine", "9");
}