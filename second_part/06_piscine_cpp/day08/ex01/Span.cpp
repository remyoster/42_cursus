#include <algorithm>
#include "Span.hpp"

Span::Span(void) {}
Span::Span(unsigned int n) : _size(n) {}

Span::Span(int min, int max) { 
	if (min > max)
		throw std::invalid_argument("First arg must be < to second");
	this->_size = max - min + 1;
	for (int i=min; i <= max;i++)
		this->_arr.push_back(i);
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span(void) {}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs) {
		this->_size = rhs.getSize();
		this->_arr = rhs.getArray();
	}
	return (*this);
}

int Span::addNumber(int n)
{
	if (this->_arr.size() < this->_size)
		this->_arr.push_back(n);
	else
		throw std::length_error("Span can't accept more numbers.");
	return (0);
}

int Span::shortestSpan(void) const
{
	std::vector<int> tmp(this->_arr);
	if (this->_arr.size() <= 1)
		throw std::length_error("Span contains not enough numbers");
	std::sort(tmp.begin(), tmp.end());
	int shortest = tmp[1] - tmp[0];
	for (size_t idx = 0; idx + 1 < this->_arr.size(); idx++)
		if (tmp[idx + 1] - tmp[idx] < shortest)
			shortest = tmp[idx + 1] - tmp[idx];
	return (shortest);
}

int Span::longestSpan(void) const
{
	if (this->_arr.size() <= 1)
		throw std::length_error("Span contains not enough numbers");
	int min = *std::min_element(this->_arr.begin(), this->_arr.end());
	int max = *std::max_element(this->_arr.begin(), this->_arr.end());
	return (max - min);
}

unsigned int Span::getSize() const {
	return (this->_size);
}

std::vector<int> Span::getArray() const {
	return (this->_arr);
}