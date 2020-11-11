#!/bin/sh

## This script needs a bridged adapter connection on Virtualbox

# SUDO 
sh sudo.sh

# STATIC NETWORK
sh static.sh

# SSH
sh ssh.sh

# FIREWALL
sh my_firewall.sh

# DOS
sh fail2ban.sh
sh mod_evasive.sh

# PORTS SCAN OPTIONNAL : Portsentry
sh portsentry.sh

# UPDATE
sh update.sh

# SURVEY
sh survey.sh

# WEB SITE
sh website.sh

# Uninstall git
#apt-get autoremove --purge git

# Reboot to apply the changes
reboot
