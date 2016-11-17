#
# This script helps to prepare production dumps for acquia usage.
#
# Dumps should be put in tmp/dumps.
#
# It is best to test it local first.
#
clear

function printcolor {
  printf "\033[0;31m$1\033[0m\n"
}

## Defining variables.
DBUSER=root
DBPASS=""
DBNAME=tmpdbprtbl
DBHOST=127.0.0.1
VERBOSE="" #--verbose
BAZOOKA="" #--fire-bazooka

## File selection.
prompt="Please select a file:"
tmp_path="$( cd "$(dirname $(dirname "${BASH_SOURCE}"))" ; pwd -P )/tmp"
options=( $(ls $tmp_path/dumps/*.sql | xargs -n 1 basename) )

PS3="$prompt "
select opt in "${options[@]}" "Quit" ; do
    if (( REPLY == 1 + ${#options[@]} )) ; then
        exit
    elif (( REPLY > 0 && REPLY <= ${#options[@]} )) ; then
        break
    else
        echo "Invalid option. Try another one."
    fi
done

## Use mysql password only if set.
if (( $DBPASS -ne "" )) ; then
    $DBPASS = "-p$DBPASS"
fi

## Processing the files.
printcolor "## Starting to process <<< $opt >>>"
printcolor "## Please note that this operation might take a long time depending on the size of the database."
printcolor "## Notify the team to avoid deployments and that the target instance will be down during this operation."

printcolor "\n## Creating temporary database: $DBNAME"
mysqladmin -u $DBUSER $DBPASS create $DBNAME

printcolor "\n## Importing database file: $opt into $DBNAME"
mysql -u $DBUSER $DBPASS $DBNAME < $tmp_path/dumps/$opt

printcolor "\n## Sanitizing database (empty's passwords and e-mail)"
mysql -u $DBUSER $DBPASS $DBNAME -e "UPDATE users SET pass='pass', mail='mail@mail.mail'"

printcolor "\n## Rename fpfis-admin to admin"
mysql -u $DBUSER $DBPASS $DBNAME -e "UPDATE users SET name='admin' where name='fpfis-admin'"

printcolor "\n## Disabling ECAS"
mysql -u $DBUSER $DBPASS $DBNAME -e "UPDATE system SET status=0 where name like \"%ecas%\""

printcolor "\n## Disabling other modules by the platform"
mysql -u $DBUSER $DBPASS $DBNAME -e "UPDATE system SET status=0 where name like \"%gelf_log%\""
mysql -u $DBUSER $DBPASS $DBNAME -e "UPDATE system SET status=0 where name like \"%skippy_cookie%\""

printcolor "\n## Truncate cache tables"
list="cache cache_block cache_bootstrap cache_field cache_filter cache_form cache_image cache_menu cache_page cache_path cache_token cache_update"
for varname in $list; do
  echo "> Truncating $varname"
  mysql -u $DBUSER $DBPASS $DBNAME -e "TRUNCATE TABLE $varname;"
done

printcolor "\n## Dumping the ac ready db to: $tmp_path/ready/$opt"
mkdir -p $tmp_path/ready
mysqldump -u $DBUSER $DBPASS --no-create-db $DBNAME > $tmp_path/ready/$opt

printcolor "\n## Uploading the database to the remote"
prompt="Please choose the target alias:"
options=( $(drush sa) )

PS3="$prompt "
select alias in "${options[@]}" "Quit" ; do
    if (( REPLY == 1 + ${#options[@]} )) ; then
        exit
    elif (( REPLY > 0 && REPLY <= ${#options[@]} )) ; then
        break
    else
        echo "Invalid option. Try another one."
    fi
done

LOCALBCK=$(sed 's/@/backup-/g' <<< $alias)
mkdir -p $tmp_path/backup

printcolor "\n### Creating remote datbase dump in $tmp_path/backup/$LOCALBCK.sql"
drush $alias $VERBOSE sql-dump > $tmp_path/backup/$LOCALBCK.sql

printcolor "\n### Dropping remote database"
printf 'y' | drush $VERBOSE $alias sql-drop

printcolor "\n### Restoring the new database to the remote"
drush $alias $VERBOSE sql-cli < $tmp_path/ready/$opt

printcolor '\n## Registry rebuild'
drush $alias $VERBOSE rr $BAZOOKA

printcolor '\n## Clear caches'
drush $alias $VERBOSE cc all

printcolor '\n## Running updates'
drush $alias $VERBOSE updb -y

printcolor '\n## Reverting features'
drush $alias $VERBOSE frdt -y
drush $alias $VERBOSE frcwt -y

printcolor '\n## Setting variables, passwords and test users'
commands=(
"vset file_public_path sites/default/files"
"vset file_private_path sites/default/files/private_files"
"vset file_temporary_path sites/default/files/tmp"
"upwd --password=\"ECBeta123?\" admin"
"ucrt editor_test"
"upwd --password=\"testing123\" editor_test"
"user-add-role editor editor_test"
"ucrt site_manager"
"upwd --password=\"testing123\" site_manager"
"user-add-role editor site_manager"
"user-add-role \"site manager\" site_manager"
"upwd --password=\"ECBeta123?\" admin"
"ucrt agenda_validator"
"upwd --password=\"testing123\" agenda_validator"
"user-add-role \"agenda validator\" agenda_validator"
"ucrt draft_viewer"
"upwd --password=\"testing123\" draft_viewer"
"user-add-role \"draft viewer\" draft_viewer"
)

for command in "${commands[@]}"; do
    printcolor "> Running $command"
    eval "drush $alias $VERBOSE $command"
done

printcolor "\n## Dropping temporary database: $DBNAME"
printf 'y' | mysqladmin -u $DBUSER $DBPASS drop $DBNAME
