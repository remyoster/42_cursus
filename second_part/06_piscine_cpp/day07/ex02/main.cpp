#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> intTab = Array<int>(5);
	Array<int> intTab2 = Array<int>(5);
	Array<int> intTab3 = Array<int>(intTab2);

	std::cout << intTab[0] << std::endl;

	intTab[2] = 42;
	std::cout << intTab[2] << std::endl;
	intTab2 = intTab;
	std::cout << intTab2[2] << std::endl;
	intTab[0] = 470;
	std::cout << intTab[0] << std::endl;
	std::cout << intTab2[0] << std::endl;

	try
	{
		intTab[457] = 8;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}