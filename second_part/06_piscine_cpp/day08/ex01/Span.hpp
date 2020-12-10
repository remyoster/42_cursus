#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <vector>

class Span {

public:
	Span(unsigned int n);
	Span(int min, int max);
	Span(Span const & src);
	~Span(void);

	Span &	operator=(Span const & rhs);

	int addNumber(int n);
	int	shortestSpan(void) const;
	int	longestSpan(void) const;

	unsigned int getSize() const;
	std::vector<int> getArray() const;

private:
	Span(void);
	std::vector<int>	_arr;
	unsigned int		_size;

};

#endif
