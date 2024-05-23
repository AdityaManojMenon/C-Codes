#ifndef FORGETFUL_VECTOR_HPP
#define FORGETFUL_VECTOR_HPP
#include <vector>
#include<iostream>

class ForgetfulVector
{
  private:
    std::vector<int>vec;
    std::vector<int>inputs;

  public:
    void push_back(int num);
    int size();
    int at(int index);
};

#endif