/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:10:08 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 16:17:38 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rosterlinette.h"

void	print_begin_main(void)
{
		printf("\n /--------------------------------------------------------------\\\n");
		printf("|\t\t\tMAIN FONCTIONS TESTS\t\t\t |");
		printf("\n \\--------------------------------------------------------------/\n\n");
}

void	print_begin_add(void)
{
		printf("\n /--------------------------------------------------------------\\\n");
		printf("|\t\t    ADDITIONAL FONCTIONS TESTS\t\t\t |");
		printf("\n \\--------------------------------------------------------------/\n\n");
}

void	print_begin_bonus(void)
{
		printf("\n /--------------------------------------------------------------\\\n");
		printf("|\t\tBONUS FONCTIONS TESTS\t\t |");
		printf("\n \\--------------------------------------------------------------/\n\n");
}

void	print_begin(char *name)
{
	printf(YELLOW"TEST OF %s : "RESET, name);
}

void	print_wrong_int(int res, int exp, int test_nb) 
{
	printf("Test%d: ", test_nb);
	printf(RED"WRONG\n"RESET);
	printf(CYAN"PERSONNAL = |%d|\n", res);
	printf("EXPECTED = |%d|\n"RESET, exp);

}

void	print_wrong_size_t(size_t res, size_t exp, int test_nb) 
{
	printf("Test%d: ", test_nb);
	printf(RED"WRONG\n"RESET);
	printf(CYAN"PERSONNAL = |%zu|\n", res);
	printf("EXPECTED = |%zu|\n"RESET, exp);

}

void	print_wrong_char(char *res, char const *exp, int test_nb)
{
	printf("Test%d: ", test_nb);
	printf(RED"WRONG\n"RESET);
	printf(CYAN"PERSONNAL = |%s|\n", res);
	printf("EXPECTED = |%s|\n"RESET, exp);
}

void	print_wrong_char2(char *res, char *exp, int test_nb)
{
	printf("Test%d: ", test_nb);
	printf(RED"WRONG\n"RESET);
	printf(CYAN"PERSONNAL = |%s|\n", res);
	printf("EXPECTED = |%s|\n"RESET, exp);
}

void	print_wrong_memory(void	*mem, int test_nb)
{
	printf("Test%d: ", test_nb);
	printf(RED"WRONG\n"RESET);
	printf(CYAN"PERSONNAL = |%p|\n", &mem);
	printf("EXPECTED = |%p|\n"RESET, NULL);
}
void	print_ok(int test_nb)
{
	printf("Test%d:", test_nb);
	printf(GREEN" OK "RESET);
}

void	print_end(int bol)
{
	if (bol == 0)
		printf("\n----------------------------------------------------------\n");
	else
	{
		printf(RED" => %d mistakes :("RESET, bol);
		printf("\n----------------------------------------------------------\n");
	}
}

void	print_end_add(int bol)
{
	if (bol == 0)
		printf(GREEN"\nFUNCTIONS OPERATIONNAL\n\n"RESET);
	else
	{
		printf(RED"\nYOU HAVE "RESET);
		printf("%d ", bol);
		printf(RED"FUNCTIONS INSTABLE\n\n"RESET);
	}
}

void	print_end_main(int bol)
{
	if (bol == 0)
		printf(GREEN"EVERY FUNCTIONS OPERATIONNAL\n"RESET);
	else
	{
		printf(RED"\nYOU HAVE "RESET);
		printf("%d ", bol);
		printf(RED"FUNCTIONS INSTABLE\n\n"RESET);
	}
}
