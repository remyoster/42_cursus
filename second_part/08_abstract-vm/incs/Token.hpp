#ifndef TOKEN_H
# define TOKEN_H

# include <iostream>

typedef enum	e_type {
	KEYWORD, 
	OPERAND,
	OPERATOR,
	NUMBER,
	UNKNOWN
}				t_type;

class Token {

public:
	Token(t_type type, std::string str, size_t pos, size_t line);
	Token(t_type type, std::string str, std::string rval, size_t pos, size_t line);
	Token(Token const & src);
	~Token(void);

	Token 		&operator=(Token const & rhs);

	t_type		getType() const;
	std::string getValue() const;
	std::string getRValue() const;
	size_t		getPos() const;
	size_t		getLine() const;

	void		setValue(std::string val);

private:
	Token(void);
	t_type		_type;
	std::string	_val;
	std::string	_rVal;
	size_t		_pos;
	size_t		_line;

};

#endif
