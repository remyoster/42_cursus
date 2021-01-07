#include <iostream>
#include "Token.hpp"

Token::Token(void) {}

Token::Token(t_type type, std::string str, size_t pos, size_t line) : 
	_type(type), _val(str), _rVal(str), _pos(pos), _line(line) {
}

Token::Token(t_type type, std::string str, std::string rval, size_t pos, size_t line) : 
	_type(type), _val(str), _rVal(rval), _pos(pos), _line(line) {
}

Token::Token(Token const & src) {
	*this = src;
}

Token::~Token(void) {}

Token &	Token::operator=(Token const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

t_type Token::getType() const {
	return (this->_type);
}

std::string Token::getValue() const {
	return (this->_val);
}

std::string Token::getRValue() const {
	return (this->_rVal);
}

size_t Token::getPos() const {
	return (this->_pos);
}

size_t Token::getLine() const {
	return (this->_line);
}

void	Token::setValue(std::string val) {
	this->_val = val;
}