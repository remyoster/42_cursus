#include <iostream>
#include "Form.hpp"

Form::Form(void) : _signedGrade(1), _execGrade(1) {}

Form::Form(std::string str, unsigned int sign, unsigned int exec) : _name(str),
	_signedGrade(sign), _execGrade(exec), _isSigned(false)
{
	if (sign == 0 || exec == 0)
		throw(Form::GradeTooHighException());
	else if (sign > 150)
		throw(Form::GradeTooLowException(sign));
}

Form::Form(Form const &src) : _name(src.getName()),
	_signedGrade(src.getSignedGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
	return;
}

Form::~Form(void) {}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs) {
		this->_isSigned = rhs.isSigned();
	}
	return (*this);
}

std::string const Form::getName() const
{
	return (this->_name);
}

unsigned int Form::getSignedGrade() const
{
	return (this->_signedGrade);
}

unsigned int Form::getExecGrade() const
{
	return (this->_execGrade);
}

bool Form::isSigned() const
{
	return (this->_isSigned);
}

void Form::beSigned(Bureaucrat &bur)
{
	if (this->_signedGrade < bur.getGrade())
		throw(Form::GradeTooLowException(bur.getGrade()));
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << i.getName() << ", form need grade " << i.getSignedGrade() << " to be signed";
	o << " and " << i.getExecGrade() << " to be executed.";
	i.isSigned() ? o << " The form is signed." : o << " The form is unsigned.";
	return (o);
}

Form::GradeTooHighException::GradeTooHighException()
{
	this->err = "Grade(s) is(are) too high";
}

Form::GradeTooHighException::GradeTooHighException(long int nb)
{
	std::ostringstream s;
	s << "Grade \"" << nb << "\" is too high.";
	this->err = s.str();
}

const char * Form::GradeTooHighException::what() const throw()
{
	return (this->err.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::GradeTooLowException()
{
	this->err = "Grade(s) is(are) too low";
}

Form::GradeTooLowException::GradeTooLowException(long int nb)
{
	std::ostringstream s;
	s << "Grade \"" << nb << "\" is too low.";
	this->err = s.str();
}

const char * Form::GradeTooLowException::what() const throw()
{
	return (this->err.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}
