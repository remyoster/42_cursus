/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:36:16 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 14:26:59 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"
# define GRAS    "\033[1m"
# define SOUL    "\033[4m"
# define SURL    "\033[7m"

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int		ft_printf(char const *fmt, ...);

int		main(void)
{
	char c = '4';
	unsigned char uc = '2';
	short int hi = 4242;
	unsigned short int uhi = 4242;
	int i = 42424242;
	unsigned int ui = 4242424242;
	long int li = 4242424242424242;
	long long int lli = 4242424242424242;
	unsigned long int uli = 42424242424242;
	unsigned long long int ulli = 424242;
	float f = 0.42;
	double d = 42.0;
	long double ld = 42.42;
	char *str = "42 42 42 42 42 42 42 42 42 42 42 42";


	printf(YELLOW"|\n--------------------\n");
	printf("|       csp        |\n");
	printf("--------------------\n"RESET);
	printf(MAGENTA"|\n# char OU unsigned char = c|\n"RESET);
	printf("return = |%d | |%d|\n", printf("char = |%c|\n", c), ft_printf("char = |%c|\n", c));
	printf("return = |%d | |%d|\n", printf("-char = |%c|\n", -c), ft_printf("-char = |%c|\n", -c));
	printf("return = |%d | |%d|\n", printf("u_char = |%c|\n", uc), ft_printf("u_char = |%c|\n", uc));
	printf("---------------------------\n");
	printf(MAGENTA"# char * = s|\n"RESET);
	printf("return = |%d | |%d|\n", printf("str = |%s|\n", str), ft_printf("str = |%s|\n", str));
	printf("return = |%d | |%d|\n", printf("|%s|\n", NULL), ft_printf("|%s|\n", NULL));
	printf("---------------------------\n");
	printf(MAGENTA"# address = p|\n"RESET);
	printf("return = |%d | |%d|\n", printf("addr = |%p|\n", str), ft_printf("addr = |%p|\n", str));



	printf(YELLOW"|\n--------------------\n");
	printf("|      diouxX      |\n");
	printf("--------------------\n"RESET);
	printf(MAGENTA"# int = d OU i|\n"RESET);
	printf("return = |%d | |%d|\n", printf("int = |%d|\n", i), ft_printf("int = |%d|\n", i));
	printf("return = |%d | |%d|\n", printf("int = |%i|\n", i), ft_printf("int = |%i|\n", i));
	printf("return = |%d | |%d|\n", printf("-int = |%d|\n", -i), ft_printf("-int = |%d|\n", -i));
	printf("return = |%d | |%d|\n", printf("-int = |%i|\n", -i), ft_printf("-int = |%i|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# octal = o|\n"RESET);
	printf("return = |%d | |%d|\n", printf("octal = |%o|\n", i), ft_printf("octal = |%o|\n", i));
	printf("return = |%d | |%d|\n", printf("-octal = |%o|\n", -i), ft_printf("-octal = |%o|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned int = u|\n"RESET);
	printf("return = |%d | |%d|\n", printf("u_i = |%u|\n", ui), ft_printf("u_i = |%u|\n", ui));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned hexa_min = x|\n"RESET);
	printf("return = |%d | |%d|\n", printf("hex_min = |%x|\n", i), ft_printf("hex_min = |%x|\n", i));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned hexa_maj = X|\n"RESET);
	printf("return = |%d | |%d|\n", printf("hex_maj = |%X|\n", i), ft_printf("hex_maj = |%X|\n", i));



	printf(YELLOW"|\n--------------------\n");
	printf("|       float      |\n");
	printf("--------------------\n"RESET);
	printf(MAGENTA"# float = f|\n"RESET);
	printf("return = |%d | |%d|\n", printf("float = |%f|\n", f), ft_printf("float = |%f|\n", f));
	printf("return = |%d | |%d|\n", printf("-float = |%f|\n", -f), ft_printf("-float = |%f|\n", -f));
	printf("---------------------------\n");
	printf(MAGENTA"# double = f|\n"RESET);
	printf("return = |%d | |%d|\n", printf("double = |%f|\n", d), ft_printf("double = |%f|\n", d));
	printf("return = |%d | |%d|\n", printf("-double = |%f|\n", -d), ft_printf("-double = |%f|\n", -d));



	printf(YELLOW"|\n--------------------\n");
	printf("|     flags Llh    |\n");
	printf("--------------------\n"RESET);
	printf(MAGENTA"# short short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("hh_int = |%hhd|\n", c), ft_printf("hh_int = |%hhd|\n", c));
	printf("return = |%d | |%d|\n", printf("hhhex_min = |%hhx|\n", c), ft_printf("hhhex_min = |%hhx|\n", c));
	printf("return = |%d | |%d|\n", printf("hhhex_maj = |%hhX|\n", c), ft_printf("hhhex_maj = |%hhX|\n", c));
	printf("return = |%d | |%d|\n", printf("hhoctal = |%hho|\n", c), ft_printf("hhoctal = |%hho|\n", c));
	printf("---------------------------\n");
	printf(MAGENTA"# short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("h_int = |%hd|\n", hi), ft_printf("h_int = |%hd|\n", hi));
	printf("return = |%d | |%d|\n", printf("hhex_min = |%hx|\n", hi), ft_printf("hhex_min = |%hx|\n", hi));
	printf("return = |%d | |%d|\n", printf("hhex_maj = |%hX|\n", hi), ft_printf("hhex_maj = |%hX|\n", hi));
	printf("return = |%d | |%d|\n", printf("hoctal = |%ho|\n", hi), ft_printf("hoctal = |%ho|\n", hi));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("uh_int = |%hu|\n", uhi), ft_printf("uh_int = |%hu|\n", uhi));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned short short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("uhh_int = |%hhu|\n", uc), ft_printf("uhh_int = |%hhu|\n", uc));
	printf("---------------------------\n");
	printf(MAGENTA"# long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("l_int = |%ld|\n", li), ft_printf("l_int = |%ld|\n", li));
	printf("return = |%d | |%d|\n", printf("-l_int = |%ld|\n", -li), ft_printf("-l_int = |%ld|\n", -li));
	printf("return = |%d | |%d|\n", printf("lhex_min = |%lx|\n", li), ft_printf("lhex_min = |%lx|\n", li));
	printf("return = |%d | |%d|\n", printf("lhex_maj = |%lX|\n", li), ft_printf("lhex_maj = |%lX|\n", li));
	printf("return = |%d | |%d|\n", printf("loctal = |%lo|\n", li), ft_printf("loctal = |%lo|\n", li));
	printf("---------------------------\n");
	printf(MAGENTA"# long long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("ll_int = |%lld|\n", lli), ft_printf("ll_int = |%lld|\n", lli));
	printf("return = |%d | |%d|\n", printf("llhex_min = |%llx|\n", lli), ft_printf("llhex_min = |%lx|\n", lli));
	printf("return = |%d | |%d|\n", printf("llhex_maj = |%llX|\n", lli), ft_printf("llhex_maj = |%lX|\n", lli));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("ul_int = |%lu|\n", uli), ft_printf("ul_int = |%lu|\n", uli));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned long long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("ull_int = |%llu|\n", ulli), ft_printf("ull_int = |%llu|\n", ulli));
	printf("---------------------------\n");
	printf(MAGENTA"# float = f|\n"RESET);
	printf("return = |%d | |%d|\n", printf("lfloat = |%lf|\n", f), ft_printf("lfloat = |%lf|\n", f));
	printf("return = |%d | |%d|\n", printf("-lfloat = |%lf|\n", -f), ft_printf("-lfloat = |%lf|\n", -f));
	printf(MAGENTA"# long double|\n"RESET);
	printf("return = |%d | |%d|\n", printf("L_double = |%Lf|\n", ld), ft_printf("L_double = |%Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("-L_double = |%Lf|\n", -ld), ft_printf("-L_double = |%Lf|\n", -ld));



	printf(YELLOW"|\n--------------------\n");
	printf("|     flags #      |\n");
	printf("--------------------\n"RESET);
	//'#' with 'f' always put a '.' even if .0
	printf("return = |%d | |%d|\n", printf("#o = |%#o|\n", i), ft_printf("#o = |%#o|\n", i));
	printf("return = |%d | |%d|\n", printf("#o = |%#o|\n", -i), ft_printf("#o = |%#o|\n", -i));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#hex_min = |%#x|\n", i), ft_printf("#hex_min = |%#x|\n", i));
	printf("return = |%d | |%d|\n", printf("#hex_min = |%#x|\n", -i), ft_printf("#hex_min = |%#x|\n", -i));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#hex_maj = |%#X|\n", i), ft_printf("#hex_maj = |%#X|\n", i));
	printf("return = |%d | |%d|\n", printf("#hex_maj = |%#X|\n", -i), ft_printf("#hex_maj = |%#X|\n", -i));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#.0f = |%#.0f|\n", d), ft_printf("#.0f = |%#.0f|\n", d));
	printf("return = |%d | |%d|\n", printf("#.0f = |%#.0f|\n", -d), ft_printf("#.0f = |%#.0f|\n", -d));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#.0Lf = |%#.0Lf|\n", ld), ft_printf("#.0Lf = |%#.0Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("#.-0Lf = |%#.0Lf|\n", -ld), ft_printf("#.-0Lf = |%#.0Lf|\n", -ld));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#30lx = |%#30lx|\n", li), ft_printf("#30lx = |%#30lx|\n", li));
	printf("return = |%d | |%d|\n", printf("#30lx = |%#30lx|\n", -li), ft_printf("#30lx = |%#30lx|\n", -li));
	printf("return = |%d | |%d|\n", printf("#f = |%#f|\n", f), ft_printf("#f = |%#f|\n", f));
	printf("return = |%d | |%d|\n", printf("#f = |%#f|\n", -f), ft_printf("#f = |%#f|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#x = |%#x|\n", 0), ft_printf("#x = |%#x|\n", 0));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#08x = |%#08x|\n", 42), ft_printf("#08x = |%#08x|\n", 42));



	printf(YELLOW"|\n--------------------\n");
	printf("|    flags '-'     |\n");
	printf("--------------------\n"RESET);
	//si apres le - il y a un 0 ca compile pas

	printf(CYAN GRAS"csp|\n"RESET);
	printf(MAGENTA"# char OU unsigned char = c|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10char = |%-10c|\n", c), ft_printf("-10char = |%-10c|\n", c));
	printf("return = |%d | |%d|\n", printf("-10char = |%-10c|\n", -c), ft_printf("-10char = |%-10c|\n", -c));
	printf("return = |%d | |%d|\n", printf("-10u_char = |%-10c|\n", uc), ft_printf("-10u_char = |%-10c|\n", uc));
	printf("---------------------------\n");
	printf(MAGENTA"# char * = s|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-20str = |%-20s|\n", str), ft_printf("-20str = |%-20s|\n", str));
	printf("---------------------------\n");
	printf(MAGENTA"# address = p|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-20addr = |%-20p|\n", str), ft_printf("-20addr = |%-20p|\n", str));

	printf(CYAN GRAS"|\ndiouxX|\n"RESET);
	printf(MAGENTA"# int = d OU i|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10int = |%-10d|\n", i), ft_printf("-10int = |%-10d|\n", i));
	printf("return = |%d | |%d|\n", printf("-10-int = |%-10i|\n", -i), ft_printf("-10-int = |%-10i|\n", -i));
	printf("return = |%d | |%d|\n", printf("-.10d = |%-.10d|\n", i), ft_printf("-.10d = |%-.10d|\n", i));
	printf("return = |%d | |%d|\n", printf("-.010d = |%-.010d|\n", i), ft_printf("-.010d = |%-.010d|\n", i));
	printf("---------------------------\n");
	printf(MAGENTA"# octal = o|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10octal = |%-10o|\n", i), ft_printf("-10octal = |%-10o|\n", i));
	printf("return = |%d | |%d|\n", printf("-10octal = |%-10o|\n", -i), ft_printf("-10octal = |%-10o|\n", -i));
	printf("return = |%d | |%d|\n", printf("-#6o = |%-#6o|\n", 2500), ft_printf("-#6o = |%-#6o|\n", 2500));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned int = u|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10u_i = |%-10u|\n", ui), ft_printf("-10u_i = |%-10u|\n", ui));
	printf("---------------------------\n");
	printf(MAGENTA"# hexa_min = x|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10hex_min = |%-10x|\n", i), ft_printf("-10hex_min = |%-10x|\n", i));
	printf("return = |%d | |%d|\n", printf("-10-hex_min = |%-10x|\n", -i), ft_printf("-10-hex_min = |%-10x|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# hexa_maj = X|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10hex_maj = |%-10X|\n", i), ft_printf("-10hex_maj = |%-10X|\n", i));
	printf("return = |%d | |%d|\n", printf("-10-hex_maj = |%-10X|\n", -i), ft_printf("-10-hex_maj = |%-10X|\n", -i));

	printf(CYAN GRAS"|\nfloat|\n"RESET);
	printf(MAGENTA"# float = f|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10float = |%-10f|\n", f), ft_printf("-10float = |%-10f|\n", f));
	printf("return = |%d | |%d|\n", printf("-10-float = |%-10f|\n", -f), ft_printf("-10-float = |%-10f|\n", -f));
	printf("---------------------------\n");
	printf(MAGENTA"# double = f|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-15double = |%-15f|\n", d), ft_printf("-15double = |%-15f|\n", d));
	printf("return = |%d | |%d|\n", printf("-15-double = |%-15f|\n", -d), ft_printf("-15-double = |%-15f|\n", -d));
	printf(CYAN GRAS"|\nh-hh-l-ll-L|\n"RESET);
	printf(MAGENTA"# short short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10hh_int = |%-10hhd|\n", c), ft_printf("-10hh_int = |%-10hhd|\n", c));
	printf("---------------------------\n");
	printf(MAGENTA"# short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10h_int = |%-10hd|\n", hi), ft_printf("-10h_int = |%-10hd|\n", hi));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10uh_int = |%-10hu|\n", uhi), ft_printf("-10uh_int = |%-10hu|\n", uhi));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned short short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-10uhh_int = |%-10hhu|\n", uc), ft_printf("-10uhh_int = |%-10hhu|\n", uc));
	printf("---------------------------\n");
	printf(MAGENTA"# long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-20l_int = |%-20ld|\n", li), ft_printf("-20l_int = |%-20ld|\n", li));
	printf("return = |%d | |%d|\n", printf("-20l_int = |%-20ld|\n", -li), ft_printf("-20l_int = |%-20ld|\n", -li));
	printf("---------------------------\n");
	printf(MAGENTA"# long long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-20ll_int = |%-20lld|\n", lli), ft_printf("-20ll_int = |%-20lld|\n", lli));
	printf("return = |%d | |%d|\n", printf("-20ll_int = |%-20lld|\n", -lli), ft_printf("-20ll_int = |%-20lld|\n", -lli));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-20ul_int = |%-20lu|\n", uli), ft_printf("-20ul_int = |%-20lu|\n", uli));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned long long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-20ull_int = |%-20llu|\n", ulli), ft_printf("-20ull_int = |%-20llu|\n", ulli));
	printf("---------------------------\n");
	printf(MAGENTA"# long double|\n"RESET);
	printf("return = |%d | |%d|\n", printf("-20L_double = |%-20Lf|\n", ld), ft_printf("-20L_double = |%-20Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("-20L_double = |%-20Lf|\n", -ld), ft_printf("-20L_double = |%-20Lf|\n", -ld));
	printf("---------------------------\n");


	printf(YELLOW"|\n--------------------\n");
	printf("|    flags '+'     |\n");
	printf("--------------------\n"RESET);
	//with '!(d-i-ld-lld-f-Lf-nb) Do not compile
	//si la valeur est neg ne fait rien
	//si apres le + il y a csp ca ne compile pas
	//si apres le + il y a oux ca ne compile pas
	printf("return = |%d | |%d|\n", printf("+hh_int = |%+hhd|\n", c), ft_printf("+hh_int = |%+hhd|\n", c));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+h_int = |%+hd|\n", hi), ft_printf("+h_int = |%+hd|\n", hi));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+d = |%+d|\n", i), ft_printf("+d = |%+d|\n", i));
	printf("return = |%d | |%d|\n", printf("+d = |%+d|\n", -i), ft_printf("+d = |%+d|\n", -i));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+i = |%+i|\n", i), ft_printf("+i = |%+i|\n", i));
	printf("return = |%d | |%d|\n", printf("+i = |%+i|\n", -i), ft_printf("+i = |%+i|\n", -i));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+ld = |%+ld|\n", li), ft_printf("+ld = |%+ld|\n", li));
	printf("return = |%d | |%d|\n", printf("+ld = |%+ld|\n", -li), ft_printf("+ld = |%+ld|\n", -li));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+lld = |%+lld|\n", lli), ft_printf("+lld = |%+lld|\n", lli));
	printf("return = |%d | |%d|\n", printf("+lld = |%+lld|\n", -lli), ft_printf("+lld = |%+lld|\n", -lli));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+f = |%+f|\n", f), ft_printf("+f = |%+f|\n", f));
	printf("return = |%d | |%d|\n", printf("+f = |%+f|\n", -f), ft_printf("+f = |%+f|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+f(d) = |%+f|\n", d), ft_printf("+f(d) = |%+f|\n", d));
	printf("return = |%d | |%d|\n", printf("+f(d) = |%+f|\n", -d), ft_printf("+f(d) = |%+f|\n", -d));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+Lf = |%+Lf|\n", ld), ft_printf("+Lf = |%+Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("+Lf = |%+Lf|\n", -ld), ft_printf("+Lf = |%+Lf|\n", -ld));
	printf("--------------------\n");
	printf(MAGENTA"# int = d OU i|\n"RESET);
	printf("return = |%d | |%d|\n", printf("+10int = |%+10d|\n", -i), ft_printf("+10int = |%+10d|\n", -i));
	printf("return = |%d | |%d|\n", printf("+010int = |%+010i|\n", i), ft_printf("+010int = |%+010i|\n", i));
	printf("return = |%d | |%d|\n", printf("+0int = |%+0i|\n", -i), ft_printf("+0int = |%+0i|\n", -i));
	printf("---------------------------\n");


	printf(YELLOW"|\n--------------------\n");
	printf("| flags '+' & '-'  |\n");
	printf("--------------------\n"RESET);
	//TEST DE + - together
	printf("%d | %d\n", printf("|%+-20d|\n", i), ft_printf("|%+-20d|\n", i));
	printf("%d | %d\n", printf("|%+-20d|\n", -i), ft_printf("|%+-20d|\n", -i));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%+---20d|\n", i), ft_printf("|%+---20d|\n", i));
	printf("%d | %d\n", printf("|%+---20d|\n", -i), ft_printf("|%+---20d|\n", -i));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%---+20d|\n", i), ft_printf("|%---+20d|\n", i));
	printf("%d | %d\n", printf("|%---+20d|\n", -i), ft_printf("|%---+20d|\n", -i));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%------+++---20d|\n", -i), ft_printf("|%------+++---20d|\n", -i));
	printf("%d | %d\n", printf("|%------+++---20d|\n", i), ft_printf("|%------+++---20d|\n", i));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%-+-+-+-+-+-+20d|\n", i), ft_printf("|%-+-+-+-+-+-+20d|\n", i));
	printf("%d | %d\n", printf("|%-+-+-+-+-+-+20d|\n", -i), ft_printf("|%-+-+-+-+-+-+20d|\n", -i));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%++++++------+++20d|\n", i), ft_printf("|%++++++------+++20d|\n", i));
	printf("%d | %d\n", printf("|%++++++------+++20d|\n", -i), ft_printf("|%++++++------+++20d|\n", -i));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%-+-+--+++---+-+-+20d|\n", i), ft_printf("|%-+-+--+++---+-+-+20d|\n", i));
	printf("%d | %d\n", printf("|%-+-+--+++---+-+-+20d|\n", -i), ft_printf("|%-+-+--+++---+-+-+20d|\n", -i));
	printf("---------------------------\n");


	printf(YELLOW"|\n--------------------\n");
	printf("|    flag  ' '     |\n");
	printf("--------------------\n"RESET);
	//' ' ignore if '+' present
	printf(MAGENTA"' 'int = d OU i|\n"RESET);
	printf("return = |%d | |%d|\n", printf(" int = |% d|\n", i), ft_printf(" int = |% d|\n", i));
	printf("return = |%d | |%d|\n", printf(" int = |% d|\n", -i), ft_printf(" int = |% d|\n", -i));
	printf("return = |%d | |%d|\n", printf("     int = |%     d|\n", i), ft_printf("     int = |%     d|\n", i));
	printf("return = |%d | |%d|\n", printf("     int = |%     d|\n", -i), ft_printf("     int = |%     d|\n", -i));
	printf("return = |%d | |%d|\n", printf(" 10int = |% 10i|\n", -i), ft_printf(" 10int = |% 10i|\n", -i));
	printf("return = |%d | |%d|\n", printf(" 010int = |% 010d|\n", -i), ft_printf(" 010int = |% 010d|\n", -i));
	printf(MAGENTA"' 'float = f|\n"RESET);
	printf("return = |%d | |%d|\n", printf("' '.10f = |% .10f|\n", f), ft_printf("' '.10f = |% .10f|\n", f));
	printf("return = |%d | |%d|\n", printf("' '.10-f = |% .10f|\n", -f), ft_printf("' '.10-f = |% .10f|\n", -f));
	printf(MAGENTA"' 'double = d|\n"RESET);
	printf("return = |%d | |%d|\n", printf("' '.10d = |% .10f|\n", d), ft_printf("' '.10d = |% .10f|\n", d));
	printf("return = |%d | |%d|\n", printf("' '.10-d = |% .10f|\n", -d), ft_printf("' '.10-d = |% .10f|\n", -d));
	printf("%d | %d\n", printf("|% ld|\n", li), ft_printf("|% ld|\n", li));
	printf("%d | %d\n", printf("|% lf|\n", f), ft_printf("|% lf|\n", f));
	printf("%d | %d\n", printf("|% lf|\n", -f), ft_printf("|% lf|\n", -f));
	printf("%d | %d\n", printf("|% Lf|\n", ld), ft_printf("|% Lf|\n", ld));
	printf("%d | %d\n", printf("|% 20d|\n", i), ft_printf("|% 20d|\n", i));



	printf(YELLOW"|\n--------------------\n");
	printf("|    flags 0_nb    |\n");
	printf("--------------------\n"RESET);

	printf(CYAN GRAS"diouxX|\n"RESET);
	printf(MAGENTA"# int = d OU i|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10int = |%10d|\n", i), ft_printf("10int = |%10d|\n", i));
	printf("return = |%d | |%d|\n", printf("10int = |%10i|\n", -i), ft_printf("10int = |%10i|\n", -i));
	printf("return = |%d | |%d|\n", printf("010int = |%010i|\n", i), ft_printf("010int = |%010i|\n", i));
	printf("return = |%d | |%d|\n", printf("010int = |%010d|\n", -i), ft_printf("010int = |%010d|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# octal = o|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10octal = |%10o|\n", i), ft_printf("10octal = |%10o|\n", i));
	printf("return = |%d | |%d|\n", printf("010octal = |%010o|\n", i), ft_printf("010octal = |%010o|\n", i));
	printf("return = |%d | |%d|\n", printf("010octal = |%010o|\n", -i), ft_printf("010octal = |%010o|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned int = u|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10u_i = |%10u|\n", ui), ft_printf("10u_i = |%10u|\n", ui));
	printf("return = |%d | |%d|\n", printf("010u_i = |%010u|\n", ui), ft_printf("010u_i = |%010u|\n", ui));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned hexa_min = x|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10hex_min = |%10x|\n", i), ft_printf("10hex_min = |%10x|\n", i));
	printf("return = |%d | |%d|\n", printf("10hex_min = |%10x|\n", -i), ft_printf("10hex_min = |%10x|\n", -i));
	printf("return = |%d | |%d|\n", printf("010hex_min = |%010x|\n", i), ft_printf("010hex_min = |%010x|\n", i));
	printf ("return = |%d | |%d|\n", printf("5.2x = |%5.2x|\n", i), ft_printf("5.2x = |%5.2x|\n", i));
	printf ("return = |%d | |%d|\n", printf("5.2x = |%5.2x|\n", -i), ft_printf("5.2x = |%5.2x|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned hexa_maj = X|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10hex_maj = |%10X|\n", i), ft_printf("10hex_maj = |%10X|\n", i));
	printf("return = |%d | |%d|\n", printf("10hex_maj = |%10X|\n", -i), ft_printf("10hex_maj = |%10X|\n", -i));

	printf(CYAN GRAS"|\ncsp"RESET);
	printf(MAGENTA"|\n# char OU unsigned char = c|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10char = |%10c|\n", c), ft_printf("10char = |%10c|\n", c));
	printf("return = |%d | |%d|\n", printf("10u_char = |%10c|\n", uc), ft_printf("10u_char = |%10c|\n", uc));
	printf("%d | %d\n", printf("|%2c|\n", 0), ft_printf("|%2c|\n", 0));
	printf("%d | %d\n", printf("|%2s|\n", ""), ft_printf("|%2s|\n", ""));
	printf("%d | %d\n", printf("|%2s|\n", NULL), ft_printf("|%2s|\n", NULL));
	printf("---------------------------\n");
	printf(MAGENTA"# char * = s|\n"RESET);
	printf("return = |%d | |%d|\n", printf("20str = |%20s|\n", str), ft_printf("20str = |%20s|\n", str));
	printf("return = |%d | |%d|\n", printf("5str = |%5s|\n", str), ft_printf("5str = |%5s|\n", str));
	printf("return = |%d | |%d|\n", printf("|%10s| is a string|\n", ""), ft_printf("|%10s| is a string|\n", ""));
	printf("%d | %d\n", printf("|%5.2s is a string|\n", ""), ft_printf("|%5.2s is a string|\n", ""));
	printf("%d | %d\n", printf("|%20.150s|\n", "onestlapoto"), ft_printf("|%20.150s|\n", "onestlapoto"));
	printf("%d | %d\n", printf("|%20s|\n", "on est la poto"), ft_printf("|%20s|\n", "on est la poto"));
	printf("---------------------------\n");
	printf(MAGENTA"# address = p|\n"RESET);
	printf("return = |%d | |%d|\n", printf("15addr = |%15p|\n", str), ft_printf("15addr = |%15p|\n", str));

	printf(CYAN GRAS"|\nh-hh-l-ll-L|\n"RESET);
	printf(MAGENTA"# short short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10hh_int = |%10hhd|\n", c), ft_printf("10hh_int = |%10hhd|\n", c));
	printf("---------------------------\n");
	printf(MAGENTA"# short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10h_int = |%10hd|\n", hi), ft_printf("10h_int = |%10hd|\n", hi));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10uh_int = |%10hu|\n", uhi), ft_printf("10uh_int = |%10hu|\n", uhi));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned short short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10uhh_int = |%10hhu|\n", uc), ft_printf("10uhh_int = |%10hhu|\n", uc));
	printf("---------------------------\n");
	printf(MAGENTA"# long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("20l_int = |%20ld|\n", li), ft_printf("20l_int = |%20ld|\n", li));
	printf("return = |%d | |%d|\n", printf("20l_int = |%20ld|\n", -li), ft_printf("20l_int = |%20ld|\n", -li));
	printf("---------------------------\n");
	printf(MAGENTA"# long long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("25ll_int = |%25lld|\n", lli), ft_printf("25ll_int = |%25lld|\n", lli));
	printf("return = |%d | |%d|\n", printf("25ll_int = |%25lld|\n", -lli), ft_printf("25ll_int = |%25lld|\n", -lli));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("20ul_int = |%20lu|\n", uli), ft_printf("20ul_int = |%20lu|\n", uli));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned long long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf("25ull_int = |%25llu|\n", ulli), ft_printf("25ull_int = |%25llu|\n", ulli));
	printf("---------------------------\n");
	printf(MAGENTA"# long double|\n"RESET);
	printf("return = |%d | |%d|\n", printf("15L_double = |%15Lf|\n", ld), ft_printf("15L_double = |%15Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("15L_double = |%15Lf|\n", -ld), ft_printf("15L_double = |%15Lf|\n", -ld));
	printf("---------------------------\n");
	printf(MAGENTA"# float|\n"RESET);
	printf("return = |%d | |%d|\n", printf("10f = |%10f|\n", f), ft_printf("10f = |%10f|\n", f));
	printf("return = |%d | |%d|\n", printf("0f = |%0f|\n", f), ft_printf("0f = |%0f|\n", f));
	printf("return = |%d | |%d|\n", printf("10.10f = |%10.10f|\n", f), ft_printf("10.10f = |%10.10f|\n", f));
	printf("return = |%d | |%d|\n", printf("10.0f = |%10.0f|\n", f), ft_printf("10.0f = |%10.0f|\n", f));


	printf(YELLOW"|\n--------------------\n");
	printf("| flag accuracy '.'|\n");
	printf("--------------------\n"RESET);

	//if '-' after the '.' doest not compile
	//if 'cp' after the '.' doest not compile
	//if '0' after '.' does not change anything
	printf(CYAN GRAS".diouxX|\n"RESET);
	printf(MAGENTA"# int = d OU i|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10int = |%.10i|\n", i), ft_printf(".10int = |%.10i|\n", i));
	printf("return = |%d | |%d|\n", printf("-.10int = |%.10i|\n", -i), ft_printf("-.10int = |%.10i|\n", -i));
	printf("return = |%d | |%d|\n", printf(".010int = |%.010d|\n", i), ft_printf(".010int = |%.010d|\n", i));
	printf("return = |%d | |%d|\n", printf("-.010int = |%.010i|\n", -i), ft_printf("-.010int = |%.010i|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# octal = o|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10octal = |%.10o|\n", i), ft_printf(".10octal = |%.10o|\n", i));
	printf("return = |%d | |%d|\n", printf(".010octal = |%.010o|\n", i), ft_printf(".010octal = |%.010o|\n", i));
	printf("return = |%d | |%d|\n", printf(".10octal = |%.10o|\n", -i), ft_printf(".10octal = |%.10o|\n", -i));
	printf("return = |%d | |%d|\n", printf(".010octal = |%.010o|\n", -i), ft_printf(".010octal = |%.010o|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned int = u|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10u_i = |%.10u|\n", ui), ft_printf(".10u_i = |%.10u|\n", ui));
	printf("return = |%d | |%d|\n", printf(".010u_i = |%.010u|\n", ui), ft_printf(".010u_i = |%.010u|\n", ui));
	printf("---------------------------\n");
	printf(MAGENTA"# hexa_min = x|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10hex_min = |%.10x|\n", i), ft_printf(".10hex_min = |%.10x|\n", i));
	printf("return = |%d | |%d|\n", printf(".10hex_min = |%.10x|\n", -i), ft_printf(".10hex_min = |%.10x|\n", -i));
	printf("return = |%d | |%d|\n", printf(".010hex_min = |%.010x|\n", i), ft_printf(".010hex_min = |%.010x|\n", i));
	printf("return = |%d | |%d|\n", printf(".010hex_min = |%.010x|\n", -i), ft_printf(".010hex_min = |%.010x|\n", -i));
	printf("---------------------------\n");
	printf(MAGENTA"# hexa_maj = X|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10hex_maj = |%.10X|\n", i), ft_printf(".10hex_maj = |%.10X|\n", i));
	printf("return = |%d | |%d|\n", printf(".010hex_maj = |%.010X|\n", i), ft_printf(".010hex_maj = |%.010X|\n", i));
	printf("return = |%d | |%d|\n", printf(".10hex_maj = |%.10X|\n", -i), ft_printf(".10hex_maj = |%.10X|\n", -i));
	printf("return = |%d | |%d|\n", printf(".010hex_maj = |%.010X|\n", -i), ft_printf(".010hex_maj = |%.010X|\n", -i));

	printf(CYAN GRAS"|\n.s|\n"RESET);
	printf(MAGENTA"# char * = s|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".20str = |%.20s|\n", str), ft_printf(".20str = |%.20s|\n", str));
	printf("return = |%d | |%d|\n", printf(".5str = |%.5s|\n", str), ft_printf(".5str = |%.5s|\n", str));

	printf(CYAN GRAS"|\n.h-hh-l-ll-L|\n"RESET);
	printf(MAGENTA"# short short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10hh_int = |%.10hhd|\n", c), ft_printf(".10hh_int = |%.10hhd|\n", c));
	printf("---------------------------\n");
	printf(MAGENTA"# short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10h_int = |%.10hd|\n", hi), ft_printf(".10h_int = |%.10hd|\n", hi));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10uh_int = |%.10hu|\n", uhi), ft_printf(".10uh_int = |%.10hu|\n", uhi));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned short short int|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10uhh_int = |%.10hhu|\n", uc), ft_printf(".10uhh_int = |%.10hhu|\n", uc));
	printf("---------------------------\n");
	printf(MAGENTA"# long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".20l_int = |%.20ld|\n", li), ft_printf(".20l_int = |%.20ld|\n", li));
	printf("return = |%d | |%d|\n", printf(".20l_int = |%.20ld|\n", -li), ft_printf(".20l_int = |%.20ld|\n", -li));
	printf("---------------------------\n");
	printf(MAGENTA"# long long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".25ll_int = |%.25lld|\n", lli), ft_printf(".25ll_int = |%.25lld|\n", lli));
	printf("return = |%d | |%d|\n", printf(".25ll_int = |%.25lld|\n", -lli), ft_printf(".25ll_int = |%.25lld|\n", -lli));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".20ul_int = |%.20lu|\n", uli), ft_printf(".20ul_int = |%.20lu|\n", uli));
	printf("---------------------------\n");
	printf(MAGENTA"# unsigned long long int|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".25ull_int = |%.25llu|\n", ulli), ft_printf(".25ull_int = |%.25llu|\n", ulli));


	printf(CYAN GRAS"|\n.f-Lf|\n"RESET);
	printf(MAGENTA"# float = f|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".10float = |%.10f|\n", f), ft_printf(".10float = |%.10f|\n", f));
	printf("return = |%d | |%d|\n", printf(".0f = |%.0f|\n", f), ft_printf(".0f = |%.0f|\n", f));
	printf("return = |%d | |%d|\n", printf(".f = |%.f|\n", f), ft_printf(".f = |%.f|\n", f));
	printf("return = |%d | |%d|\n", printf(".10f = |%.10f|\n", f), ft_printf(".10f = |%.10f|\n", f));
	printf("return = |%d | |%d|\n", printf(".10float = |%.10f|\n", -f), ft_printf(".10float = |%.10f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".0f = |%.0f|\n", -f), ft_printf(".0f = |%.0f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".f = |%.f|\n", -f), ft_printf(".f = |%.f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".10f = |%.10f|\n", -f), ft_printf(".10f = |%.10f|\n", -f));
	printf("---------------------------\n");
	printf(MAGENTA"# double = f|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".30double = |%.30f|\n", d), ft_printf(".30double = |%.30f|\n", d));
	printf("return = |%d | |%d|\n", printf(".30double = |%.30f|\n", -d), ft_printf(".30double = |%.30f|\n", -d));
	printf("---------------------------\n");
	printf(MAGENTA"# long double|\n"RESET);
	printf("return = |%d | |%d|\n", printf(".15L_double = |%.15Lf|\n", ld), ft_printf(".15L_double = |%.15Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf(".15L_double = |%.15Lf|\n", -ld), ft_printf(".15L_double = |%.15Lf|\n", -ld));


	printf(YELLOW"|\n--------------------\n");
	printf("|      flag %%      |\n");
	printf("--------------------\n"RESET);

	printf("%d | %d\n", printf("%% = %%\n"), ft_printf("%% = %%\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("10%% = %10%\n"), ft_printf("10%% = %10%\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("-5%% = %-5%\n"), ft_printf("-5%% = %-5%\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf(".10%% = %.10%\n"), ft_printf(".10%% = %.10%\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf(".0%% = %.0%\n"), ft_printf(".0%% = %.0%\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("%   % = %   %\n"), ft_printf("%   % = %   %\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("%+%\n"), ft_printf("%+%\n"));
	printf("---------------------------\n");


	printf(YELLOW"|\n--------------------\n");
	printf("|   DIVERS TESTS   |\n");
	printf("--------------------\n"RESET);

	printf("%d | %d\n", printf("null |%c and text|\n", 0), ft_printf("null |%c and text|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("-#6o = |%-#6o|\n", 2500), ft_printf("-#6o = |%-#6o|\n", 2500));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%0+5d|\n", 42), ft_printf("|%0+5d|\n", 42));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%0+5d|\n", -42), ft_printf("|%0+5d|\n", -42));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%03.2d|\n", 1), ft_printf("|%03.2d|\n", 1));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%010x|\n", 542), ft_printf("|%010x|\n", 542));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%.0d|\n", 0), ft_printf("|%.0d|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%.d|\n", 0), ft_printf("|%.d|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("@moulitest: |%#.x |%#.0x|\n", 0, 0), ft_printf("@moulitest: |%#.x |%#.0x|\n", 0, 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("@moulitest: |%#.o |%#.0o|\n", 0, 0), ft_printf("@moulitest: |%#.o |%#.0o|\n", 0, 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("@moulitest: |%c|\n", 0), ft_printf("@moulitest: |%c|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("@moulitest: |%.o |%.0o|\n", 0, 0), ft_printf("@moulitest: |%.o |%.0o|\n", 0, 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%0d|\n", i), ft_printf("|%0d|\n", i));
	printf("%d | %d\n", printf("|%0d|\n", -i), ft_printf("|%0d|\n", -i));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%#x|\n", 0), ft_printf("|%#x|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%-5.2s is a string|\n", "this"), ft_printf("|%-5.2s is a string|\n", "this"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%.2i|\n", -10), ft_printf("|%.2i|\n", -10));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("toto et |%02u coco |%-5lu mimi|\n", 19, (unsigned long)-20), ft_printf("toto et |%02u coco |%-5lu mimi|\n", 19, (unsigned long)-20));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%#-8.3o|\n", 0), ft_printf("|%#-8.3o|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("t|%04.2o|%#2oet |%#-8.3o titi|\n", 0, 0, 0), ft_printf("t|%04.2o|%#2oet |%#-8.3o titi|\n", 0, 0, 0));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("%d | %d\n", printf("test|%-8p |%---32p |%#5.3x|%#024X|\n", &i, &str, 0x25, 50), ft_printf("test|%-8p |%---32p |%#5.3x|%#024X|\n", &i, &str, 0x25, 50));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%00+10.4d|\n", 0), ft_printf("|%00+10.4d|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("test|%#.4o| et |%02o| |%0#14.0o|!!|\n", 012, 036, 12587499), ft_printf("test|%#.4o| et |%02o| |%0#14.0o|!!|\n", 012, 036, 12587499));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("toto |%0##0.4X||%#4.2x|et c'est fini |\n", 0x037a, 0x9e), ft_printf("toto |%0##0.4X||%#4.2x|et c'est fini |\n", 0x037a, 0x9e));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("cc|%#.4X| et |%#0012x| |%#04hX| !!|\n", 0xaef, 0xe, (unsigned short)0), ft_printf("cc|%#.4X| et |%#0012x| |%#04hX| !!|\n", 0xaef, 0xe, (unsigned short)0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%0#10.0x| |%0#x|\n", 12345, 0), ft_printf("|%0#10.0x| |%0#x|\n", 12345, 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("OF ->|%0#10.0x|\n", 0), ft_printf("US ->|%0#10.0x|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("titi % +---12.5% et%%%0004% et %+1%\n"), ft_printf("titi % +---12.5% et%%%0004% et %+1%\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("u|%4.2s|s |%-1.s|\n |%---5.3s| |\n", "coco", NULL, "yooo"), ft_printf("u|%4.2s|s |%-1.s|\n |%---5.3s| |\n", "coco", NULL, "yooo"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|%-2s|\n", ""), ft_printf("|%-2s|\n", ""));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("hello ca|%----4c| |%1c| va |%10c| |%-c| ??|\n", '\0', '\n', (char)564, 0), ft_printf("hello ca|%----4c| |%1c| va |%10c| |%-c| ??|\n", '\0', '\n', (char)564, 0));
	printf("---------------------------\n");
	ft_printf("bin to nb = |%~b|\n", "1001111001011");
	printf("%d | %d\n", printf("|%f|\n", sqrt(-2)), ft_printf("|%f|\n", sqrt(-2)));
	printf("%d | %d\n", printf("|%f|\n", -pow(5548489, 4894984646)), ft_printf("|%f|\n", -pow(5548489, 4894984646)));
	printf("%d | %d\n", printf("|%f|\n", pow(5548489, 4894984646)), ft_printf("|%f|\n", pow(5548489, 4894984646)));
	printf("%d | %d\n", printf("|%+f|\n", -pow(5548489, 4894984646)), ft_printf("|%+f|\n", -pow(5548489, 4894984646)));
	printf("%d | %d\n", printf("|%+f|\n", pow(5548489, 4894984646)), ft_printf("|%+f|\n", pow(5548489, 4894984646)));
	printf("%d | %d\n", printf("|%X %12o %5s %x %d qdaze %c|\n", -123, -432, "okqsd", 5643, 123654, 'S'), ft_printf("|%X %12o %5s %x %d qdaze %c|\n", -123, -432, "okqsd", 5643, 123654, 'S'));
	printf("%d | %d\n", printf("|%X %o %s %x %d qdaze %c | %c|\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W'), ft_printf("|%X %o %s %x %d qdaze %c | %c|\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W'));
	printf("%d | %d\n", printf("|%X %o %s %x %d qdaze %c | %c|\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W'), ft_printf("|%X %o %s %x %d qdaze %c | %c|\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W'));

	printf("%d | %d\n", printf("|%X| |%o| |%s| |%5x| |%d| qdaze |%5c| \n |%c| |%X| |%o| |%s| |%x| |%d| qdaze |%c| \n |%c|\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W'), ft_printf("|%X| |%o| |%s| |%5x| |%d| qdaze |%5c| \n |%c| |%X| |%o| |%s| |%x| |%d| qdaze |%c| \n |%c|\n", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W'));


	printf("\n");

	/*NE COMPILE PAS AVEC LES FLAGS -WALL -WEXTRA -WERROR
NB :
printf("|%#-08x", 42);
printf("|%.2c", NULL);
printf("|% c", 0);
printf("|%-05o", 2500);
printf("|% +d", 42);
printf("|%+ d", 42);
printf("|% ++d", -42);
printf("|%-05d", 42);
printf("|%+u", 4294967295);
printf("@moulitest: |%#.d |%#.0d|\n", 0, 0);
*/

	return (0);
}
