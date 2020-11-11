# Set the sshd configuration file to the exigence of RS1 subject at 42

user=$(cat /etc/passwd | grep home | awk -F ':' '{print $1}')
sed -i 's/#Port 22/Port 1222/' /etc/ssh/sshd_config
sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config
sed -i 's/#PubkeyAuthentication yes/PubkeyAuthentication yes/' /etc/ssh/sshd_config
sed -i 's/#PasswordAuthentication yes/PasswordAuthentication no/' /etc/ssh/sshd_config
sed -i 's/#PermitEmptyPasswords no/PermitEmptyPasswords no/' /etc/ssh/sshd_config
sed -i 's/UsePAM yes/UsePAM no/' /etc/ssh/sshd_config
mkdir /home/$user/.ssh
echo "$(cat id_rsa.pub)" >> /home/$user/.ssh/authorized_keys

#service ssh restart
