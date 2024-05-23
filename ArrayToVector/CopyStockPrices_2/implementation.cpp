#include "header.hpp"
void CopyStockPrices(double const * source, double * dest) {
  int source_size = *source;
  *dest = *source;  // copy size
  for (int i = 1; i <= static_cast<int>(source_size); ++i) {
    dest[i] = source[i];
  }
}