#include <iostream>

int main()
{
  char ch_curr, ch_prev = '\0';
  while(std::cin.get(ch_curr))
  {
    if(ch_curr == '\n' || ch_prev < ch_curr || ch_prev == '\0')
    {
      std::cout<<ch_curr;
    }
    else
    {
      std::cout<<"_";
    }
    
    if(ch_curr != '\n')
    {
      ch_prev = ch_curr;
    }
  }
}