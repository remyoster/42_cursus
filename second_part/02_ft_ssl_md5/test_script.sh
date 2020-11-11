#!/bin/bash

## script to compare hashes between openssl and ft_ssl
## It test each file of the repository and then add a define string in
## a test file to test it in a loop
## If there is a difference between openssl and ft_ssl it write it in a results
## file


## to start on good base
rm -f testfile resfile && touch testfile resfile
exec="ft_ssl"
if [ ! -f "$exec" ]; then
	make
fi

## Mandatory variables, don't modify them
idx=0
total_tests=0
error=0
error_nb=0
main_dir=$(pwd)
ft_ssl_res=""
openssl_res=""
exec="$(pwd)/$exec"
green="\033[32m"
yellow="\033[33m"
red="\033[31m"
reset="\033[0m"
resfile="$(pwd)/resfile"

## Modifiable variables -> feel free to modify them
teststring="jfhduisgfids fydsgf uygifyg s\0\0\0\0ds0fds\0fsd\fsdgsdgdsg\n"
looplimit=100

## function to launch ./ft_ssl and openssl with the algo passed in $1 and file $2
test_algo() {
	ft_ssl_res=$($exec $1 $2)
	openssl_res=$(openssl $1 $2)
	if [ "$ft_ssl_res" != "$openssl_res" ]; then
		printf "\nLoop or file : $3 / $2 - algo : $1\n" >> $resfile
		printf "ft_ssl  : $ft_ssl_res\n" >> $resfile
		printf "openssl : $openssl_res\n" >> $resfile
		error_nb=$(( error_nb+1 ))
		error=$(( error+1 ))
	fi
}

## recurse function to test every file in the repo
recurse_file() {
	cd "$1"
	echo -e "$yellow> Entering :$reset $(pwd)"
	for file in *; do
		if [ -f "$file" ]; then
			echo -n "- Hashing $file "
			test_algo "md5" "$file" "0"
			test_algo "sha256" "$file" "0"
			test_algo "sha384" "$file" "0"
			test_algo "sha512" "$file" "0"
			if [ "$error" -eq "0" ] ; then
				echo -e "$green\u2714$reset"
			else
				echo -e "$red\u274c$reset"
			fi
			error=$((0))
			idx=$(( idx+1 ))
		fi
		if [ -d "$file" ]; then
			recurse_file "$file"
		fi
	done
	cd ..
}

## Hash every files
recurse_file .


cd $main_dir
total_tests=$idx
idx=0
## loop to make many tests based on teststring
echo -n "- Hashing testfile $looplimit times "
while [ "$idx" -le "$looplimit" ]
do
	echo -n $teststring >> testfile
	test_algo "md5" "testfile" $idx
	test_algo "sha256" "testfile" $idx
	test_algo "sha384" "testfile" $idx
	test_algo "sha512" "testfile" $idx
	idx=$(( idx+1 ))
done

if [ "$error" -eq "0" ] ; then
	echo -e "$green\u2714$reset"
else
	echo -e "$red\u274c$reset"
fi

total_tests=$(( total_tests + idx))

## Check if resfile is empty
if [ -s resfile ]
then
	echo -ne "$red >> $error_nb/$((total_tests*4)) tests went wrong..."
	echo -e " check resfile for details$reset"
else
	rm -f resfile
	echo -e "$green >> All tests are good ($((total_tests*4)) hash made)$reset"
fi