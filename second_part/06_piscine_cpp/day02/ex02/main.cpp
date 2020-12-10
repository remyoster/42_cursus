#include <iostream>
#include "Fixed.class.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << a + b << std::endl;
	std::cout << b / a << std::endl;
	std::cout << a - b << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	a = b * Fixed(2);
	c = Fixed::min(a, b);
	std::cout << c << std::endl;
	c = Fixed::max(a, b);
	std::cout << c << std::endl;

	
	return 0;
}