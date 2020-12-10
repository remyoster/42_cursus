#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <set>

int main()
{
	std::list<int> lst;
	std::vector<int> v1(10);
	int myints[] = {10, 20, 30, 42, 50};
	std::set<int> second(myints, myints + 5);
	
	v1[4] = 42;
	lst.push_back(10);
	lst.push_back(15);
	lst.push_back(17);
	lst.push_back(13);
	lst.push_back(11);
	lst.push_back(42);

	if (easyfind(lst, 42) == 42)
		std::cout << "42 find in lst" << std::endl;
	if (easyfind(v1, 42) == 42)
		std::cout << "42 find in vector" << std::endl;
	if (easyfind(second, 42) == 42)
		std::cout << "42 find in set" << std::endl;
	try
	{
		if (easyfind(second, 12) == 42)
			std::cout << "42 find in set" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
