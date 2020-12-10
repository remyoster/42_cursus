#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	Span test(200000);
	Span range(-12, 15787815);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	Span sp2(sp);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	for (size_t i = 0; i < 200000; i++)
		test.addNumber(i);

	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	std::cout << range.shortestSpan() << std::endl;
	std::cout << range.longestSpan() << std::endl;

	try
	{
		sp.addNumber(14);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span err(5);
		err.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
