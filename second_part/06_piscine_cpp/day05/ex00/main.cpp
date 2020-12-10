#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat president("Macron", 1);
		Bureaucrat modernSlave("DFfsdgsdg", 150);

		std::cout << president << std::endl;
		std::cout << modernSlave << std::endl;

		president.degrade();
		modernSlave.upgrade();

		std::cout << president << std::endl;
		std::cout << modernSlave << std::endl;

		modernSlave = president;
		std::cout << modernSlave << std::endl;
		Bureaucrat test2("Dsds", 157);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat test3("Dsds", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat president("Macron", 1);
		president.upgrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat president("tsst", 150);
		president.degrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
