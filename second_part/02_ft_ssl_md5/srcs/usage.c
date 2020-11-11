/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 09:10:50 by roster            #+#    #+#             */
/*   Updated: 2020/04/24 08:29:28 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** print usage if no arguments are provided
*/

void	usage(void)
{
	ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
	ft_putstr("type -h or \"help\" for a list\n");
}

/*
** Print available commands if flags -h or help is provided in argv[1]
*/

void	print_available_commands(void)
{
	ft_putstr("Standard commands:\n\n");
	ft_putstr("Message digest commands:\n");
	ft_putstr("md5\n");
	ft_putstr("sha256\n");
	ft_putstr("sha384\n");
	ft_putstr("sha512\n\n");
	ft_putstr("Cipher commands:\n\n");
}

/*
** Print command options if an algo is provided in argv[1] and "help" in argv[2]
*/

void	print_command_options(char *cmd)
{
	cmd = ft_str_tolower(cmd);
	if (ft_strcmp(cmd, "md5") == 0 || ft_strcmp(cmd, "sha256") == 0
		|| ft_strcmp(cmd, "sha384") == 0 || ft_strcmp(cmd, "sha512") == 0)
	{
		ft_putstr("Usage: ");
		ft_putstr(cmd);
		ft_putstr(" [options] [file...]\n");
		ft_putstr(" file... files to digest (default is stdin)\n");
		ft_putstr("-help         Display this summary\n");
		ft_putstr("-p            echo STDIN to STDOUT and");
		ft_putstr(" append the checksum to STDOUT\n");
		ft_putstr("-q            quiet mode\n");
		ft_putstr("-r            reverse the format of the output\n");
		ft_putstr("-s            print the sum of the given string\n");
	}
}
