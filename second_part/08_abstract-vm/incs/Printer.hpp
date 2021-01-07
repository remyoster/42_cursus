#ifndef PRINTER_H
# define PRINTER_H

# include <iostream>
# include <exception>
# include <stdexcept>
# include <vector>
# include "SyntaxError.hpp"

class Printer {

public:

	Printer(void);
	~Printer(void);

	void usage() const;
	void error(std::vector<std::exception_ptr> err) const;

private:
	void handle_eptr(std::exception_ptr eptr) const;
};


#endif
