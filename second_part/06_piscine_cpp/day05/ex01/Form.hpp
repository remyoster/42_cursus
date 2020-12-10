#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

public:
	Form(std::string str, unsigned int sign, unsigned int exec);
	Form(Form const &src);
	~Form(void);

	Form &operator=(Form const &rhs);

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(long int nb);
		~GradeTooLowException() throw();
		const char *what() const throw();
		std::string err;
	};

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(long int nb);
		~GradeTooHighException() throw();
		const char *what() const throw();
		std::string err;
	};

	std::string const getName() const;
	unsigned int getSignedGrade() const;
	unsigned int getExecGrade() const;
	bool isSigned() const;

	void beSigned(Bureaucrat &bur);

private:
	Form(void);
	std::string const _name;
	unsigned const int _signedGrade;
	unsigned const int _execGrade;
	bool _isSigned;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
