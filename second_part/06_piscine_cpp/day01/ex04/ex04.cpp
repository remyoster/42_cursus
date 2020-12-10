#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *sPtr = &str;
	std::string &sRef = str;

	std::cout << *sPtr << std::endl;
	std::cout << sRef << std::endl;

	str = "HI THIS IS HUMAN";
	
	std::cout << *sPtr << std::endl;
	std::cout << sRef << std::endl;
}