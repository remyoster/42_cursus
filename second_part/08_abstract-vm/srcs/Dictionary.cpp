#include "Dictionary.hpp"

Dictionary::Dictionary(void)
{
	this->_keywords["push"] = "PUSH";
	this->_keywords["pop"] = "POP";
	this->_keywords["dump"] = "DUMP";
	this->_keywords["assert"] = "ASSERT";
	this->_keywords["add"] = "ADD";
	this->_keywords["sub"] = "SUB";
	this->_keywords["mul"] = "MUL";
	this->_keywords["div"] = "DIV";
	this->_keywords["mod"] = "MOD";
	this->_keywords["print"] = "PRINT";
	this->_keywords["exit"] = "EXIT";

	this->_operands["int"] = "INT";
	this->_operands["int8"] = "INT8";
	this->_operands["int16"] = "INT16";
	this->_operands["int32"] = "INT32";
	this->_operands["float"] = "FLOAT";
	this->_operands["double"] = "DOUBLE";

	this->_operators["-"] = "MINUS";
	this->_operators["."] = "DOT";
	this->_operators["("] = "LPARENTHESIS";
	this->_operators[")"] = "RPARENTHESIS";

	this->_dico[KEYWORD] = this->_keywords;
	this->_dico[OPERAND] = this->_operands;
	this->_dico[OPERATOR] = this->_operators;
}

Dictionary::Dictionary(Dictionary const &src)
{
	*this = src;
}

Dictionary::~Dictionary(void) {}

Dictionary &Dictionary::operator=(Dictionary const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

std::map<std::string, std::string> Dictionary::getKeywords() const
{
	return (this->_keywords);
}
std::map<std::string, std::string> Dictionary::getOperands() const
{
	return (this->_operands);
}
std::map<std::string, std::string> Dictionary::getOperators() const
{
	return (this->_operators);
}
std::map<t_type, std::map<std::string, std::string>> Dictionary::getDico() const {
	return (this->_dico);
}