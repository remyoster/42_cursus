#include <iostream>
#include "Form.hpp"

Form::Form(void) : _name(""), _signedGrade(150), _execGrade(150), _isSigned(false) {}

Form::Form(std::string str, unsigned int sign, unsigned int exec) : _name(str),
	_signedGrade(sign), _execGrade(exec), _isSigned(false)
{
	if (sign == 0 || exec == 0)
		throw(Form::GradeTooHighException());
	else if (sign > 150)
		throw(Form::GradeTooLowException());
}

Form::Form(Form const &src) : _name(src.getName()),
	_signedGrade(src.getSignedGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs) {
		this->_isSigned = rhs.getIsSigned();
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

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

std::string Form::getTarget() const {
	return (this->_target);
}

void Form::setIsSigned(bool bol) {
	this->_isSigned = bol;
}

void Form::setTarget(std::string str) {
	this->_target = str;
}

void	Form::beSigned(Bureaucrat const & bur) {
	if (this->getSignedGrade() < bur.getGrade())
		throw (Form::GradeTooLowException());
	else
		this->setIsSigned(true);
}

void	Form::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned())
		throw (Form::NotSignedException());
	else if (this->getExecGrade() < executor.getGrade())
		throw (Form::GradeTooLowException());
	else
		this->action();
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << i.getName() << ", form need grade " << i.getSignedGrade() << " to be signed";
	o << " and " << i.getExecGrade() << " to be executed.";
	i.getIsSigned() ? o << " The form is signed." : o << " The form is unsigned.";
	return (o);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade(s) is(are) too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade(s) is(are) too low");
}

const char *Form::NotSignedException::what() const throw() {
	return ("The form is unsigned");
}
