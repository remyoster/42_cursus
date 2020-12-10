#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <iostream>

class Fixed
{

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(Fixed const &src);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed &operator=(Fixed const &rhs);
		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;

		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		bool operator>(Fixed const &rhs);
		bool operator>=(Fixed const &rhs);
		bool operator<(Fixed const &rhs);
		bool operator<=(Fixed const &rhs);
		bool operator==(Fixed const &rhs);
		bool operator!=(Fixed const &rhs);

		static Fixed const &min(Fixed const &rhs1, Fixed const &rhs2);
		static Fixed &min(Fixed &rhs1, Fixed &rhs2);
		static Fixed const &max(Fixed const &rhs1, Fixed const &rhs2);
		static Fixed &max(Fixed &rhs1, Fixed &rhs2);

	private:
		int _val;
		static const int _fractionnal;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
