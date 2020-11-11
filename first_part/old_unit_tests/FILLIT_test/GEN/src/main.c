#include "tetrigen.h"

int		main(int ac, char **av)
{
	srand(time(NULL));

	if (ac != 5)
		ft_error();
	else
	{
		int		fd;
		int		index;
		int count;
		char	*str;
		char	file_name[10][5] = {
			"map0",
			"map1",
			"map2",
			"map3",
			"map4",
			"map5",
			"map6",
			"map7",
			"map8",
			"map9",
		};
		char	tetris[12][21] = {
			"....\n.##.\n.#..\n.#..\n",
			"##..\n.#..\n.#..\n....\n",
			"....\n.##.\n.##.\n....\n",
			".#..\n.#..\n.#..\n.#..\n",
			"....\n.##.\n..##\n....\n",
			".##.\n##..\n....\n....\n",
			"..#.\n.###\n....\n....\n",
			"....\n....\n##.#\n..#.\n",
			"#.#.\n.#.#\n....\n..#.\n",
			"....\n.#.#\n#.#.\n....\n",
			"#...\n####\n....\n....\n",
			"....\n....\n....\n....\n",
		};
		count = 0;
		if (ft_atoi(av[3]) > 0 && ft_atoi(av[3]) < 27 && ft_atoi(av[4]) > 0 && ft_atoi(av[4]) < 11)
		{
			while (count < ft_atoi(av[4]))
			{
				index = ft_atoi(av[3]);
				if (av[2][0] == '-' && av[2][1] == 's')
					fd = 0;
				if (av[2][0] == '-' && av[2][1] == 'f')
					fd = open(file_name[count], O_CREAT | O_RDWR, 0666);
				while (--index >= 0)
				{
					if (av[1][0] == '-' && av[1][1] == 'v')
					{
						str = ft_block_rot(tetris[ft_random(0, 6)], ft_random(0, 3));
						write(fd, str, 20);
						if (index > 0)
							write(fd, "\n", 1);
						//free(str);
					}
					if (av[1][0] == '-' && av[1][1] == 'i')
					{
						str = ft_block_rot(tetris[ft_random(7, 11)], ft_random(0, 3));
						write(fd, str, 20);
						if (ft_random(0, 1) == 1)
							write(fd, "\n", 1);
						//free(str);
					}
				}
				close(fd);
				count++;
			}
		}
		else
			ft_error();
	}
	return (0);
}
