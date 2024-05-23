#include <iostream>

int main()
{
  int row_start,row_end,col_start,col_end;

  std::cin>>row_start>>row_end;
  std::cin>>col_start>>col_end;

  for(int i = col_start; i < col_end+1; ++i)
  {
    for(int j = row_start; j < row_end+1; ++j)
    {
      if(j != row_end)
      {
        std::cout<<i<<"*"<<j<<"="<<i*j<<","<<" ";
      }
      else
      {
        std::cout<<i<<"*"<<j<<"="<<i*j;
      }
    }
    std::cout<<std::endl;
  }
}