#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template<typename T>
class Array {

public:

	Array<T>(void) : _arr(new T[0]), _size(0) {};
	Array<T>(unsigned int n) : _arr(new T[n]), _size(n) {
		for (size_t idx = 0; idx < n; idx++)
			this->_arr[idx] = T();
	};
	Array(Array const & src) : _arr(new T[0]) {
		*this = src;
	};
	~Array<T>(void) {
		delete [] this->_arr;
	};

	Array<T> & operator=(Array<T> const & rhs) {
		if (this != &rhs) {
			delete[] this->_arr;
			this->_arr = new T[rhs.size()];
			this->_size = rhs.size();
			for (size_t idx = 0; idx < rhs.size(); idx++)
				this->_arr[idx] = rhs._arr[idx];
		}
		return *this;
    };

	T &	operator[](size_t idx) {
		if (idx >= this->_size)
			throw std::out_of_range("Index is out of range");
		return (this->_arr[idx]);
	};

	size_t	size(void) const {
		return (this->_size);
	}

private:

	T	*_arr;
	size_t	_size;

};

#endif
