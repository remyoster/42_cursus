echo "# Survey script" >> /etc/crontab
echo "00 00 * * * /etc/init.d/survey_cron" >> /etc/crontab
date=$(date -r /etc/crontab)
sed -i "s/DATE_MODIF=/DATE_MODIF=\"$date\"/" survey_cron
cp survey_cron /etc/init.d/
