#include "Printer.hpp"

Printer::Printer(void) {}
Printer::~Printer(void) {}

/*
** Prints avm's usage
*/

void	Printer::usage() const {
	std::cout << "./avm [filename]" << std::endl;
	std::cout << "filname : if provided, read from the file, else read from stdin";
	std::cout << std::endl;
}

/*
** Iterate through the error array and call handle_eptr on each
*/

void Printer::error(std::vector<std::exception_ptr> err) const {
	std::vector<std::exception_ptr>::iterator it;
	for (it = err.begin(); it != err.end(); ++it)
		this->handle_eptr(*it);
}

/*
** Rethrow an exception by the ptr and catch it
** Using std::exception is mandatory
*/

void Printer::handle_eptr(std::exception_ptr eptr) const
{
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    }
	catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}