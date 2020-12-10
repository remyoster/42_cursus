#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{

public:
	RobotomyRequestForm(std::string str);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	virtual ~RobotomyRequestForm(void);

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	class GradeTooLowException : public Form::GradeTooLowException
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public Form::GradeTooHighException
	{
		public:
			virtual const char *what() const throw();
	};

	class NotSignedException : public Form::NotSignedException
	{
		public:
			virtual const char *what() const throw();
	};

	void action() const;

private:
	RobotomyRequestForm();
};

#endif
