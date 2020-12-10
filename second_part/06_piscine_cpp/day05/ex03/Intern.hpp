#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "Form.hpp"

class Intern {

public:

	Intern(void);
	Intern(Intern const & src);
	~Intern(void);

	class UnknownFormException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	Intern &	operator=(Intern const & rhs);

	Form *makeForm(std::string formName, std::string target);
	Form *makeShrubberyForm(std::string target);
	Form *makeRobotomyForm(std::string target);
	Form *makePresidentialForm(std::string target);


private:

};

std::ostream &	operator<<(std::ostream & o, Intern const & i);

#endif
