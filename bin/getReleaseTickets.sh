#!/bin/bash
# This can be used like this:
# ./getReleaseTickets.sh master release/1
# Then it will show all the links.

SOURCE=$1
TARGET=$2

echo Issues in $TARGET going into $SOURCE:

LOGS=$(git log $SOURCE..$TARGET --oneline)
LIST=$(echo $LOGS | grep -Eo "DTTSB-[0-9]{1,5}" | sort -u)

while read -r line; do
  echo "https://webgate.ec.europa.eu/CITnet/jira/browse/$line"
done <<< "$LIST"

