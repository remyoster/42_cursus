#ifndef DICTIONARY_H
# define DICTIONARY_H

# include <iostream>
# include <map>
# include "Token.hpp"

class Dictionary {

public:

	Dictionary(void);
	Dictionary(Dictionary const & src);
	~Dictionary(void);

	Dictionary &	operator=(Dictionary const & rhs);

	std::map<std::string, std::string> getKeywords() const;
	std::map<std::string, std::string> getOperands() const;
	std::map<std::string, std::string> getOperators() const;
	std::map<t_type, std::map<std::string, std::string>> getDico() const;

private:

	std::map<std::string, std::string> 							_keywords;
	std::map<std::string, std::string> 							_operands;
	std::map<std::string, std::string> 							_operators;
	std::map<t_type, std::map<std::string, std::string>>	_dico;
};

#endif
