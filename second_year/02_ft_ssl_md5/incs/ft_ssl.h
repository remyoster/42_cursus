/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 11:49:03 by roster            #+#    #+#             */
/*   Updated: 2020/05/08 07:47:02 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

/*
** Respectively for bool uint_t type and t_list struct
*/
# include <stdbool.h>
# include <stdint.h>
# include "libft.h"

/*
** Constant in hash status to know how to print
*/

# define STDIN 0
# define FILE 1
# define STRING 2
# define ERR -1
# define READ_SIZE 512

/*
** List of all available flags
*/

# define A_FLAGS "rpqs"

/*
** Will contain hash value or error value in hash, source argument in src
*/

typedef struct		s_hash
{
	uint8_t			*value;
	char			*src;
	int				status;
	size_t			size;
}					t_hash;

typedef struct		s_data
{
	char			*msg;
	size_t			msg_len;
}					t_data;

/*
** Hashes functions
*/

uint8_t				*md5(char *msg, size_t msg_len);
uint8_t				*sha256(char *msg, size_t msg_len);
uint8_t				*sha512(char *msg, size_t msg_len, int mod);
t_list				*toggle_hashes(int ac, char **av, size_t idx, char *flags);

/*
** Parsing functions
*/

bool				parser(char **argv, char **flags, size_t *idx);

/*
** Utils functions
*/
t_data				read_file(char *path, int status);

/*
** Print functions
*/

void				usage();
void				print_available_commands();
void				print_command_options(char *cmd);
void				print_hash(t_list **hash, char *algo, char *flags);

void				print_invalid_command(char *cmd);
void				print_invalid_flag(char *cmd, char *flag);
void				print_invalid_path(char *algo, char *path);

#endif
