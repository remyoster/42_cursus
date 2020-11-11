#!/bin/bash

# The script test computor programm on each line of a file if there is a specific file 
# given, or if random it will use the eq_generator 
# else it test all files in the tests folder. So in order to work
# each equation must be in a line.
# Example : 
# ./test_script.sh === ./test_script.sh nonexistingile -> read tests folder
# ./test_script existingfile -> read the file
# ./test_script random [eq_number] [complexity] -> use eq_generator

# colors 
green="\033[32m"
yellow="\033[33m"
reset="\033[0m"

# clean res file in case it already exists
rm -f results && touch results

# Read a file line by line and call the computor on each line
# if err is given in 2nd arg, it just keep the last output in results
read_file() {
	echo -e "$yellow Opening file : $1 $reset"
	echo "Fichier : $1" >> results
	while IFS= read -r line
	do
		echo "	Testing equation : $line"
		echo "Equation : \"$line\"" >> results
		echo "Output :" >> results
		if [ "$2" == "err" ]; then
			python computor.py "$line" | tail -n 1 >> results
		else
			python computor.py "$line" >> results
		fi
		echo "" >> results
	done < "$1"
	echo "--------------------------------------------------------" >> results
}

# loop through all lines in all err test files to test our computor on it
# We just keep the last print sentence to have better lisibility
if [ -f "$1" ]; then
	read_file "$1"
elif [ "$1" == "random" ]; then
	echo -e "$yellow Generating random equation $reset"
	python eq_generator.py $2 $3 > sample
	read_file "sample"
	rm -f sample
	echo -e "$yellow Deleting sample file $reset"
else
	for file in ./tests/err/*; do
		if [ -f "$file" ]; then
			read_file "$file"
		fi
	done
	for file in ./tests/*; do
		if [ -f "$file" ]; then
			read_file "$file"
		fi
	done
fi

echo -e "$green All tests done. Check results file $reset"
