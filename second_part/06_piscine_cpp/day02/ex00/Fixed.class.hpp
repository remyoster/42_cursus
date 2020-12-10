#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed &	operator=(Fixed const & rhs);

private:

	int					_val;
	static const int	_fractionnal;

};

#endif
