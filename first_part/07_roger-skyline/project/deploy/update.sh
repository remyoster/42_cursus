# Copy the update script on init.d and add it to cron

cp my_update /etc/init.d/
update-rc.d my_update defaults
echo "# My update_script" >> /etc/crontab
echo "00 04 * * 1 /etc/init.d/my_update" >> /etc/crontab
