#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>
# include <iterator>


template <typename T>
int	easyfind(T haystack, int needle)
{
	typename T::iterator it;

	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end())
		throw std::runtime_error("value not found in container");
	return (needle);
};

#endif