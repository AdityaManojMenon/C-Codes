#pragma once

#include <map>
#include <set>
#include <string>
#include <iostream>

std::set<std::string> ReplacementCensor(std::istream & is, std::ostream & os, std::map<std::string, std::string> const & bad_to_good);
