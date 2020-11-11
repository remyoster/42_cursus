# Protection against DoS by apache)

apt-get install -y libapache2-mod-evasive
mkdir /var/log/apache2/mod_evasive
touch /var/log/apache2/mod_evasive/dos_evasive.log
chown -R www-data:www-data /var/log/apache2/
cp evasive.conf /etc/apache2/mods-enabled/evasive.conf
