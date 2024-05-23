#include <iostream>
#include <algorithm>

using namespace std;

double Centrifuge(int& time, int& ore, double * u_238)
{
  int time_per_cycle = 12;
  int ore_per_cycle = 10;
  double u_235_per_cycle = 0.007;
  double u_238_per_cycle = 0.993;

  int possible_cycles_in_time = time/time_per_cycle;
  int possible_cycles_for_ore = ore/ore_per_cycle;
  int cycles = std::min(possible_cycles_in_time, possible_cycles_for_ore);
  time -= cycles * time_per_cycle;
  ore -= cycles * ore_per_cycle;
  *u_238 += cycles * u_238_per_cycle;
  return cycles * u_235_per_cycle;
}

//piazza