#include "ForgetfulVector.hpp"

void ForgetfulVector::push_back(int num)
{
  bool found = false;
  if(inputs.size() > 1)
  {
    for(int val : inputs)
    {
      if(val == num)
      {
        found = true;
      }
    }
  }

  if(found == true)
  {
    vec.push_back(num);
  }

  inputs.push_back(num);
}

int ForgetfulVector::size()
{
  int len = vec.size();
  return len;
}

int ForgetfulVector::at(int index)
{
  return vec.at(index);
}