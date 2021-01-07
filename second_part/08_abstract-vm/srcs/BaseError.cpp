#include "BaseError.hpp"

BaseError::BaseError(void) : _mess("error: ") {}
BaseError::BaseError(const char *str) : _mess(str) {}

BaseError::BaseError(BaseError const & src) {
	*this = src;
}

BaseError::~BaseError(void) {}

BaseError &	BaseError::operator=(BaseError const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

const char* BaseError::what() const throw() {
	return (this->_err.c_str());
}
