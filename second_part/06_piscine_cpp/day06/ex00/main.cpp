#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <limits>

const char * parser(char *str)
{
	size_t countDot = 0;
	std::string s = str;
	std::string type = "double";

	if (s.compare("inff") == 0 || s.compare("inf") == 0
		|| s.compare("+inf") == 0 || s.compare("-inf") == 0
		|| s.compare("+inff") == 0 || s.compare("-inff") == 0)
		return ("infinity");
	else if (s.compare("nan") == 0 || s.compare("nanf") == 0)
		return ("not a number");
	else if (isdigit(s[0]) || s[0] == '-' || s[0] == '+')
	{
		for (size_t i = 1; i < s.length(); i++)
		{
			if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
				return (NULL);
			if (s[i] == '.')
				countDot += 1;
			if (s[i] == 'f' && i + 1 != s.length())
				return (NULL);
			else if (s[i] == 'f')
				type = "float";
		}
		if (countDot > 1)
			return (NULL);
		else if (countDot == 0 && s.length() < 10)
		{
			if (s.length() > 4 || (isdigit(s[0]) && s.length() == 3
				&& (s[0] > 49 || (s[0] == 49 && s[1] > 50)
				|| (s[0] == 49 && s[1] == 50 && s[2] > 55)))
				|| (!isdigit(s[0]) && s.length() == 4
				&& ((s[0] == '-' && (s[1] > 49 || (s[1] == 49 && s[2] > 50)
				|| (s[1] == 49 && s[2] == 50 && s[3] > 56)))
				|| (s[0] == '+' && (s[1] > 49 || (s[1] == 49 && s[2] > 50)
				|| (s[1] == 49 && s[2] == 50 && s[3] > 55))))))
					type = "int";
			else
				type = "char";
		}
		return (type.c_str());
	}
	return (NULL);
}

void print_char(double d)
{
	char c = static_cast<char>(d);

	if (isnan(d) || isinf(d) || d < 0)
		std::cout << "char: "
				  << "impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: "
				  << "Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

void print_int(double d)
{
	int i = static_cast<int>(d);

	if (isnan(d) || isinf(static_cast<float>(d)) || d > 2147483647 || d < -2147483648)
		std::cout << "int: "
				  << "impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void print_float(double d)
{
	float f = static_cast<float>(d);
	if (static_cast<int>(f) == f)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

void print_double(double d)
{


	if (static_cast<int>(d) == d)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: "
			<< std::setprecision(std::numeric_limits<double>::digits10 + 1)
			<< d << std::endl;
}

int main(int ac, char **av)
{
	double d;
	std::string parsed;
	const char *res;

	if (ac == 2)
	{
		res = parser(av[1]);
		if (res != NULL)
		{
			std::cout << "** detected type : " << res << " **" << std::endl;
			d = atof(av[1]);
			print_char(d);
			print_int(d);
			print_float(d);
			print_double(d);
		}
		else
			std::cout << "Bad format" << std::endl;
	}
	else
		std::cout << "usage: only one string argument" << std::endl;
	return (0);
}
