import sys;
import random;

"""
Usage : python eq_generator.py [eq_number] [complexity]
- eq_number = number of equation you want to generate
- complexity = number of random degree val you want to generate
If none of them are provided it use 5 and 5

To test computor you can redirect ouput of eq_generator.py into a file. Then
launch test_script.sh file or launch test_script.sh random which is going to
do exactly that.
"""

try :
	eq_number = int(sys.argv[1]);
	complexity = int(sys.argv[2]);
except:
	eq_number = 5;
	complexity = 5;

while (eq_number > 0):
	eq = "";
	init = True;
	complexity_tmp = complexity;
	while (complexity_tmp > 0):
		nb = random.randint(-100, 100);
		degree = random.randint(0, 2);
		if (init == True or nb < 0):
			eq += "{}X^{}".format(nb, degree);
			init = False;
		elif (nb > 0):
			eq += "+{}X^{}".format(nb, degree);
		complexity_tmp -= 1;
	eq += " = 0";
	print(eq);
	eq_number -= 1;
