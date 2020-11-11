# Set our IP to be a static one finishing by 0.39
# The cluster is the part of the IP address which depends of the floor (11,12,13)

FLOOR=$(ip addr | grep -m2 "10" | tail -n1 | cut -d '.' -f2)

echo "\n" >> /etc/network/interfaces
sed -i 's/allow-hotplug enp0s3/auto enp0s3/' /etc/network/interfaces
sed -i 's/iface enp0s3 inet dhcp/iface enp0s3 inet static/' /etc/network/interfaces
echo "address 10.$FLOOR.0.39" >> /etc/network/interfaces
echo "gateway 10.$FLOOR.254.254" >> /etc/network/interfaces
echo "netmask 255.255.255.252" >> /etc/network/interfaces
echo "network 10.$FLOOR.0.36" >> /etc/network/interfaces
echo "broadcast 10.$FLOOR.0.39" >> /etc/network/interfaces
