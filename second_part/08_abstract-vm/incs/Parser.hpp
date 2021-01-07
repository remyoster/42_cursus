#ifndef PARSER_H
# define PARSER_H

# include <iostream>
# include <vector>
# include "Token.hpp"
# include "Dictionary.hpp"
# include "Error.hpp"
# include "SyntaxError.hpp"

# define FROM_STDIN 0
# define FROM_FILE 1

class Parser {

public:
	Parser(void);
	Parser(int src, std::vector<Token*> *tokens);
	Parser(Parser const & src);
	~Parser(void);

	Parser &	operator=(Parser const & rhs);

	int parse();
	void reduceTokens();

	std::vector<Token*> *getTokens() const;
	std::vector<std::exception_ptr> getErrors() const;

	void	setSrc(int src);
	void	setTokens(std::vector<Token*> *tokens);

private:
	std::vector<std::exception_ptr>	_errTab;
	int								_src;
	std::vector<Token*>				*_tokens;
	Dictionary						_dico;
	size_t 							_tIdx;
	int								_parenthesis;
	bool							_exitEncounter;

	void _checkToken(Token *token);
	void _checkKeyword(std::string tVal);
	void _checkNumber();
	void _checkOperand(std::string tVal);
	void _checkOperator(std::string tVal);
	void _checkParenthesisContent(void);

};

#endif
