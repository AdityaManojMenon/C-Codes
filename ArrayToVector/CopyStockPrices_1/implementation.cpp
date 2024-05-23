#include "header.hpp"

void CopyStockPrices(double const * source, double* des)
{
  while(true)
  {
    *des = *source;
    ++des;
    ++source;
    if(*source < 0.0)
    {
      break;
    }
  }
  *des = *source;
}