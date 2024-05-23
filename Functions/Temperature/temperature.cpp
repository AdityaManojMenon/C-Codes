#include <stdexcept> 

class Temperature
{
  double temp_c;

  public:
    Temperature(double temp, char unit)
    {
      switch(unit)
      {
        case 'C':
          temp_c = temp;
          break;
        case 'F':
          temp_c = (temp-32)*(5.0/9.0);
          break;
        case 'R':
          temp_c = (temp - 491.67)*(5.0/9.0);
          break;
        case 'K':
          temp_c = temp - 273.15;
          break;
        default:
          throw std::out_of_range("Unexpected Unit");
      }
    }

  double AsCelsius()
  {
    return temp_c;
  }

  double AsFahrenheit()
  {
    return temp_c*(9.0/5.0)+32;
  }

  double AsRankine()
  {
    return temp_c*(9.0/5.0)+491.67;
  }

  double AsKelvin()
  {
    return temp_c + 273.15;
  }
};