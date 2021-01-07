#include "Error.hpp"

Error::UnknowExpressionType::UnknowExpressionType(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "unknown expression '" << token->getRValue() << "'";
	this->_err = this->_oss.str();
}

Error::InvalidOperand::InvalidOperand(Token *token, Token *token2) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << token->getRValue() << " only accept operand (int8|16|32, float, double)";
	this->_oss << " Receive : '" << token2->getRValue() << "'";
	this->_err = this->_oss.str();
}

Error::InvalidIntOperand::InvalidIntOperand(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "only int8|16|32 are accepted";
	this->_oss << " Receive : 'int" << token->getRValue() << "'";
	this->_err = this->_oss.str();
}

Error::InvalidMinusOperator::InvalidMinusOperator(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "'-' can only be a number prefix";
	this->_oss << " Receive : '-" << token->getRValue() << "'";
	this->_err = this->_oss.str();
}

Error::InvalidDotOperator::InvalidDotOperator(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "'.' can only be a number prefix.";
	this->_oss << " Receive : '." << token->getRValue() << "'";
	this->_err = this->_oss.str();
}

Error::BadParenthesisContent::BadParenthesisContent(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "only one number can be inside parenthesis";
	this->_err = this->_oss.str();
}

Error::BadIntValue::BadIntValue(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "operand int only accept a entire number";
	this->_err = this->_oss.str();
}

Error::ExtraneousClosingParenthesis::ExtraneousClosingParenthesis(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "remove extraneous closing parenthesis ')'";
	this->_err = this->_oss.str();
}

Error::MissingParenthesis::MissingParenthesis(Token *token, char c) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "missing parenthesis '" << c << "'";
	this->_oss << (c == '(' ? " before '" : " after '") << token->getRValue() << "'";
	this->_err = this->_oss.str();
}

Error::BadPlacement::BadPlacement(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "bad placement; '" << token->getRValue();
	this->_oss << "' must follow or by followed by a valid expression";
	this->_err = this->_oss.str();
}

Error::MissingExit::MissingExit()
{
	this->_oss << this->_mess << "missing 'exit' instruction at the end";
	this->_err = this->_oss.str();
}

Error::InstructionAfterExit::InstructionAfterExit()
{
	this->_oss << this->_mess << "one or more instructions after 'exit' are present.";
	this->_oss << " Remove them or put your 'exit' instruction at the end";
	this->_err = this->_oss.str();
}

Error::Underflow::Underflow(eOperandType e, std::string value) {
	const std::string type[] = {
		"int8",
		"int16",
		"int32",
		"float",
		"double"
	};
	this->_oss << this->_mess << "underflow on type '" << type[e];
	this->_oss << "' with value : '" << value << "'";
	this->_err = this->_oss.str();
}

Error::Overflow::Overflow(eOperandType e, std::string value) {
	const std::string type[] = {
		"int8",
		"int16",
		"int32",
		"float",
		"double"
	};
	this->_oss << this->_mess << "overflow on type '" << type[e];
	this->_oss << "' with value : '" << value << "'";
	this->_err = this->_oss.str();
}

Error::AssertIsNotTrue::AssertIsNotTrue(Token *token, IOperand const *op, IOperand const *opStack) {
	const std::string type[] = {
		"int8",
		"int16",
		"int32",
		"float",
		"double"
	};
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "assert is not true. '";
	this->_oss << type[op->getType()] << "(" << op->toString() << ")' can't be equal to '";
	this->_oss << type[opStack->getType()] << "(" << opStack->toString() << ")'";
	this->_err = this->_oss.str();
	delete op;
}

Error::StackIsEmpty::StackIsEmpty(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "can't '" << token->getRValue() << "' on empty stack";
	this->_err = this->_oss.str();
}

Error::StackSize::StackSize(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "can't '" << token->getRValue() << "'. Not enough numbers stacked";
	this->_err = this->_oss.str();
}

Error::Print::Print(Token *token, IOperand const *op) {
	const std::string type[] = {
		"int16",
		"int32",
		"float",
		"double"
	};
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "print can only be called on int8 value. Receive '";
	this->_oss << type[op->getType() - 1] << "(" << op->toString() << ")'";
	this->_err = this->_oss.str();
}

Error::DivisorEqualToZero::DivisorEqualToZero(Token *token) {
	this->_oss << token->getLine() << ":" << token->getPos() << ": ";
	this->_oss << this->_mess << "can't '" << token->getRValue() << "' by 0";
	this->_err = this->_oss.str();
}
