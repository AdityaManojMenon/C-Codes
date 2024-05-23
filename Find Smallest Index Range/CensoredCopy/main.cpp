#include "func.hpp"
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>

int main() {
	std::map<std::string, std::string> bad_to_good = {{"word", "Grouped-Letters"}, {"be", "wasp"}, {"not found", "not appearing"}};
  std::istringstream iss("this is a line with multiple words that should be replaced./n all instances of word eveninlargerwordsshould be replaced.");
  std::ostringstream oss;
  std::set<std::string> result = ReplacementCensor(iss, oss, bad_to_good);
  std::set<std::string> expected_return = {"word", "be"};
  assert(result == expected_return);
  assert(oss.str() == "this is a line with multiple words that should be replaced./n all instances of word eveninlargerwordsshould be replaced.");
}