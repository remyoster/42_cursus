#!/bin/bash

## script to run avm on each file of the /tests folder

## to start on good base
exec="avm"
if [ ! -f "$exec" ]; then
	make
fi

## Mandatory variables, don't modify them
exec="$(pwd)/$exec"
green="\033[32m"
yellow="\033[33m"
red="\033[31m"
reset="\033[0m"

## recurse function to test every file in the repo
recurse_file() {
	cd "$1"
	for file in *; do
		if [ -f "$file" ]; then
			echo -e "\n	- Runnning ${yellow}$file${reset}"
			$exec "$file"
			sleep 1
		fi
		if [ -d "$file" ]; then
			recurse_file "$file"
		fi
	done
	cd ..
}

## Run every files in /tests folder
recurse_file "./tests"