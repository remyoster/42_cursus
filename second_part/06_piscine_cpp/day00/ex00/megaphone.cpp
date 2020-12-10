#include <iostream> // std::cout
#include <string>	// std::string
#include <locale>	// std::locale, std::toupper

std::string ft_toupper(char *s)
{
	std::locale loc;
	std::string str (s);
	for (std::string::size_type i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i], loc);
	return str;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			std::cout << ft_toupper(argv[i]);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;

	return (0);
}