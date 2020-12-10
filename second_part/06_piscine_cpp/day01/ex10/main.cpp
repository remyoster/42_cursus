#include <iostream>
#include <fstream>

int readFromstdint(std::string line) {
	while(getline(std::cin, line))
		std::cout << line << std::endl;
	return (0);
}

int main(int ac, char **av)
{
	std::string line;
	std::ifstream ifs;
	size_t idx;

	if (ac == 1)
		return (readFromstdint(line));
	else
	{
		idx = 1;
		while (av[idx])
		{
			line = av[idx];
			if (line.compare("-") == 0)
				return (readFromstdint(line));
			ifs.open(av[idx]);
			if (ifs.is_open())
			{
				while (getline(ifs, line))
					std::cout << line << std::endl;
				ifs.close();
			}
			else
			{
				std::cout << av[0] << ": " << av[idx];
				std::cout << ": No such file or directory" << std::endl;
			}
			idx++;
		}
	}
	return (0);
}
