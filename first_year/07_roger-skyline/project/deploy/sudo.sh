# Install and add the first user if any in sudo-group

apt-get install -y sudo
user=$(cat /etc/passwd | grep home | awk -F ':' '{print $1}')
if [ $user ]
then
	#sed -i "/\%sudo/a ${user}\tALL=(ALL:ALL) ALL" /etc/sudoers
	adduser $user sudo
fi
