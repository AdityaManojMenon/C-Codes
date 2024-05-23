#include <iostream>
#include "header.hpp"
int main() {
	int * array = new int[5];
	array[0] = 1;
	array[0] = 1;
	array[0] = 1;
	array[0] = 2;
	array[0] = 4;
	int result = SumOf5(array);
	std::cout << result << std::endl;
}