#include <iostream>
#include "Fixed.class.hpp"

const int	Fixed::_fractionnal = 8;

Fixed::Fixed(void) : _val(0) {
	std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;

	*this = src;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;

	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_val = rhs.getRawBits();

	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_val);
}

void	Fixed::setRawBits(int const raw) {
	this->_val = raw;
	return ;
}
