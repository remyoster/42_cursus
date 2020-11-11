from Parser import Parser;
from Solver import Solver;

"""
C style to launch the computor. It will first call the parser to check the user
input. The user can write an equation in many ways :
- 2X^2 - 487.254 + 78/4 * X^0 + 5 -777 = 36
- x^2 + x - 5X = 47
- 48787X + 487x^287+478 -18 = -32X + 4
- ...
But if -- or -+ or ^45.21 or ^2/4-> error
Then if equation is well formated it calls Solver class to extract coefs (a,b,c)
If the degree of the equation is > 2 it stops with a message. Then it solve the
equation
BONUS : 
- irreductible fraction
- more flexible parsing
- natural form
- unit test ? 
"""

def main():
	eq = Parser.check_all();
	coefs = Solver.extract_coefs(eq);
	Solver.solve_eq(coefs);

main();
