/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 09:36:55 by roster            #+#    #+#             */
/*   Updated: 2020/04/14 10:06:45 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** This file contains functions to print errors on standart output
*/

void	print_invalid_command(char *cmd)
{
	ft_putstr("Invalid command \'");
	ft_putstr(cmd);
	ft_putstr("\'; type \"help\" or -h for a list.\n");
}

void	print_invalid_flag(char *cmd, char *flag)
{
	ft_putstr(cmd);
	ft_putstr(": Unrecognized flag ");
	ft_putstr(flag);
	ft_putchar('\n');
	ft_putstr(cmd);
	ft_putstr(": Use -help for summary.\n");
}

void	print_invalid_path(char *algo, char *path)
{
	ft_putstr("ft_ssl: ");
	ft_putstr(ft_str_tolower(algo));
	ft_putstr(": ");
	ft_putstr(path);
	ft_putstr(": No such file or directory\n");
}
