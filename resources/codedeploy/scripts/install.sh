#!/bin/bash
cd /var/www/html

while [ ! -f /usr/local/etc/subsite/subsite.ini ]
do
  sleep 2
done

bin/phing -propertyfile /usr/local/etc/subsite/subsite.ini install >> /var/log/subsite/install.log
chown -R apache:apache /var/www/html/*