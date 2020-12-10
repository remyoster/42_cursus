#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main() {
	std::srand(std::time(NULL));
	Bureaucrat president("Macron", 1);
	Bureaucrat cadre("Jean", 70);
	Bureaucrat pdg("Lise", 35);
	Bureaucrat modernSlave("Roster", 150);

	ShrubberyCreationForm form1("tree");
	RobotomyRequestForm form2("victim");
	PresidentialPardonForm form3("Roster");

	modernSlave.signForm(form1);
	modernSlave.executeForm(form1);

	cadre.signForm(form1);
	cadre.executeForm(form1);

	cadre.signForm(form2);
	cadre.executeForm(form2);

	pdg.executeForm(form2);
	pdg.executeForm(form2);
	pdg.executeForm(form2);
	pdg.executeForm(form2);

	pdg.signForm(form3);
	pdg.executeForm(form3);

	president.signForm(form3);
	president.executeForm(form3);
}