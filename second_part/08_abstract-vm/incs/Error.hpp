#ifndef ERROR_H
# define ERROR_H

# include <Token.hpp>
# include "IOperand.hpp"
# include "SyntaxError.hpp"
# include "LogicError.hpp"

class Error {

public:
	class UnknowExpressionType : public SyntaxError
	{
		public:
			UnknowExpressionType(Token* token);
	};

	class InvalidOperand : public SyntaxError
	{
		public:
			InvalidOperand(Token* token, Token* token2);
	};

	class InvalidIntOperand : public SyntaxError
	{
		public:
			InvalidIntOperand(Token* token);
	};

	class InvalidMinusOperator : public SyntaxError
	{
		public:
			InvalidMinusOperator(Token* token);
	};

	class InvalidDotOperator : public SyntaxError
	{
		public:
			InvalidDotOperator(Token* token);
	};

	class MissingParenthesis : public SyntaxError
	{
		public:
			MissingParenthesis(Token* token, char c);
	};

	class ExtraneousClosingParenthesis : public SyntaxError
	{
		public:
			ExtraneousClosingParenthesis(Token* token);
	};

	class BadParenthesisContent : public SyntaxError
	{
		public:
			BadParenthesisContent(Token* token);
	};

	class BadIntValue : public SyntaxError
	{
		public:
			BadIntValue(Token* token);
	};

	class BadPlacement : public SyntaxError
	{
		public:
			BadPlacement(Token* token);
	};

	class MissingExit : public SyntaxError
	{
		public:
			MissingExit(void);
	};

	class InstructionAfterExit : public SyntaxError
	{
		public:
			InstructionAfterExit(void);
	};



	class Underflow : public LogicError
	{
		public:
			Underflow(eOperandType e, std::string value);
	};

	class Overflow : public LogicError
	{
		public:
			Overflow(eOperandType e, std::string value);
	};

	class AssertIsNotTrue : public LogicError
	{
		public:
			AssertIsNotTrue(Token *token, IOperand const *op, IOperand const *opStack);
	};

	class StackIsEmpty : public LogicError
	{
		public:
			StackIsEmpty(Token* token);
	};

	class StackSize : public LogicError
	{
		public:
			StackSize(Token* token);
	};

	class DivisorEqualToZero : public LogicError
	{
		public:
			DivisorEqualToZero(Token* token);
	};

	class Print : public LogicError
	{
		public:
			Print(Token *token, IOperand const *op);
	};

};

#endif
