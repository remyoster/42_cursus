#ifndef BASEERROR_H
# define BASEERROR_H

# include <iostream>
# include <sstream>

class BaseError : public std::exception {

public:

	BaseError(void);
	BaseError(const char *str);
	BaseError(BaseError const & src);
	~BaseError(void);

	BaseError &	operator=(BaseError const & rhs);

	const char *what() const throw();

protected:
		std::string _err;
		std::ostringstream _oss;
		const char *_mess;
};

#endif
