#include <cctype>
#include <iostream>
#include <string>

std::string ShortWords(std::string input) {
  input += "\n";
  std::string new_line = "";
  std::string word = "";
  int line_length = static_cast<int>(input.size());

  for (int i = 0; i < line_length; ++i) {
    if (!std::isspace(input.at(i))) {
      word += input.at(i);
    } else {
      if (word.size() >= 5) {
        new_line += word + " ";
      }
      word.clear();
    }
  }

  return new_line;
}

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    std::cout << ShortWords(line) << std::endl;
  }
  return 0;
}