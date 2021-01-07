#include <iostream>
#include "Lexer.hpp"

Lexer::Lexer(void) {}

Lexer::Lexer(Lexer const &src)
{
	*this = src;
}

/*
** Delete each Token
*/

Lexer::~Lexer(void)
{
	std::vector<Token*>::iterator it;
	for (it = this->_tokens.begin(); it != this->_tokens.end(); ++it)
		delete *it;
}

Lexer &Lexer::operator=(Lexer const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

/*
** read from a file
*/

int Lexer::read(char *filename)
{
	std::string line;
	std::ifstream ifs;
	size_t lineCounter = 1;
	ifs.open(filename);
	if (ifs.is_open())
	{
		while (getline(ifs, line)) {
			this->tokenize(line, lineCounter);
			lineCounter += 1;
		}
		ifs.close();
	}
	else {
		std::cout << "Can't open file" << std::endl;
		return (1);
	}
	return (0);
}

/*
** read from stdin
*/

int Lexer::read(void)
{
	std::string line;
	size_t lineCounter = 1;
	while (getline(std::cin, line))
	{
		if (line.compare(";;") == 0)
			break ;
		this->tokenize(line, lineCounter);
		lineCounter += 1;
	}
	return (0);
}


/*
** Create token by associate the str with the dictionnary val
*/

Token *Lexer::createToken(std::string str, size_t pos, size_t lineCounter)
{
	std::map<std::string, std::string>::iterator it;
	std::map<t_type, std::map<std::string, std::string>> sMap;
	std::map<t_type, std::map<std::string, std::string>>::iterator dicoIt;

	sMap = this->_dico.getDico();
	for (dicoIt = sMap.begin(); dicoIt != sMap.end(); ++dicoIt)
	{
		it = dicoIt->second.find(str);
		if (it != dicoIt->second.end())
			return (new Token(dicoIt->first, it->second, str, pos, lineCounter));
	}
	return (new Token(UNKNOWN, str, pos, lineCounter));
}

/*
** Read the line and tokenize it
*/

void Lexer::tokenize(std::string line, size_t lineCounter)
{
	size_t i = 0;
	size_t j;
	
	while (line[i])
	{
		if (isdigit(line[i]))
		{
			j = i;
			while (isdigit(line[++j])){}
			this->_tokens.push_back(
				new Token(NUMBER, line.substr(i, j - i), i + 1, lineCounter));
			i = j - 1;
		}
		else if (isalpha(line[i]))
		{
			j = i;
			while (isalpha(line[++j])){}
			this->_tokens.push_back(
				this->createToken(line.substr(i, j - i), i + 1, lineCounter));
			i = j - 1;
		}
		else if (line[i] == ';')
			return ;
		else if (line[i] != ' ')
			this->_tokens.push_back(
				this->createToken(line.substr(i, 1), i + 1, lineCounter));
		i++;
	}
}

std::vector<Token*> Lexer::getTokens() const {
	return (this->_tokens);
}