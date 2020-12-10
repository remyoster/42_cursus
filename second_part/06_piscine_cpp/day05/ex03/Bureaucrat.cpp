#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string str, unsigned int nb) : _name(str)
{
	if (nb >= 1 && nb <= 150)
		this->_grade = nb;
	else if (nb == 0)
		throw(Bureaucrat::GradeTooHighException(nb));
	else
		throw(Bureaucrat::GradeTooLowException(nb));
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName())
{
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{

	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

void	Bureaucrat::signForm(Form & form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << this->_name << " can't sign " << form.getName();
		std::cout << " because his grade is too low" << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form) {
	try {
		std::cout << this->_name << " executs " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch (Form::NotSignedException & e) {
		std::cout << this->_name << " can't execute " << form.getName();
		std::cout << " because : " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << this->_name << " can't sign " << form.getName();
		std::cout << " because : " << e.what() << std::endl;
	}
}

std::string const Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::upgrade()
{
	if (this->_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException(0));
	this->_grade -= 1;
}

void Bureaucrat::degrade()
{
	if (this->_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException(151));
	this->_grade += 1;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	this->err = "Grade is too high";
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(long int nb)
{
	std::ostringstream s;
	s << "Grade \"" << nb << "\" is too high.";
	this->err = s.str();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (this->err.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	this->err = "Grade is too low";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(long int nb)
{
	std::ostringstream s;
	s << "Grade \"" << nb << "\" is too low.";
	this->err = s.str();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (this->err.c_str());
}