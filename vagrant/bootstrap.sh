#!/usr/bin/env bash

# Add multiverse
add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc) main universe multiverse"
add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc)-updates main universe multiverse"
add-apt-repository "deb http://security.ubuntu.com/ubuntu $(lsb_release -sc)-security main universe multiverse"

# Install packages.
apt-get update && apt-get -y upgrade

# Default settings.
echo 'mysql-server mysql-server/root_password password pass' | debconf-set-selections
echo 'mysql-server mysql-server/root_password_again password pass' | debconf-set-selections
echo 'phpmyadmin phpmyadmin/dbconfig-install boolean true' | debconf-set-selections
echo 'phpmyadmin phpmyadmin/app-password-confirm password pass' | debconf-set-selections
echo 'phpmyadmin phpmyadmin/mysql/admin-pass password pass' | debconf-set-selections
echo 'phpmyadmin phpmyadmin/mysql/app-pass password pass' | debconf-set-selections
echo 'phpmyadmin phpmyadmin/reconfigure-webserver multiselect apache2' | debconf-set-selections

apt-get install -y apache2 libapache2-mod-fastcgi hp5-cli php5-fpm php5-xdebug \
  php5-gd php5-mysql vim mc language-pack-en git mysql-server mysql-client \
  phpmyadmin zsh php5-curl


# Setting up hostname to contentcluster.
echo "contentcluster" > /etc/hostname


# Config for Apache2 webserver.
cat > /etc/apache2/sites-available/v.conf <<EOF
<VirtualHost *:8080>
  ServerAdmin admin@localhost.lan
  ServerAlias *.v
  CustomLog /var/log/apache2/v-access.log common
  ErrorLog /var/log/apache2/v-error.log
  VirtualDocumentRoot /var/www/%0/build/
  <Directory /var/www/>
    AllowOverride All
    Allow from all
  </Directory>
</VirtualHost>
EOF

cat > /etc/apache2/sites-available/default <<EOF
<VirtualHost *:8080>
  ServerAdmin webmaster@localhost
  DocumentRoot /var/www
  <Directory />
    Options FollowSymLinks
    AllowOverride All
    Order allow,deny
    allow from all
  </Directory>
  <Directory /var/www/>
    Options Indexes FollowSymLinks MultiViews
    AllowOverride All
    Order allow,deny
    allow from all
  </Directory>
  ScriptAlias /cgi-bin/ /usr/lib/cgi-bin/
  <Directory "/usr/lib/cgi-bin">
    AllowOverride None
    Options +ExecCGI -MultiViews +SymLinksIfOwnerMatch
    Order allow,deny
    Allow from all
  </Directory>
  ErrorLog \${APACHE_LOG_DIR}/error.log

  # Possible values include: debug, info, notice, warn, error, crit,
  # alert, emerg.
  LogLevel warn
  CustomLog \${APACHE_LOG_DIR}/access.log combined
  Alias /doc/ "/usr/share/doc/"
  <Directory "/usr/share/doc/">
    Options Indexes MultiViews FollowSymLinks
    AllowOverride None
    Order deny,allow
    Deny from all
    Allow from 127.0.0.0/255.0.0.0 ::1/128
  </Directory>
</VirtualHost>
EOF

# Php FPM config.
cat > /etc/apache2/conf.d/php5-fpm.conf <<EOF
<IfModule mod_fastcgi.c>
  AddHandler php5-fcgi .php
  Action php5-fcgi /php5-fcgi
  Alias /php5-fcgi /usr/lib/cgi-bin/php5-fcgi
  FastCgiExternalServer /usr/lib/cgi-bin/php5-fcgi -socket /var/run/php5-fpm.sock -pass-header Authorization -idle-timeout 3600
  <Directory /usr/lib/cgi-bin>
    Order allow,deny
    Allow from all
  </Directory>
</IfModule>
EOF

# Resolving FQDN error.
echo "ServerName localhost" > /etc/apache2/conf.d/fqdn

# Change Apache server port.
sed -i 's/^\(NameVirtualHost\).*$/\1 *:8080/gi' /etc/apache2/ports.conf
sed -i 's/^\(Listen \).*$/\1 8080/gi' /etc/apache2/ports.conf
# Change the user.
sed -i 's/^\(export APACHE_RUN_USER=\).*$/\1vagrant/gi' /etc/apache2/envvars
sed -i 's/^\(export APACHE_RUN_GROUP=\).*$/\1vagrant/gi' /etc/apache2/envvars

# Enabling Apache modules.
a2enmod vhost_alias rewrite actions fastcgi alias
a2ensite v.conf

# Changing the ownership of www directory.
chown vagrant:vagrant /var/www -R
chown vagrant:vagrant /var/lib/apache2/fastcgi -R
chown vagrant /var/lock/apache2

# Php settings.
# XDebug
cat >> /etc/php5/fpm/conf.d/xdebug.ini <<EOF
xdebug.remote_enable=1
xdebug.remote_host=127.0.0.1
xdebug.remote_port=9000
xdebug.max_nesting_level=500
;xdebug.auto_trace=1
EOF

# Php FPM: Php.ini
# Change memory limit to 1GB.
sed -i 's/^\(memory_limit = \).*$/\1 1G/gi' /etc/php5/fpm/php.ini
# Post max size and upload max size set up 10GB.
sed -i 's/^\(post_max_size =\).*/\1 10G/gi' /etc/php5/fpm/php.ini
sed -i 's/^\(upload_max_filesize =\).*$/\1 10G/gi' /etc/php5/fpm/php.ini
# Max execution time and input time to 600.
sed -i 's/^\(max_execution_time =\).*$/\1 600/gi' /etc/php5/fpm/php.ini
sed -i 's/^\(max_input_time = \).*$/\1 600/gi' /etc/php5/fpm/php.ini

# Php CLI: Php.ini
# Change memory limit to 1GB.
sed -i 's/^\(memory_limit = \).*$/\1 1G/gi' /etc/php5/cli/php.ini
# Post max size and upload max size set up 10GB.
sed -i 's/^\(post_max_size =\).*/\1 10G/gi' /etc/php5/cli/php.ini
sed -i 's/^\(upload_max_filesize =\).*$/\1 10G/gi' /etc/php5/cli/php.ini
# Max execution time and input time to 600.
sed -i 's/^\(max_execution_time =\).*$/\1 600/gi' /etc/php5/cli/php.ini
sed -i 's/^\(max_input_time = \).*$/\1 600/gi' /etc/php5/cli/php.ini

# Updating user, group and the socket in pool file.
sed -i 's/^\(user =\).*$/\1 vagrant/gi' /etc/php5/fpm/pool.d/www.conf
sed -i 's/^\(group =\).*$/\1 vagrant/gi' /etc/php5/fpm/pool.d/www.conf
sed -i 's/^\(listen =\).*$/\1 \/var\/run\/php5-fpm.sock/gi' /etc/php5/fpm/pool.d/www.conf
sed -i 's/^;\(listen.owner =\).*$/\1 vagrant/gi' /etc/php5/fpm/pool.d/www.conf
sed -i 's/^;\(listen.group =\).*$/\1 vagrant/gi' /etc/php5/fpm/pool.d/www.conf
sed -i 's/^;\(listen.mode = 0660\)/\1/gi' /etc/php5/fpm/pool.d/www.conf

# Mysql settings.
# Create .my.cnf file for vagrant user.
cat > ~vagrant/.my.cnf <<EOF
[mysql]
user=root
password=pass

[mysqladmin]
user=root
password=pass

[mysqldump]
user=root
password=pass

[mysql_convert_table_format]
user=root
password=pass
EOF
chown vagrant:vagrant ~vagrant/.my.cnf

# Create .my.cnf file for root user.
cat > ~root/.my.cnf <<EOF
[mysql]
user=root
password=pass

[mysqladmin]
user=root
password=pass

[mysqldump]
user=root
password=pass

[mysql_convert_table_format]
user=root
password=pass
EOF

# Giving rights for cc mysql user.
mysql -e "grant all on *.* to cc@localhost identified by 'cc'"

# Restarting services.
service apache2 restart
service php5-fpm restart


# Zsh install.
wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh


# Update zsh local aliases.
cat > ~vagrant/.zshrc_local <<EOF
#!/bin/zsh
# General aliases
alias du1='du --max-depth=1 -m | sort -n'
alias duh1='du --max-depth=1 -h'
alias df='df -h'
# Set back rm
unalias rm

# Open ports
alias ports='netstat -tulanp'

# Drupal Code Sniffer
alias drupalcs="phpcs --standard=~/.drush/coder/coder_sniffer/Drupal --extensions='php,module,inc,install,test,profile,theme,js,css,info,txt'"

# Webserver
alias nginxreload='sudo nginx -s reload'
alias nginxtest='sudo nginx -t'
alias apache2reload='sudo servive apache2 reload'
alias apache2test='sudo apachectl -t && apachectl -t -D DUMP_VHOSTS'

# Firewall
alias iptlist='sudo /sbin/iptables -L -n -v --line-numbers'
alias iptlistin='sudo /sbin/iptables -L INPUT -n -v --line-numbers'
alias iptlistout='sudo /sbin/iptables -L OUTPUT -n -v --line-numbers'
alias iptlistfw='sudo /sbin/iptables -L FORWARD -n -v --line-numbers'

## pass options to free ##
alias meminfo='free -m -l -t'
alias psmem='ps auxf | sort -nr -k 4'
alias psmem10='ps auxf | sort -nr -k 4 | head -10'
alias pscpu='ps auxf | sort -nr -k 3'
alias pscpu10='ps auxf | sort -nr -k 3 | head -10'

## Get server cpu info ##
alias cpuinfo='lscpu'

# Drush
alias ddl='drush -y dl'
alias dcc='drush -y cc all'
alias duli='drush uli'
alias dwd='drush -y wd-del all'
alias d='drush'
alias dy='drush -y'

# Grep
alias gr='grep -B 5 -A 10 -n --color=auto -R * -e'

if [ -d ~/.composer ] ; then
  export COMPOSER_HOME=~/.composer
  export PATH=~/.composer/vendor/bin:"\${PATH}"
fi

# CDPATH
export CDPATH=.:~:/var/www:"\${CDPATH}"

# SSH Askpass
# export SSH_ASKPASS=/usr/bin/ksshaskpass


db() {
  # Display the help text.
  HELP=\$(echo -e "Usage:\\n  db <parameters>\\n  \\nParameters:\\n  list|l          [<filter for databases>]                  - listing databases.\\n  table|t         <database> [<table filter>]               - tables of database.\\n  create|c        <database> [<user> [<password>]]          - create a database, with full grants for user@localhost.\\n  drupal|d        <database>                                - create a database, drupal@localhost user has a full rights.\\n  drop            <database>                                - drop the database.\\n  drop-tables|dt  <database>                                - drop tables in database.\\n  dump|du         <database> [<gzip file path>]             - database dump creating.\\n  restore|re      <database> <gzip dump file path>          - restore from database dump.\\n  copy|co         <source database> <destination database>  - copy from source to destination (table of destination will be dropped before).\\n  grant|g         <database> <user>  [<password>]           - for user@localhost gives rights.\\n  revoke|rv       <database> <user>                         - revoke rights of a user@localhost.\\n  rights|ri       <user>                                    - user@localhost rights.\\n  \\n")
  if [ -z "\${1}" ]; then echo -e "Nincs paraméter megadva.\\n\\n\$HELP"
  else
    case \$1 in
      list | l)
        # List the databases.
        # If you give a parameter, than it fiter the databases names.
        if [ ! -z "\${2}" ]; then
          mysql -e "show databases like '%\${2}%'"
        else
          mysql -e "show databases"
        fi;;
      create | c)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        else
          # Adatbázis létrehozása
          mysql -e "create database \${2} default character set utf8 default collate utf8_hungarian_ci";
          if [ ! -z "\${4}" ]; then
            # Jelszó megadása is
            mysql -e "grant all on \${2}.* to \${3}@localhost identified by '\${4}'; show grants for \${3}@localhost"
          elif [ ! -z "\${3}" ]; then
            # Nincs jelszó megadva, csak a jogok beállítva
            mysql -e "grant all on \${2}.* to \${3}@localhost; show grants for \${3}@localhost"
          fi
        fi ;;
      drupal | d)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        else
          # Adatbázis létrehozása
          mysql -e "create database \${2} default character set utf8 default collate utf8_hungarian_ci; grant all on \${2}.* to drupal@localhost; show grants for drupal@localhost"
        fi ;;
      drop)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        else
          mysql -e "drop database if exists \${2};"
        fi ;;
      drop-tables | dt)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        else
          mysql -e "drop database if exists \${2}; create database \${2}"
        fi ;;
      grant | g)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        else
          if [ ! -z "\${4}" ]; then
            # Jelszó megadása is
            mysql -e "grant all on \${2}.* to \${3}@localhost identified by '\${4}'; show grants for \${3}@localhost"
          elif [ ! -z "\${3}" ]; then
            # Nincs jelszó megadva, csak a jogok beállítva
            mysql -e "grant all on \${2}.* to \${3}@localhost; show grants for \${3}@localhost"
          fi
        fi ;;
      revoke | rv)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        elif [ -z "\${3}" ]; then echo -e "Nincs user megadva.\\n\\n\$HELP"
        else
          mysql -e "revoke all on \${2}.* from \${3}@localhost; show grants for \${3}@localhost"
        fi ;;
      rights | ri)
        if [ -z "\${2}" ]; then echo -e "Username is missing.\\n\\n\$HELP"
        else
          mysql -e "show grants for \${2}@localhost"
        fi ;;
      tables | t)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        else
          # Ha megadott a tábla szűkítése is.
          if [ ! -z "\${3}" ]; then
            mysql -e "show tables like '%\${3}%'" \${2}
          else
            mysql -e "show tables" \${2}
          fi
        fi ;;
      dump | du)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        else
          DATE=\$(date +%Y%m%d-%H%M)
          # Ha megadott fájlnév is.
          if [ ! -z "\${3}" ]; then
            mysqldump \${2} | gzip > \${3}-$DATE.mysql.gz
          else
            mysqldump \${2} | gzip > \${2}-$DATE.mysql.gz
          fi
        fi ;;
      restore | re)
        if [ -z "\${2}" ]; then echo -e "Database name is missing.\\n\\n\$HELP"
        elif [ -z "\${3}" ]; then echo -e "Dump filename is missing.\\n\\n\$HELP"
        elif [ ! -f "\${3}" ]; then echo -e "Not existing \${3} dump file.\\n\\n\$HELP"
        else
          zcat \${3} | mysql \${2}
        fi ;;
      copy | co)
        if [ -z "\${2}" ]; then echo -e "Undefined source database.\\n\\n\$HELP"
        elif [ -z "\${3}" ]; then echo -e "Undefined destination database.\\n\\n\$HELP"
        else
          mysql -e "drop database if exists \${3}; create database \${3} default character set utf8;"
          # mysqladmin create \${3}
          mysqldump \${2} | mysql \${3}
        fi ;;
    esac
  fi
}
EOF
chown vagrant:vagrant ~vagrant/.zshrc_local

# Edititng .zshrc.
sed -i 's/^\(ZSH_THEME=\).*$/\1"agnoster"\nDEFAULT_USER="vagrant"/gi' ~vagrant/.zshrc
sed -i 's/^\(plugins=\).*$/\1(git common-aliases history rsync ubuntu web-search wd)/gi' ~vagrant/.zshrc
cat >> ~vagrant/.zshrc <<EOF
source ~/.zshrc_local
DEFAULT_USER="vagrant"
EOF


# Install Composer and Drush.
curl -sS https://getcomposer.org/installer | sudo php -- --install-dir=/usr/local/bin --filename=composer
su vagrant <<EOF
/usr/local/bin/composer global require 'drush/drush:7.*'
/usr/local/bin/composer global require squizlabs/PHP_CodeSniffer:\<2
mkdir -p ~vagrant/.drush
cd ~vagrant/.drush
~/.composer/vendor/bin/drush -y pm-download coder registry_rebuild
EOF
