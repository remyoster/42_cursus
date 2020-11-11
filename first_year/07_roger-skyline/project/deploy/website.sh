# This script configure a web server named gdw by searching the static address

mkdir /var/www/gdw
cp -R ../web/website/* /var/www/gdw/
cp -R ../web/ssl /var/www/gdw/
addr=$(cat /etc/network/interfaces | grep address | awk '{print $2}')
sed -i "s/addr/$addr/" ../web/gdw-80.conf
sed -i "s/addr/$addr/" ../web/gdw-443.conf
cp ../web/gdw-80.conf /etc/apache2/sites-available/
cp ../web/gdw-443.conf /etc/apache2/sites-available/
a2enmod ssl
a2ensite gdw-80
a2ensite gdw-443

#service apache2 restart
