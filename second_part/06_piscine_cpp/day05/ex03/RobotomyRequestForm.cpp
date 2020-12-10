#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string str)
	: Form ("RobotomyRequestForm", 72, 45) {
	this->setTarget(str);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this != &rhs) {
		this->setIsSigned(rhs.getIsSigned());
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

void	RobotomyRequestForm::action() const {
	size_t random = 1 + std::rand()/((RAND_MAX + 1u)/6);
	if (random == 6) {
		std::cout << "* make drill noises *" << std::endl;
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	}
	else
		std::cout << "* does nothing... *" << std::endl;
}
