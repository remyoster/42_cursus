#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {

public:

	MutantStack() : std::stack<T, Container>() {};
	~MutantStack() {};

	typedef typename Container::iterator iterator;
	typename Container::iterator begin() { return (this->c.begin()); };
	typename Container::iterator end() { return (this->c.end()); };

private:

};

#endif
