#include "Bureaucrat.hpp"

int	main() {
	try {
		Form formHigh("high", 0, 0);
	}
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form formLow("low", 200, 5);
	}
	catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat president("Macron", 1);
	Bureaucrat modernSlave("Roster", 130);

	Form form1("basic form", 140, 130);
	Form form2("pres form", 1, 1);
	Form form3("high form", 20, 15);

	std::cout<< form1 << std::endl;
	std::cout<< form2 << std::endl;
	std::cout<< form3 << std::endl;

	modernSlave.signForm(form1);
	modernSlave.signForm(form2);
	modernSlave.signForm(form3);

	std::cout<< form1 << std::endl;
	std::cout<< form2 << std::endl;
	std::cout<< form3 << std::endl;

	president.signForm(form2);
	president.signForm(form3);

	std::cout<< form2 << std::endl;
	std::cout<< form3 << std::endl;
}