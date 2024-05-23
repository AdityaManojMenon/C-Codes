#include <iostream>
#include <cctype>

int main()
{
  char ch_curr, ch_prev = '\0';
  while(std::cin.get(ch_curr))
  {
    if(!isalpha(ch_prev))
    {
      if(isalpha(ch_curr))
      {
        std::cout<<ch_curr;
      }
    }
    ch_prev = ch_curr;
  }
}