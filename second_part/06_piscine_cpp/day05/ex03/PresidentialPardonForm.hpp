#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{

public:
	PresidentialPardonForm(std::string str);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	void action() const;

private:
	PresidentialPardonForm();
};

#endif
