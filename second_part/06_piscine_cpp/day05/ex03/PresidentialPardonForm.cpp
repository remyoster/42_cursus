#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string str)
	: Form ("PresidentialPardonForm", 25, 5) {
	this->setTarget(str);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs) {
		this->setIsSigned(rhs.getIsSigned());
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

void	PresidentialPardonForm::action() const {
	std::cout << this->getTarget();
	std::cout << " has been forgiven by Zafod Beeblebrox." << std::endl;
}
