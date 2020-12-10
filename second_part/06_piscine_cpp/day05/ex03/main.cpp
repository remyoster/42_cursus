#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat president("Macron", 1);
	Intern someRandomIntern;
	Form *form;

	try
	{
		form = someRandomIntern.makeForm("shrubbery creation", "tree");
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		form = someRandomIntern.makeForm("presidential pardon", "Roster");
		president.signForm(*form);
		president.executeForm(*form);
		form = someRandomIntern.makeForm("caf request", "Roster");
	}
	catch (Intern::UnknownFormException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
