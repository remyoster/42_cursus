#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::string line;
	std::ifstream ifs(av[1]);
	std::ofstream ofs;
	std::size_t found;

	if (ac == 4)
	{
		std::string s1 = av[2];
		std::string s2 = av[3];
		line = av[1];
		if (!s1.length() || !s2.length() || !line.length())
		{
			std::cout << "You must provide [filename] [s1] [s2]" << std::endl;
			return (0);
		}
		if (ifs.is_open())
		{
			line += ".replace";
			ofs.open(line.c_str());
			if (ofs.is_open())
			{
				while (getline(ifs, line))
				{
					found = 0;
					while ((found = line.find(s1, found)) != std::string::npos)
					{
						line.replace(found, s1.length(), s2);
						found += 1;
					}
					ofs << line << std::endl;
				}
				ifs.close();
				ofs.close();
				return (0);
			}
		}
		std::cout << "Can't open files" << std::endl;
	}
	else
		std::cout << "You must provide [filename] [s1] [s2]" << std::endl;
	return (0);
}
