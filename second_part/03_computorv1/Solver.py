from Parser import Parser;
from Printer import Printer;

"""
This class resolve the equation. To do that it first isolate every coefs,
then it checks if the coefs are not = 0. Then it calculate the discriminant (if
needed) and resolve the equation
"""

class Solver:

	# Global index to imitate pointer in C. get_number can increase index and 
	# return a number thanks to that id
	idx = 0;


	# Solve the equation by calculating the discriminant and print the result
	@classmethod
	def solve_eq(self, coefs):
		if (self.check_infinite(coefs)):
			Printer.infinite_solution();
		if (not self.is_degree_valid(coefs)):
			Printer.cant_resolve(coefs);
		if (not self.are_coefs_valid(coefs)):
			Printer.impossible(coefs[0]);
		Printer.reduce_form(coefs.copy());
		if (not coefs.get(2) or coefs[2] == 0):
			sol = -coefs[0] / coefs[1];
			print("The solution is :\n{}".format(self.sol_to_str(sol, coefs)));
			exit();
		delta = (coefs[1] * coefs[1]) - (4 * coefs[2] * coefs[0]);
		if (delta < 0):
			print("The discriminant is stricly negative, there is no solution");
		elif (delta == 0):
			sol = (-coefs[1]) / (2 * coefs[2]);
			print("The discriminant is equal to 0,"
				+ " the solution is :\n{}".format(
					self.sol_to_str(sol, coefs, delta)));
		else:
			sol_1 = (-coefs[1] - (delta ** 0.5)) / (2 * coefs[2]);
			sol_2 = (-coefs[1] + (delta ** 0.5)) / (2 * coefs[2]);
			print("The discriminant is stricly positive, the two solutions "
				+ "are :\n{}\n{}".format(
					self.sol_to_str(sol_1, coefs.copy(), delta, -1),
					self.sol_to_str(sol_2, coefs, delta)));


	# Split the equation in two to extract coefs of each part and then substract
	# right coefs to left coefs and return the result
	@classmethod
	def extract_coefs(self, eq):
		eq_parts = eq.split('=');
		l_coefs = self.get_coefs(eq_parts[0]);
		r_coefs = self.get_coefs(eq_parts[1]);
		for key in r_coefs.keys():
			if (l_coefs.get(key)):
				l_coefs[key] -= r_coefs[key];
			else:
				l_coefs[key] = - r_coefs[key];
		return (l_coefs);


	# Extract every coef from an equation part.
	@classmethod
	def get_coefs(self, eq):
		coefs = {0 : 0.0, 1 : 0.0, 2 : 0.0};
		Solver.idx = 0;
		i = Solver.idx;
		eq_len = len(eq);
		sign = 1;
		while (i < eq_len):
			if (eq[i] == '-' or eq[i] == '+'):
				sign = -1 if eq[i] == '-' else 1;
			if (eq[i].isdigit() or eq[i] == 'X'):
				tmp_number = self.get_number(i, eq);
				i = Solver.idx;
				if (i < eq_len and eq[i] == '*'):
					i += 1;
				if (i < eq_len and eq[i] == 'X'):
					if (i + 1 < eq_len and eq[i + 1] == '^'):
						tmp_power = int(self.get_number(i + 2, eq));
						i = Solver.idx;
						if (coefs.get(tmp_power)):
							coefs[tmp_power] += (tmp_number * sign);
						else:
							coefs[tmp_power] = (tmp_number * sign);
					else:
						coefs[1] += (tmp_number * sign);
				else:
					coefs[0] += (tmp_number * sign);
				while (i < eq_len and eq[i] != '-' and eq[i] != '+'):
					i += 1;
			else:
				i += 1;
		return (coefs);


	# Transform a string number to a float number and return it
	# nb keep trace of the previous number, and op of the operation to do
	# Ex: 12.5, 47 / 2, 42*42, 42, 124878...
	@classmethod
	def get_number(self, i, eq, nb=0, op=None):
		j = i;
		eq_len = len(eq);
		while (i < eq_len and eq[i].isdigit()):
			i += 1;
		tmp_number = 1 if not eq[j:i] else eq[j:i];
		if (op == '.'):
			tmp_number = nb + '.' + tmp_number;
		elif (op == '/'):
			tmp_number = float(nb) / float(tmp_number);
		elif (op == '*'):
			tmp_number = float(nb) * float(tmp_number);
		if (i < eq_len and (eq[i] == '/' or eq[i] == '.' or (eq[i] == '*'
			and eq[i + 1] != 'X'))):
			return (self.get_number(i + 1, eq, tmp_number, eq[i])); 
		Solver.idx = i;
		return (float(tmp_number));


	# Return the pgcd of two numbers or 1. 
	@staticmethod
	def get_pgcd(num, denum):
		num = -num if num < 0 else num;
		denum = -denum if denum < 0 else denum;
		while (denum % num):
			pgcd = denum % num;
			denum = num;
			num = pgcd;
		return (num or 1);


	# Check if every reel are solutions (= all coefs at 0), also delete each
	# coef which is equal to 0
	@staticmethod
	def check_infinite(coefs):
		is_infinite = True;
		for coef in coefs.keys():
			if (coefs[coef] != 0):
				is_infinite = False;
			elif (coef > 2):
				del coefs[coef];
		return (is_infinite);


	# Check if the degree of the equation is not > 2
	@staticmethod
	def is_degree_valid(coefs):
		for coef in coefs.keys():
			if (coef > 2 and coefs[coef] != 0):
				return (False);
		return (True);
	
	@staticmethod
	def are_coefs_valid(coefs):
		if ((coefs.get(0) and (coefs.get(1) or coefs.get(2))) or coefs.get(1)
			or coefs.get(2)):
			return (True);
		return (False);


	# BONUS : get numerator, denumerator and pgcd to print solution in an
	# irreductible fraction
	@classmethod
	def sol_to_str(self, sol, coefs, delta=None, sign=1):
		if (sol.is_integer()):
			return ((int)(sol));
		else:
			if (not delta):
				num = -coefs[0];
				denum = coefs[1];
			elif (delta == 0):
				num = -coefs[1];
				denum = coefs[2] * 2;
			else:
				num = -coefs[1] + (sign * (delta ** 0.5));
				denum = coefs[2] * 2;
			if (num.is_integer() and denum.is_integer()):
				pgcd = self.get_pgcd(num, denum);
			else: 
				pgcd = 1;
			num = (int)(num) if num.is_integer() else num;
			denum = (int)(denum) if denum.is_integer() else denum;
			if (num < 0 and denum < 0):
				num = -num;
				denum = -denum;
			if (pgcd != 1):
				num_f = num / pgcd;
				denum_f = denum / pgcd;
				num_f = (int)(num_f) if num_f.is_integer() else num_f;
				denum_f = (int)(denum_f) if denum_f.is_integer() else denum_f;
				msg = "{} <=> {}/{} => {}/{}".format(sol, num, denum,
					num_f, denum_f);
			else:
				msg = "{} <=> {}/{}".format(sol, num, denum);
		return (msg);
	
	# Square root function in case that ** 0.5 is not allowed
	# iter_max define the accuracy of the result. 
	@staticmethod
	def ft_sqrt(nb):
		nb = float(nb);
		def f(x):
			return ((x + nb / x) / 2);
		a0 = 1;
		a1 = f(a0);
		iter_max = 10000;
		while (iter_max > 0 and a0 != a1):
			a0 = a1;
			a1 = f(a0);
			iter_max -= 1;
		return ((int)(a1) if a1.is_integer() else a1);


