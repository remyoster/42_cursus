#include <iostream>
#include "Fixed.class.hpp"
#include <cmath>

const int	Fixed::_fractionnal = 8;

Fixed::Fixed(void) : _val(0) {
	std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed(const int n) {
	this->_val = n * (1 << Fixed::_fractionnal);

	return ;
}

Fixed::Fixed(const float f) {
	this->_val = roundf(f * (1 << Fixed::_fractionnal));
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
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_val / (1 << Fixed::_fractionnal));

}

int		Fixed::toInt(void) const {
	return (this->_val / (1 << Fixed::_fractionnal));
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
