#include <iostream>
#include "temperature.cpp" // LAter you will be taught better ways to include files

int main() 
{
  Temperature t(13, 'C'); // 13.0 degrees C
  std::cout << t.AsKelvin() << std::endl; // Should return 286.15 as that is the temp in Kelvin.
}