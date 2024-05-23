#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <sstream>

std::string OnlyUppercase(std::string word) { // Intentional Copy
  std::string::iterator new_end = std::remove_if(word.begin(), word.end(), 
    [](char c){return !std::isupper(c);});
  word.erase(new_end, word.end());
  return word;
}

void SortByUppercase(std::vector<std::string> & words) {
    std::stable_sort(words.begin(), words.end(), 
    [](std::string const & left, std::string const & right) {
      return OnlyUppercase(left) < OnlyUppercase(right);
    });
}

std::string DoubleToPercentString(std::vector<double> const & numbers) {
  std::vector<int> percents;
  std::transform(numbers.cbegin(), numbers.cend(), std::back_inserter(percents),
            [](double d) { return static_cast<int>(d * 100); });
  std::ostringstream oss;
  copy(percents.cbegin(), percents.cend(), std::ostream_iterator<int>(oss, "% "));
  return oss.str();
} 

int main() {
  std::vector<double> const doubles = {1, 2, 100, 200, 12.3456, 4787, 0.123};
  std::cout << DoubleToPercentString(doubles) << std::endl;
}