#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(std::string str, unsigned int sign, unsigned int exec);
	Form(Form const &src);
	virtual ~Form() {};

	Form &operator=(Form const &rhs);

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	std::string const getName() const;
	unsigned int getSignedGrade() const;
	unsigned int getExecGrade() const;
	std::string		getTarget() const;
	bool			getIsSigned() const;
	void			beSigned(Bureaucrat const & bur);
	void			execute(Bureaucrat const & executor) const;
	virtual void			action() const = 0;

	void	setIsSigned(bool);
	void	setTarget(std::string);

private:
	std::string const	_name;
	unsigned const int	_signedGrade;
	unsigned const int	_execGrade;
	bool				_isSigned;
	std::string			_target;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
