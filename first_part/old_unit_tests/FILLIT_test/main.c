/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:46:40 by roster            #+#    #+#             */
/*   Updated: 2019/01/11 11:12:39 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putstr(char const *s);

void	ft_usage(void)
{
	printf("\nError\n");
	printf("usage: ./test.fillit [option] [number1] [number2]\n");
	printf("Option:\n-v = Generate a valid map\n-i = Generate a invalid map\n");
	printf("-m = {SPECIAL} Run on existing folder\n\t [0] == invalid map\n\t[1] == valid map\n");
	printf("[number1]\n = Select a map_size between 1 and 26\n");
	printf("[number2]\n = Select a number of tests between 1 and 10\n");
}

int		main(int argc, char **argv)
{
	int index;
	char map[10][5] = {
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
	char invalid_map[19][32] = {
		"sample/error/sample_27",
		"sample/error/sample_a",
		"sample/error/sample_error",
		"sample/error/sample_error1",
		"sample/error/sample_error2",
		"sample/error/sample_error3",
		"sample/error/sample_error4",
		"sample/error/sample_error5",
		"sample/error/sample_error6",
		"sample/error/sample_error7",
		"sample/error/sample_error8",
		"sample/error/sample_error9",
		"sample/error/sample_error10",
		"sample/error/sample_error_spe1",
		"sample/error/sample_linesup",
		"sample/error/sample_linesup1",
		"sample/error/sample_linesup2",
		"sample/error/sample_many#",
		"sample/error/sample_no_#",
	};
	char valid_map[6][23] = {
		"sample/valid/sample_1",
		"sample/valid/sample_2",
		"sample/valid/sample_3",
		"sample/valid/sample_4",
		"sample/valid/sample_5",
		"sample/valid/sample_6",
	};
	char *arguments_gen[] = {"tetrigen", argv[1], "-f", argv[2], argv[3], NULL};
	pid_t child_pid1;
	pid_t child_pid2;
	pid_t child_pid3;

	if (argc == 4)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'v')
		{
			index = 0;
			child_pid1 = fork();
			if (child_pid1 != 0)
			{
				if (execvp("GEN/tetrigen", arguments_gen) == -1)
					perror("execvp");
			}
			while (index < atoi(argv[3]))
			{
				child_pid2 = fork();
				if (child_pid2 != 0)
				{
					if (execlp("../fillit", "fillit", map[index], NULL) == -1)
						perror("execlp");
				}
				index++;
			}
		}
		else if (argv[1][0] == '-' && argv[1][1] == 'i')
		{
			index = 0;
			child_pid1 = fork();
			if (child_pid1 != 0)
			{
				if (execvp("GEN/tetrigen", arguments_gen) == -1)
					perror("execvp");
			}
			while (index < atoi(argv[3]))
			{
				child_pid2 = fork();
				if (child_pid2 != 0)
				{
					if (execlp("../fillit", "fillit", map[index], NULL) == -1)
						perror("execlp");
				}
				index++;
			}
		}
	}
	else if (argc == 3)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'd')
		{
			if (argv[2][0] == '0')
			{
				index = 0;
				while (index < 19)
				{
					child_pid3 = fork();
					if (child_pid3 != 0)
					{
						if (execlp("../fillit", "fillit", invalid_map[index], NULL) == -1)
							perror("execlp");
					}
					index++;
				}
			}
			else if (argv[2][0] == '1')
			{
				index = 0;
				while (index < 6)
				{
					child_pid3 = fork();
					if (child_pid3 != 0)
					{
						if (execlp("../fillit", "fillit", valid_map[index], NULL) == -1)
							perror("execlp");
					}
					index++;
				}
			}
			else
				ft_usage();
		}
	}
	else
		ft_usage();
	return (0);
}
