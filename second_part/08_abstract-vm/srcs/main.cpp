#include "Lexer.hpp"
#include "Printer.hpp"
#include "Parser.hpp"
#include "Resolver.hpp"

/*
** Declare the classes needed to perfom the compilation and execution of the
** pseudo code, then call their different methods.
** If ac == 1 the programm read the input from stdin, else if ac == 2 from the file
** pointed to by av[1].
** Then the lexer will transform each portion of the line into tokens.
** Theese tokens will be passed to the parser to check the syntax. Then they will
** be reduced (simplified) and passed to the resolver. The resolver try to run
** each instructions even if an error is happening (like compilation without flags).
*/

int main(int ac, char **av)
{
	Lexer lex;
	Printer print;
	Parser ps;
	Resolver rs;

	if (ac <= 2)
	{
		if ((ac == 1 && lex.read() == 0) || (ac == 2 && lex.read(av[1]) == 0))
		{
			std::vector<Token *> tokens = lex.getTokens();
			ps.setSrc(ac - 1);
			ps.setTokens(&tokens);
			if (ps.parse() != 0) {
				print.error(ps.getErrors());
			}
			else
			{
				ps.reduceTokens();
				rs.setTokens(&tokens);
				if (rs.run() != 0)
					print.error(rs.getErrors());
			}
		}
	}
	else
		print.usage();
	return (0);
}
