#ifndef RESOLVER_H
# define RESOLVER_H

# include <iostream>
# include <vector>
# include <list>
# include <map>
# include "Error.hpp"
# include "Token.hpp"
# include "IOperand.hpp"
# include "Factory.hpp"

class Resolver {

public:

	Resolver(void);
	Resolver(std::vector<Token*> *tokens);
	Resolver(Resolver const & src);
	~Resolver(void);

	Resolver &	operator=(Resolver const & rhs);

	int run(void);

	void	setTokens(std::vector<Token*> *tokens);

	std::vector<Token*> *getTokens() const;
	std::vector<std::exception_ptr> getErrors() const;

private:
	std::vector<std::exception_ptr>	_errTab;
	std::vector<Token*>				*_tokens;
	std::list<IOperand const*>		_stack;
	size_t							_tIdx;
	Factory							_factory;

	void	_runInstruction(Token *token);
	void	_runArithmetics(Token *token);
	void	_push();
	void	_pop();
	void	_dump();
	void	_assert();
	void	_add(IOperand const *op1, IOperand const *op2);
	void	_sub(IOperand const *op1, IOperand const *op2);
	void	_mul(IOperand const *op1, IOperand const *op2);
	void	_div(IOperand const *op1, IOperand const *op2);
	void	_mod(IOperand const *op1, IOperand const *op2);
	void	_print();

	eOperandType _valueToOperand(std::string) const;

};

#endif
