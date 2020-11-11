# Install and configure fail2ban (protection by watching logs)

apt-get install -y fail2ban
cp apache-dosevasive.conf /etc/fail2ban/filter.d/
cp http-get-dos.conf /etc/fail2ban/filter.d/
cp jail.local /etc/fail2ban/
