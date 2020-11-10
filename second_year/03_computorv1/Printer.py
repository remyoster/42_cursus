import sys;

"""
Use to print different message during program
"""
class Printer:

	# Print program's usage
	@staticmethod
	def usage():
		print("Usage : python computor.py [polynomial equation]\n"
			+ "The polynomial equation must be a string, and the degree" 
			+ " couldn't exceed 2.");
	

	# Print error with code to determine which message. Exit program
	@staticmethod
	def error(code):
		if (code == "format"):
			print("The polynomial equation isn't well formated");
		elif (code == "degree"):
			print("Degrees in the polynomial equation are incorrect");
		exit();
	

	# Print infinite solution case
	@staticmethod
	def infinite_solution():
		print("Reduce form : 0 = 0\n"
			+ "Polynomial degree : 0\n"
			+ "Every number are solutions");
		exit();
	

	# Print can't resolve case
	@classmethod
	def cant_resolve(self, coefs):
		self.reduce_form(coefs);
		print("The Polynomial degree is stricly greater than 2, I can't solve.");
		exit();
	
	
	# Print impossible case like : 1 = 0;
	@staticmethod
	def impossible(c):
		c = (int)(c) if c.is_integer() else c;
		print("Reduce form : {} = 0\nThat's not possible !".format(c));
		exit();


	# Print reduce form and (bonus)natural form of the equation, 
	# then the polynomial degree. Deleted each coef which is == to 0
	@classmethod
	def reduce_form(self, coefs):
		for coef in coefs.keys():
			if (coefs[coef] == 0):
				del coefs[coef];
		sorted_coefs = sorted(coefs.keys(), reverse=True);
		reduce_form = self.get_reduce_form(coefs);
		natural_form = self.get_natural_form(coefs, sorted_coefs);
		print("Reduce form : {} = 0".format(reduce_form));
		print("Natural form : {} = 0".format(natural_form));
		print("Polynomial degree : {}".format(sorted_coefs[0]));


	# Return a reduce_form string well formated. I let 0 * X^n by choice. 
	# It can easily be removed with a boolean init like in the natura form
	@staticmethod
	def get_reduce_form(coefs):
		sorted_coefs = sorted(coefs.keys());
		reduce_form = "";
		for idx, coef in enumerate(sorted_coefs):
			if (coefs[coef].is_integer()):
				coefs[coef] = int(coefs[coef]);
			if (idx == 0):
				reduce_form += "{} * X^{}".format(coefs[coef], coef);
			else:
				if (coefs[coef] < 0):
					reduce_form += " - {} * X^{}".format(-coefs[coef], coef);
				else:
					reduce_form += " + {} * X^{}".format(coefs[coef], coef);
		return (reduce_form);


	# (BONUS)Return the natural form string well formated
	@classmethod
	def get_natural_form(self, coefs, sorted_coefs):
		natural_form = "";
		init = False;
		for idx, coef in enumerate(sorted_coefs):
			if (idx == 0 or init == True):
				init = False;
				if (coef > 1 and coefs[coef] != 0):
					natural_form += "{}X^{}".format(
						self.one_to_none(coefs[coef]), coef);
				elif (coef == 1 and coefs[coef] != 0):
					natural_form += "{}X".format(self.one_to_none(coefs[coef]));
				elif (coef == 0 and coefs[coef] != 0):
					natural_form += "{}".format(coefs[coef]);
				else:
					init = True;
			else:
				if (coef > 1):
					if (coefs[coef] < 0):
						natural_form += " - {}X^{}".format(
							self.one_to_none(-coefs[coef]), coef);
					elif (coefs[coef] > 0):
						natural_form += " + {}X^{}".format(
							self.one_to_none(coefs[coef]), coef);
				elif (coef == 1):
					if (coefs[coef] < 0):
						natural_form += " - {}X".format(
							self.one_to_none(-coefs[coef]));
					elif (coefs[coef] > 0):
						natural_form += " + {}X".format(
							self.one_to_none(coefs[coef]));
				else:
					if (coefs[coef] < 0):
						natural_form += " - {}".format(-coefs[coef]);
					elif (coefs[coef] > 0):
						natural_form += " + {}".format(coefs[coef]);
		return (natural_form);


	# return the nb if it is > 1 else '', usefull to natural form
	@staticmethod
	def one_to_none(nb):
		return (nb if nb != 1 else '');



