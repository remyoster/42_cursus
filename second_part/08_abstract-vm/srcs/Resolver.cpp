#include "Resolver.hpp"

Resolver::Resolver(void) : _tokens(NULL), _tIdx(0) {}

Resolver::Resolver(std::vector<Token *> *tokens) : _tokens(tokens), _tIdx(0) {}

Resolver::Resolver(Resolver const &src)
{
	*this = src;
}

/*
** Free and clear the stack
*/

Resolver::~Resolver(void)
{
	for (auto rit = this->_stack.crbegin(); rit != this->_stack.crend(); ++rit)
		delete *rit;
	this->_stack.clear();
}

Resolver &Resolver::operator=(Resolver const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

/*
** Run is going to loop trough tokens in recurse mode to throw exception. It loops
** to _tokens->size() - 1 because the last one is EXIT
*/

int Resolver::run()
{
	std::exception_ptr eptr;
	try
	{
		while (this->_tIdx < this->_tokens->size() - 1)
		{
			if ((*this->_tokens)[this->_tIdx]->getType() == KEYWORD)
				this->_runInstruction((*this->_tokens)[this->_tIdx]);
			this->_tIdx += 1;
		}
		return (this->_errTab.size() ? 1 : 0);
	}
	catch (...)
	{
		eptr = std::current_exception();
		this->_tIdx += 1;
	}
	this->_errTab.push_back(eptr);
	return (this->run());
}

/*
** Call basic instruction functions
*/

void Resolver::_runInstruction(Token *token)
{
	const std::string keywords[] = {
		"PUSH",
		"POP",
		"DUMP",
		"ASSERT",
		"PRINT"
	};
	void (Resolver::*func[])(void) = {
		&Resolver::_push,
		&Resolver::_pop,
		&Resolver::_dump,
		&Resolver::_assert,
		&Resolver::_print
	};
	for (size_t idx = 0; idx < 5; idx++)
		if (keywords[idx].compare(token->getValue()) == 0)
			return ((this->*func[idx])());
	this->_runArithmetics(token);
}

/*
** Call arithmetic functions
*/

void Resolver::_runArithmetics(Token *token) {
	const std::string keywords[] = {
		"ADD",
		"SUB",
		"MUL",
		"DIV",
		"MOD",
	};
	void (Resolver::*func[])(IOperand const *, IOperand const *) = {
		&Resolver::_add,
		&Resolver::_sub,
		&Resolver::_mul,
		&Resolver::_div,
		&Resolver::_mod,
	};
	if (this->_stack.size() < 2)
		throw (Error::StackSize(token));
	IOperand const *op1 = this->_stack.back();
	this->_stack.pop_back();
	IOperand const *op2 = this->_stack.back();
	this->_stack.pop_back();
	try
	{
		for (size_t idx = 0; idx < 5; idx++)
			if (keywords[idx].compare(token->getValue()) == 0)
				(this->*func[idx])(op1, op2);
		delete op1;
		delete op2;
	}
	catch (...) {
		delete op1;
		delete op2;
		throw;
	}
}

/*
** Stack the value pointed to by operand(number)
*/

void Resolver::_push()
{
	IOperand const *op = this->_factory.createOperand(
		this->_valueToOperand((*this->_tokens)[this->_tIdx + 1]->getValue()),
		(*this->_tokens)[this->_tIdx + 2]->getValue());
	this->_stack.push_back(op);
}

/*
** pop the top stack operand
*/

void Resolver::_pop()
{
	if (this->_stack.empty()) {
		throw (Error::StackIsEmpty((*this->_tokens)[this->_tIdx]));
	}
	delete this->_stack.back();
	this->_stack.pop_back();
}

/*
** Prints each IOperand with std::cout and default parameters (precision == 6)
** and cut 0 if there are some at the end
*/

void Resolver::_dump()
{
	std::string tmp;
	for (auto rit = this->_stack.crbegin(); rit != this->_stack.crend(); ++rit) {
		tmp = (*rit)->toString();
		if ((*rit)->getType() == Float || (*rit)->getType() == Double) {
		for (auto rit = tmp.rbegin(); rit != tmp.rend(); ++rit)
			if ((*rit) == '0' && tmp[tmp.length() - 2] != '.')
				tmp.pop_back();
			else
				break;
		}
		std::cout << tmp << std::endl;
	}
}

/*
** assert that the value passed in operand(number) is equal to the top stack val
*/

void Resolver::_assert()
{
	if (this->_stack.empty()) {
		throw (Error::StackIsEmpty((*this->_tokens)[this->_tIdx]));
	}
	IOperand const *op = this->_factory.createOperand(
		this->_valueToOperand((*this->_tokens)[this->_tIdx + 1]->getValue()),
		(*this->_tokens)[this->_tIdx + 2]->getValue());
	IOperand const *opStack = this->_stack.back();
	if (opStack->toString().compare(op->toString()) != 0)
		throw (Error::AssertIsNotTrue((*this->_tokens)[this->_tIdx], op, opStack));
	delete op;
}

/*
** Arithmetic functions (+,-,/,*,%) with top stack val as the second operator
*/

void Resolver::_add(IOperand const *op1, IOperand const *op2)
{
	this->_stack.push_back(*op2 + *op1);
}
void Resolver::_sub(IOperand const *op1, IOperand const *op2)
{
	this->_stack.push_back(*op2 - *op1);
}
void Resolver::_mul(IOperand const *op1, IOperand const *op2)
{
	this->_stack.push_back(*op2 * *op1);
}
void Resolver::_div(IOperand const *op1, IOperand const *op2)
{
	if (atof(op1->toString().c_str()) == 0) {
		throw (Error::DivisorEqualToZero((*this->_tokens)[this->_tIdx]));
	}
	this->_stack.push_back(*op2 / *op1);
}
void Resolver::_mod(IOperand const *op1, IOperand const *op2)
{
	if (atof(op1->toString().c_str()) == 0) {
		throw (Error::DivisorEqualToZero((*this->_tokens)[this->_tIdx]));
	}
	this->_stack.push_back(*op2 % *op1);
}

/*
** Assert that the value on top of the stack is int8 and print it as a char.
** If the value is not printable, just print the value as an int
*/

void Resolver::_print()
{
	if (this->_stack.empty()) {
		throw (Error::StackIsEmpty((*this->_tokens)[this->_tIdx]));
	}
	IOperand const *op = this->_stack.back();
	if (op->getType() != Int8) {
		throw (Error::Print((*this->_tokens)[this->_tIdx], op));
	}
	int val = atoi(op->toString().c_str());
	if (isprint(val))
		std::cout << static_cast<char>(val);
	else
		std::cout << val;
}

void Resolver::setTokens(std::vector<Token *> *tokens)
{
	if (tokens)
		this->_tokens = tokens;
}

std::vector<Token *> *Resolver::getTokens() const
{
	return (this->_tokens);
}

std::vector<std::exception_ptr> Resolver::getErrors() const
{
	return (this->_errTab);
}

/*
** use a map to return te eOperandType based on std::string
*/

eOperandType Resolver::_valueToOperand(std::string val) const
{
	static const std::map<std::string, eOperandType> vTo = {
		{"INT8", Int8},
		{"INT16", Int16},
		{"INT32", Int32},
		{"FLOAT", Float},
		{"DOUBLE", Double},
	};
	std::map<std::string, eOperandType>::const_iterator it = vTo.find(val);
	return (it->second);
}