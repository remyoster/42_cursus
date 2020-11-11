/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 09:51:16 by roster            #+#    #+#             */
/*   Updated: 2020/04/23 08:53:04 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** Parse the first arg of the program to now if it needs to print usage, error,
** or to continue in the parsing if the first arg is a valid command
*/

static bool	parse_first_arg(char *argv)
{
	argv = ft_str_tolower(argv);
	if (ft_strcmp(argv, "help") == 0 || ft_strcmp(argv, "-h") == 0)
		print_available_commands();
	else if (ft_strcmp(argv, "md5") == 0 || ft_strcmp(argv, "sha256") == 0
		|| ft_strcmp(argv, "sha384") == 0 || ft_strcmp(argv, "sha512") == 0)
		return (true);
	else
		print_invalid_command(argv);
	return (false);
}

static bool	print_err_or_help(char *first_arg, char *flag)
{
	if (ft_strcmp(flag, "-help") == 0)
		print_command_options(first_arg);
	else
		print_invalid_flag(first_arg, flag);
	return (false);
}

/*
** parse argv until it's not a flag, or there is an error or the flag is -s
** (because -s read the next arg to hash it). It increase idx to know after the
** parsing, where hashing algo can start
*/

bool		parser(char **argv, char **flags, size_t *idx)
{
	if (!(parse_first_arg(argv[1])))
		return (false);
	while (argv[*idx] && argv[*idx][0] == '-')
	{
		if (ft_strlen(argv[*idx]) == 2 && ft_strchr(A_FLAGS, argv[*idx][1]))
		{
			if (!ft_strchr(*flags, argv[*idx][1]))
				*flags = ft_strcat(*flags, &argv[*idx][1]);
			if (argv[*idx][1] == 's')
			{
				*idx = *idx + 1;
				return (true);
			}
		}
		else
			return (print_err_or_help(argv[1], argv[*idx]));
		*idx = *idx + 1;
	}
	return (true);
}
