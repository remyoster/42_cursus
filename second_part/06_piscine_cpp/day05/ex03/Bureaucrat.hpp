#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <stdexcept>
# include <sstream>
# include "Form.hpp"

class Form;

class Bureaucrat
{

public:
	Bureaucrat(std::string str, unsigned int nb);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat &operator=(Bureaucrat const &rhs);


	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException();
			GradeTooLowException(long int nb);
			~GradeTooLowException() throw();
			const char* what() const throw();
			std::string err;
	};

	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException();
			GradeTooHighException(long int nb);
			~GradeTooHighException() throw();
			const char* what() const throw();
			std::string err;
	};

	std::string const getName() const;
	unsigned int getGrade() const;

	void signForm(Form & form);
	void executeForm (Form const & form);
	void upgrade();
	void degrade();

private:
	Bureaucrat(void);

	std::string const _name;
	unsigned int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
