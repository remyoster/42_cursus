#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{

public:
	ShrubberyCreationForm(std::string str);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	virtual ~ShrubberyCreationForm(void);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

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
	ShrubberyCreationForm();
};

#endif
