#include <iostream>
#include "header.hpp"

int main() {
	int size = 7;
	double source[] = {3, 1, 2, 3, 67, -4, 13};
	double destination[size] = {};
	CopyStockPrices(source, destination);
	for (int i = 0; i < size; ++i) {
		std::cout << destination[i] << std::endl;
	}
	return 0;
}