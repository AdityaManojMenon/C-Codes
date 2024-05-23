#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int n;
  
  cin>>n;
  cout<<n*2<<endl;
}

int Triple(int a)
{
  int ans;

  ans = a*3;

  return ans;
}

int Closest_Multiple_Of_13(int a)
{
  int div_,res;
  double div, num = static_cast<double>(a),diff;
  
  if(a < 0)
  {
      div = num/13.0;
      div_ = a/13.0;
  
      diff = div-div_;
      
      if(diff > -0.5)
      {
        res = div_*13;
      }
      else
      {
        res = (div_-1)*13;
      }
  }
  else
  {
      div = num/13.0;
      div_ = a/13.0;
      
      diff = div-div_;
      
      if(diff<0.5)
      {
        res = div_*13;
      }
      else
      {
        res = (div_+1)*13;
      }
  }    

  return res;
}