#ifndef LEXER_H
# define LEXER_H

# include <iostream>
# include <fstream>
# include <vector>
# include "Token.hpp"
# include "Dictionary.hpp"

class Lexer {

public:

	Lexer(void);
	Lexer(Lexer const & src);
	~Lexer(void);

	Lexer &	operator=(Lexer const & rhs);

	int	read(void);
	int	read(char *filename);
	Token 	*createToken(std::string str, size_t pos, size_t lineCounter);
	void	tokenize(std::string line, size_t lineCounter);

	std::vector<Token*> getTokens() const;

private:
	std::vector<Token*> _tokens;
	Dictionary _dico;

};

#endif
