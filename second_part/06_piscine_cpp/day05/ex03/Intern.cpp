#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern(void) {}

Intern &Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

Form *Intern::makeRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::makePresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	Form *(Intern::*func[])(std::string) = {
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm,
		&Intern::makeShrubberyForm
	};
	size_t idx = 0;
	Form *form;

	while (idx < 3)
	{
		if (forms[idx].compare(formName) == 0)
		{
			form = (this->*func[idx])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
		idx++;
	}
	throw Intern::UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("This form doesn't exist");
}

std::ostream &operator<<(std::ostream &o, Intern const &i)
{
	(void)i;
	o << "I'm a intern and i just make form";
	return (o);
}
