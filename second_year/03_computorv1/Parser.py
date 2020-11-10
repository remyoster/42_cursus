import sys;
from Printer import Printer;

"""
The Parser class as it's name indicate, parse argv to see if the program can 
works with it.
All methods are static or classmethod so it doesn't need to be instanciated.
"""

class Parser:

	# Main function of the class, call check_ac and check_characters on each
	# member of the equation to check if the part given is well formated. 
	# Return upper equation without spaces if everything is good
	@classmethod
	def check_all(self):
		eq = self.check_ac().upper();
		eq_parts = eq.split('=');
		if (len(eq_parts) != 2):
			Printer.error("format");
		for part in eq_parts:
			if (len(part) == 0):
				Printer.error("format");
			self.check_characters(part);
		return (eq);


	# Check if there is only one string argument and returns it without spaces,
	# else print usage and exit
	@staticmethod
	def check_ac():
		ac = len(sys.argv);
		if (ac != 2):
			Printer.usage();
			exit();
		else:
			lst = sys.argv[1].split();
			lst = ''.join(lst);
			return (lst);


	# Check eq to verify that each character is a number or an operator or x|X
	# Also if two operators are following each other, and if the degree is > 2
	@classmethod
	def check_characters(self, eq):
		i = 0;
		eq_len = len(eq);
		if (self.is_operator(eq[0]) and eq[0] != '-'):
			Printer.error("format");
		while (i < eq_len):

			if (eq[i].isdigit()):
				while (i + 1 < eq_len and eq[i].isdigit()):
					i += 1;
			# case : not digit(0123456789) not X  not op(+-/*^.)
			if (not self.is_operator(eq[i]) and not self.is_number_or_x(eq[i])):
				Printer.error("format");
			
			# case : .
			if (eq[i] == '.'):
				if (not eq[i - 1].isdigit() or not eq[i + 1].isdigit()):
					Printer.error("format");
				while (i + 1 < eq_len and eq[i + 1].isdigit()):
					i += 1;
				if (i + 1 == eq_len and not eq[i].isdigit()):
					Printer.error("format");
				elif (i + 1 < eq_len and eq[i + 1] != '+' and eq[i + 1] != '-'
					and eq[i + 1] != '*' and eq[i + 1] != 'X'):
					Printer.error("format");
			try :
				# case ^
				if (eq[i] == '^'):
					if (eq[i - 1] != 'X'):
						Printer.error("format");
					if (not eq[i + 1].isdigit()):
						Printer.error("degree");
					while (i + 1 < eq_len and eq[i + 1].isdigit()):
						i += 1;
					if (i + 1 == eq_len and not eq[i].isdigit()):
						Printer.error("format");
					elif (i + 1 < eq_len and eq[i + 1] != '+'
						and eq[i + 1] != '-'):
						Printer.error("format");
				
				# case double operator
				if (self.is_operator(eq[i]) and self.is_operator(eq[i - 1])):
					Printer.error("format");

				# case / and . with else than digit around
				if ((eq[i] == '/' or eq[i] == '.')
					and (not self.is_number_or_x(eq[i + 1])
					or not self.is_number_or_x(eq[i - 1]))):
					Printer.error("format");
			except Exception:
				Printer.error("format");
			i += 1;

		# case last char is operator
		if (self.is_operator(eq[i - 1])):
			Printer.error("format");


	# Boolean function to check if the character is an operator
	@staticmethod
	def is_operator(char):
		if (char == '+' or char == '-' or char == '*' or char == '^'
			or char == '/' or char == '.'):
			return (True);
		else:
			return (False);


	# Boolean function to check if the character is a number or x|X
	@staticmethod
	def is_number_or_x(nb):
		ascii_val = ord(nb);
		if ((ascii_val >= 48 and ascii_val <= 57) or ascii_val == 88):
			return (True);
		else:
			return (False);
