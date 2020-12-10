#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	Fixed(Fixed const & src);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed &	operator=(Fixed const & rhs);

private:

	int					_val;
	static const int	_fractionnal;

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
