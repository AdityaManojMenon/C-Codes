#ifndef PENULTIMATE_HPP
#define PENULTIMATE_HPP
#include <vector>
#include <iostream>
#include <string>


class Penultimate
{
  private:
    std::vector<std::string>ans;
  
  public:

    Penultimate(std::string initial);

    std::string push_back(std::string input);

};


#endif