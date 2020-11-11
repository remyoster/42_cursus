#!/bin/bash

######################
### STARTING POINT ###
######################

## RESET ##
# Reset every rules = our serv is fully open
iptables -F
iptables -X
iptables -t nat -F
iptables -t nat -X
iptables -t mangle -F
iptables -t mangle -X

## POLICIES ##
# Put all policies on drop by default = our serv is fully closed
iptables -P INPUT DROP
iptables -P OUTPUT DROP
iptables -P FORWARD DROP

## LOG and NEW_RULES##
# Setting the LOG_DROP rule which is going to log/drop/ban
iptables -N LOG_DROP
iptables -A LOG_DROP -m limit --limit 1/s -j LOG --log-level info --log-prefix 'Iptables drop: '
iptables -A LOG_DROP -j DROP

# Setting the LOG_ACCEPT rule which is going to log and accept
iptables -N LOG_ACCEPT
iptables -A LOG_ACCEPT -m limit --limit 1/s -j LOG --log-level info --log-prefix 'Iptables accept: '
iptables -A LOG_ACCEPT -j ACCEPT

# Setting the ICMP trafic rule
iptables -N ICMP_TRAFIC
iptables -A ICMP_TRAFIC -m limit --limit 1/s --limit-burst 1 -j ACCEPT

### IF YOU NEED TO WATCH MORE EASELY YOUR LOGS ##
### This script permit to reorient the iptables log in the file /var/log/iptables.log
#if [ ! -e /etc/rsyslog.d/iptables.log ]
#then
#	echo ':msg, contains, "Iptables " -/var/log/iptables.log' > /etc/rsyslog.d/iptables.conf
#	echo '& ~' >> /etc/rsyslog.d/iptables.conf
#	systemctl restart rsyslog
#fi

### TCP FLAGS ## if you prefer to ban with portsentry comments theese
## Drop every flags that aren't normally formated and ban with log_ban rule
# All FLAGS at 0 or 1
iptables -A INPUT -p tcp --tcp-flags ALL NONE -j LOG_DROP
iptables -A INPUT -p tcp --tcp-flags ALL ALL -j LOG_DROP
# SYN 1 + FIN 1
iptables -A INPUT -p tcp --tcp-flags SYN,FIN SYN,FIN -j LOG_DROP
# SYN 1 + RST 1
iptables -A INPUT -p tcp --tcp-flags SYN,RST SYN,RST -j LOG_DROP
# FIN 1 + RST 1
iptables -A INPUT -p tcp --tcp-flags FIN,RST FIN,RST -j LOG_DROP
# FIN 1 + ACK 0
iptables -A INPUT -p tcp --tcp-flags ACK,FIN FIN -j LOG_DROP
# PSH 1 + ACK 0
iptables -A INPUT -p tcp --tcp-flags ACK,PSH PSH -j LOG_DROP
# URG 1 + ACK 0
iptables -A INPUT -p tcp --tcp-flags ACK,URG URG -j LOG_DROP

#######################
### ALLOWING TRAFIC ###
#######################

## LOOPBACK ##
# Let the internal loop working on input
iptables -A INPUT -i lo -j ACCEPT

## ESTABLISHED, RELATED ##
# Let established and related connection (and new in output) to be perform with the conntrack survey system
iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j LOG_ACCEPT
iptables -A OUTPUT -m conntrack ! --ctstate INVALID -j LOG_ACCEPT

## PING ##
# Let clients ping (type 0,3,8 only) our serv and return
iptables -A INPUT -i enp0s3 -p icmp --icmp-type 0 -j ICMP_TRAFIC
iptables -A OUTPUT -o enp0s3 -p icmp --icmp-type 0 -j ACCEPT
iptables -A INPUT -i enp0s3 -p icmp --icmp-type 3 -j ICMP_TRAFIC
iptables -A OUTPUT -o enp0s3 -p icmp --icmp-type 3 -j ACCEPT
iptables -A INPUT -i enp0s3 -p icmp --icmp-type 8 -j ICMP_TRAFIC
iptables -A OUTPUT -o enp0s3 -p icmp --icmp-type 8 -j ACCEPT

## SSH ##
# Let clients connect to ssh via the port 1222
iptables -A INPUT -i enp0s3 -m limit --limit 1/min --limit-burst 5 -m state --state NEW,ESTABLISHED,RELATED -p tcp --dport 1222 -j LOG_ACCEPT
iptables -A OUTPUT -o enp0s3 -m state --state ESTABLISHED,RELATED -p tcp --sport 1222 -j LOG_ACCEPT

## HTTP/S ##
# Let clients connect to our webserver
iptables -A INPUT -i enp0s3 -m state --state NEW,ESTABLISHED,RELATED -p tcp --dport 80 -j LOG_ACCEPT
iptables -A OUTPUT -o enp0s3 -m state --state ESTABLISHED,RELATED -p tcp --sport 80 -j LOG_ACCEPT
iptables -A INPUT -i enp0s3 -m state --state NEW,ESTABLISHED,RELATED -p tcp --dport 443 -j LOG_ACCEPT
iptables -A OUTPUT -o enp0s3 -m state --state ESTABLISHED,RELATED -p tcp --sport 443 -j LOG_ACCEPT

# Save our rules and make them persistent
apt-get install -y iptables-persistent
iptables-save > /etc/iptables/rules.v4
