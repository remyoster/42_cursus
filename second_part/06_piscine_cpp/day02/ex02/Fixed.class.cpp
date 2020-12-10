#include <iostream>
#include "Fixed.class.hpp"
#include <cmath>

const int	Fixed::_fractionnal = 8;

Fixed::Fixed(void) : _val(0) {
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
	*this = src;
	return ;
}

Fixed::~Fixed(void) {
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return (*this);
}

Fixed  Fixed::operator+(Fixed const & rhs) const {
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (tmp);
}

Fixed  Fixed::operator-(Fixed const & rhs) const {
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(Fixed const & rhs) const {
	Fixed tmp;
	tmp.setRawBits(roundf(this->getRawBits() * rhs.getRawBits()) / (1 << Fixed::_fractionnal));
	return (tmp);
}

Fixed  Fixed::operator/(Fixed const & rhs) const {
	Fixed tmp(this->_val / rhs.getRawBits());
	return (tmp);
}

Fixed  Fixed::operator++(void) {
	this->_val += 1;
	return (*this);
}
Fixed  Fixed::operator--(void) {
	this->_val -= 1;
	return (*this);
}
Fixed  Fixed::operator++(int) {
	Fixed tmp = Fixed(*this);
	this->_val += 1;
	return (tmp);
}

Fixed  Fixed::operator--(int) {
	Fixed tmp = Fixed(*this);
	this->_val -= 1;
	return (tmp);
}

bool	Fixed::operator>(Fixed const & rhs) {
		return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) {
		return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) {
		return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) {
		return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) {
		return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) {
		return (this->getRawBits() != rhs.getRawBits());
}

int	Fixed::getRawBits(void) const {
	return (this->_val);
}

void	Fixed::setRawBits(int const raw) {
	this->_val = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_val / (1 << Fixed::_fractionnal));

}

int		Fixed::toInt(void) const {
	return (this->_val / (1 << Fixed::_fractionnal));
}

Fixed const & Fixed::min(Fixed const & rhs1, Fixed const & rhs2) {
	if (rhs1.toFloat() < rhs2.toFloat())
		return (rhs1);
	return (rhs2);
}

Fixed & Fixed::min(Fixed & rhs1, Fixed & rhs2) {
	if (rhs1 < rhs2)
		return (rhs1);
	return (rhs2);
}

Fixed const & Fixed::max(Fixed const & rhs1, Fixed const & rhs2) {
	if (rhs1.toFloat() > rhs2.toFloat())
		return (rhs1);
	return (rhs2);
}

Fixed & Fixed::max(Fixed & rhs1, Fixed & rhs2) {
	if (rhs1 > rhs2)
		return (rhs1);
	return (rhs2);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
