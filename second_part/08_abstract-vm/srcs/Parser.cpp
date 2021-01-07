#include "Parser.hpp"

Parser::Parser(void) : _tokens(NULL), _tIdx(0),
 _parenthesis(0), _exitEncounter(false) {}

Parser::Parser(int src, std::vector<Token *> *tokens)
	: _src(src), _tokens(tokens), _tIdx(0),
	_parenthesis(0), _exitEncounter(false) {}

Parser::Parser(Parser const &src) : _tokens(src.getTokens())
{
	*this = src;
}

Parser::~Parser(void) {}

Parser &Parser::operator=(Parser const &rhs)
{
	if (this != &rhs) {
		*this = rhs;
	}
	return (*this);
}

/*
** Loop through the tokens by calling _checkToken to handle syntax error. If an error
** is encountered, it is thrown and catch silently to be print later. If the syntax
** is good it returns 0
*/

int Parser::parse()
{
	std::exception_ptr eptr;
	try
	{
		while (this->_tIdx < this->_tokens->size())
		{
			if (this->_exitEncounter) {
				this->_tIdx = this->_tokens->size();
				throw (Error::InstructionAfterExit());
			}
			this->_checkToken((*this->_tokens)[this->_tIdx]);
			this->_tIdx += 1;
		}
		if (!this->_exitEncounter)
		{
			this->_exitEncounter = true;
			throw (Error::MissingExit());
		}
		return (this->_errTab.size() ? 1 : 0);
	}
	catch (...)
	{
		eptr = std::current_exception();
		this->_tIdx += 1;
	}
	this->_errTab.push_back(eptr);
	return (this->parse());
}


/*
** Switch case to handle different checker on the value of the token
*/

void Parser::_checkToken(Token *token)
{
	switch (token->getType())
	{
	case KEYWORD:
		this->_checkKeyword(token->getValue());
		break;
	case OPERAND:
		this->_checkOperand(token->getValue());
		break;
	case NUMBER:
		this->_checkNumber();
		break;
	case OPERATOR:
		if (this->_tIdx == 0) {
			if (token->getValue().compare("LPARENTHESIS") == 0)
				this->_parenthesis += 1;
			throw (Error::BadPlacement(token));
		}
		this->_checkOperator(token->getValue());
		break;
	default:
		throw (Error::UnknowExpressionType(token));
	}
}

/*
** Checks are performed on the next token (considering that the one before is always good)
*/

void Parser::_checkKeyword(std::string tVal)
{
	if (tVal.compare("EXIT") == 0)
		this->_exitEncounter = true;
	else if (tVal.compare("PUSH") == 0 || tVal.compare("ASSERT") == 0) {
		if (this->_tIdx + 1 == this->_tokens->size())
			throw (Error::BadPlacement((*this->_tokens)[this->_tIdx]));
		else if ((*this->_tokens)[this->_tIdx + 1]->getType() != OPERAND)
			throw (Error::InvalidOperand(
				(*this->_tokens)[this->_tIdx],
				(*this->_tokens)[this->_tIdx + 1]
				));
	}
}

void Parser::_checkNumber() {
	if (this->_tIdx == 0 || this->_tIdx + 1 == this->_tokens->size())
		throw (Error::BadPlacement((*this->_tokens)[this->_tIdx]));
	std::string tVal = (*this->_tokens)[this->_tIdx - 1]->getValue();
	if (tVal.compare("MINUS") != 0 && tVal.compare("LPARENTHESIS") != 0
		&& tVal.compare("DOT") != 0)
		throw (Error::BadPlacement((*this->_tokens)[this->_tIdx]));
	tVal = (*this->_tokens)[this->_tIdx + 1]->getValue();
	if (tVal.compare("DOT") != 0 && tVal.compare("RPARENTHESIS") != 0)
		throw (Error::BadPlacement((*this->_tokens)[this->_tIdx]));
}

/*
** Check the INT operand case to verify that the next token is a number (8|16|32)
** Notice that an operand must be followed by a '('
*/

void Parser::_checkOperand(std::string tVal)
{
	if (this->_tIdx == 0 || this->_tIdx + 1 == this->_tokens->size())
		throw (Error::BadPlacement((*this->_tokens)[this->_tIdx]));
	std::string tValNext;
	if (tVal.compare("INT") == 0)
	{
		tValNext = (*this->_tokens)[this->_tIdx + 1]->getValue();
		if (tValNext.compare("8") != 0 && tValNext.compare("16") != 0
			&& tValNext.compare("32") != 0)
			throw (Error::InvalidIntOperand((*this->_tokens)[this->_tIdx + 1]));
		this->_tIdx += 1;
		if (this->_tIdx + 1 == this->_tokens->size())
			throw (Error::BadPlacement((*this->_tokens)[this->_tIdx]));
	}
	tValNext = (*this->_tokens)[this->_tIdx + 1]->getValue();
	if (tValNext.compare("LPARENTHESIS") != 0)
		throw (Error::MissingParenthesis((*this->_tokens)[this->_tIdx + 1], '('));
}

/*
** Checks are performed on the next token except for the '.'
** - '.' : the dot is always between two numbers
** - '-' : always a number prefix
** - '(' : must be followed by a number
** - ')' : must decrement the parenthesis counter to 0
*/

void Parser::_checkOperator(std::string tVal)
{
	if (this->_tIdx + 1 == this->_tokens->size())
		throw (Error::BadPlacement((*this->_tokens)[this->_tIdx]));
	if (tVal.compare("MINUS") == 0)
	{
		if ((*this->_tokens)[this->_tIdx + 1]->getType() != NUMBER)
			throw (Error::InvalidMinusOperator((*this->_tokens)[this->_tIdx + 1]));
	}
	else if (tVal.compare("DOT") == 0
		&& ((*this->_tokens)[this->_tIdx + 1]->getType() != NUMBER
		|| (*this->_tokens)[this->_tIdx - 1]->getType() != NUMBER))
		throw (Error::InvalidDotOperator((*this->_tokens)[this->_tIdx + 1]));
	else if (tVal.compare("LPARENTHESIS") == 0) {
		this->_parenthesis += 1;
		this->_checkParenthesisContent();
	}
	else if (tVal.compare("RPARENTHESIS") == 0) {
		this->_parenthesis -= 1;
		if (this->_parenthesis < 0) {
			this->_parenthesis = 0;
			throw (Error::ExtraneousClosingParenthesis((*this->_tokens)[this->_tIdx]));
		}
	}
}

/*
** check if the token after the '(' is either a number, either '-'.
** Then if it's a number, it checks if it's a well formated number. At the end
** it checks if there is a ')' after the number. if everything goes right it
** decrement the parenthesis counter
*/

void Parser::_checkParenthesisContent() {
	bool isInt = (*this->_tokens)[this->_tIdx - 1]->getType() == NUMBER;
	Token *t = (*this->_tokens)[this->_tIdx + 1];
	if (t->getType() == OPERATOR && t->getValue().compare("MINUS") == 0) {
		this->_tIdx += 1;
		this->_checkOperator(t->getValue());
		this->_tIdx += 2;
	}
	else if (t->getType() != NUMBER)
		throw (Error::BadParenthesisContent(t));
	else
		this->_tIdx += 2;
	if (this->_tIdx == this->_tokens->size())
		throw (Error::BadPlacement((*this->_tokens)[this->_tIdx - 1]));
	t = (*this->_tokens)[this->_tIdx];
	if (t->getType() == OPERATOR && t->getValue().compare("DOT") == 0) {
		if (isInt)
			throw (Error::BadIntValue(t));
		this->_checkOperator(t->getValue());
		this->_tIdx += 2;
		t = (*this->_tokens)[this->_tIdx];
	}
	if (t->getType() != OPERATOR || t->getValue().compare("RPARENTHESIS") != 0) {
		this->_tIdx -= 1;
		throw (Error::MissingParenthesis((*this->_tokens)[this->_tIdx], ')'));
	}
	this->_parenthesis -= 1;
}

/*
** Should only be called when this->parse() return 0
** Delete parenthesis, merge '-' and '.' with numbers, merge operand with number
*/

void Parser::reduceTokens() {
	size_t idx = 0;
	std::string str;
	Token *t;

	while (idx < this->_tokens->size()) {
		t = (*this->_tokens)[idx];
		if (t->getType() == OPERAND && t->getValue().compare("INT") == 0) {
			t->setValue(t->getValue() += (*this->_tokens)[idx + 1]->getValue());
			this->_tokens->erase(this->_tokens->begin()+idx + 1);
		}
		if (t->getType() == OPERATOR && t->getValue().compare("LPARENTHESIS") == 0) {
			this->_tokens->erase(this->_tokens->begin()+idx);
			t = (*this->_tokens)[idx];
			if (t->getValue().compare("MINUS") == 0)
				t->setValue("-");
			while ((*this->_tokens)[idx + 1]->getValue().compare("RPARENTHESIS") != 0) {
				str = (*this->_tokens)[idx + 1]->getValue().compare("DOT") == 0 ? "." 
				: (*this->_tokens)[idx + 1]->getValue();
					t->setValue(t->getValue() += str);
					this->_tokens->erase(this->_tokens->begin() + idx + 1);
				}
			this->_tokens->erase(this->_tokens->begin() + idx + 1);
		}
		idx++;
	}
}

void	Parser::setSrc(int src) {
	if (src == FROM_FILE || src == FROM_STDIN)
		this->_src = src;
}

void	Parser::setTokens(std::vector<Token*> *tokens) {
	if (tokens)
		this->_tokens = tokens;
}


std::vector<Token *> * Parser::getTokens() const
{
	return (this->_tokens);
}

std::vector<std::exception_ptr> Parser::getErrors() const
{
	return (this->_errTab);
}