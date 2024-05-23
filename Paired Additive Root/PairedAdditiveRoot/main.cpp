#include <iostream>
int main() 
{
	int value{0};
	while (std::cin >> value) 
  {
		int root{0},remainder{0};
		
		if(value < 0)
		{
			break;
		}
		while(value > 0)
		{
			remainder=value%100;
			value=value/100;
			root+=remainder;
			if(value<10)
			{
				root+=value;
				if(root>99)
				{
					value = root;
					root = 0;
				}
				else
				{
					break;
				}
			}
		}
    
		std::cout << root << std::endl;
	}
}