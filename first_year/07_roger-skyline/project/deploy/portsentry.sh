# Install the portsentry software and configure it

apt-get install -y portsentry
cp portsentry.conf /etc/portsentry/
sed -i 's/TCP_MODE="tcp"/TCP_MODE="atcp"/' /etc/default/portsentry
sed -i 's/UDP_MODE="udp"/UDP_MODE="audp"/' /etc/default/portsentry
