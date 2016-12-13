#!/bin/bash
# This can be used like this:
# ./getReleaseTickets.sh master release/1 1.5 25
# Then it will show all the links.

echo Please make sure your local versions are up to date.

SOURCE=$1
TARGET=$2
RELEASE=$3
PR=$4

echo " "
echo "#########################################"
echo Issues in $TARGET going into $SOURCE:
echo "#########################################"

LOGS=$(git log $SOURCE..$TARGET --oneline)
LIST=$(echo $LOGS | grep -Eo "DTTSB-[0-9]{1,5}" | sort -u)

while read -r line; do
  echo "https://webgate.ec.europa.eu/CITnet/jira/browse/$line"
done <<< "$LIST"

# Check the features that changed
MODIFIEDFILES=$(git diff $SOURCE..$TARGET --ignore-blank-lines | grep -e "\-\-\- a/lib/features/")
MODIFIEDFILES+=$(git diff $SOURCE..$TARGET --ignore-blank-lines | grep -e "\-\-\- a/lib/modules/")
MODIFIEDFILES+=$(git diff $SOURCE..$TARGET --ignore-blank-lines | grep -e "\-\-\- a/lib/themes/")

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PARENTDIR="$(dirname "$DIR")"

echo " "
echo "#########################################"
echo "The following features have been updated:"
echo "#########################################"

php -f "$PARENTDIR/resources/scripts/other/ReleasePreparation.php" -- "UpdatedFeatures" "$MODIFIEDFILES" "$RELEASE" "$PR"

