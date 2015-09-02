#!/bin/bash

# Global settings.
STARTERKIT_FEATURE_NAME="dt_STARTERKIT"
STARTERKIT_FEATURE_TITLE="STARTERKIT_FEATURE_TITLE"
STARTERKIT_CONTENT_NAME="STARTERKIT_CONTENT_NAME"
STARTERKIT_CONTENT_HUMAN_NAME="STARTERKIT_CONTENT_HUMAN_NAME"
STARTERKIT_FEATURE_TITLE="STARTERKIT_FEATURE_TITLE"
STARTERKIT_FEATURE_DESCRIPTION="STARTERKIT_FEATURE_DESCRIPTION"
STARTERKIT_PACKAGE_NAME="STARTERKIT_PACKAGE_NAME"
STARTERKIT_DEFAULT="DEFAULT"
DEFAULT_POSTFIX="default"
INFO_POSTFIX="info"
POLITICAL_POSTFIX="pol"

# Defaults
IS_INFO_INSTANCE=false
IS_POLITICAL_INSTANCE=false
PACKAGE_NAME="NextEuropa Digital Transformation"

usage() {
  cat <<EOF
  Usage:
    `basename $0` -f <feature_machine_name> -n <content_type_machine_name> -t <feature_human_title> -d <description> -c <content_type_machine_name>

  Parameters:
    -f <feature_machine_name>
      The machine name of feature module.
      Mandatory, like: "dt_department".
    -n <content_type_machine_name>
      Machine name of the content type.
      Mandatory, e.g.: "department"
    -t <feature_human_title>
      This is the name of feature displaying for users.
      Mandatory, e.g.: "Department content type".
    -d <description>
      Feature description.
      Optional, default: "Description"
    -c <content_type_human_name>
      Content human readable name.
      Optional, default: <content_type_machine_name> first character upppercase.
    -k <feature_package_name>
      Package human readable name.
      Optional, default: "NextEuropa Digital Transformation".
    -i
      Creating info site instance as a subfeature.
      Optional switch.
    -p
      Creating political site instance as a subfeature.
      Optional switch.
    -h
      Displaying this message as help.

  Please go into the suitable folder, like:
    - "project/modules/features/custom" or
    - "build/sites/project/modules/features/custom".
  Running the script:
    ../../../../bin/`basename $0`

  Example:
    `basename $0` -f "dt_department" -n "department" -t "DT Department" -d "DT Department content type" -c "Department" -p
      Creates a "Department" content type feature with the given description.
      The content type machine name will be "department" and the feature name is "dt_department".

EOF
}

parameter_checking() {
  # Mandatory parameters.
  if [ -z "${FEATURE_TITLE}" ] || [ -z "${CONTENT_NAME}" ] || [ -z "${FEATURE_NAME}" ]; then
    usage
    echo "Error: Missing mandatory parameter."
    echo "Feature machine name (-f): ${FEATURE_NAME}"
    echo "Content type machine name (-n): ${CONTENT_NAME}"
    echo "Feature human title (-t): ${FEATURE_TITLE}"
    exit 1
  fi
  # Checking if feature directory exists.
  if [ -d "${FEATURE_NAME}" ]; then
    usage
    echo -e "Error: ${FEATURE_NAME} directory already exists.\n"
    exit 1
  fi

  # Check the content human name is given.
  if [ -z "${CONTENT_HUMAN_NAME}" ]; then
    CONTENT_HUMAN_NAME="${CONTENT_NAME^}"
  fi

  if [ ! -d "${STARTERKIT_FEATURE_NAME}" ]; then
    usage
    echo "Error: STARTERKIT directory is not exists."
    exit 1
  fi
}

create_subfeature() {
  IS_INSTANCE="${1}"
  INSTANCE_POSTFIX="${2}"
  # Info instance.
  if [ "${IS_INSTANCE}" = true ]; then
    echo "Site instance setup: ${INSTANCE_POSTFIX}."
    SOURCE_DIR="${STARTERKIT_FEATURE_NAME}_${STARTERKIT_DEFAULT}"
    INSTANCE_DIR="${FEATURE_NAME}_${INSTANCE_POSTFIX}"
    cp -a ${SOURCE_DIR} ${INSTANCE_DIR}
    cd ${INSTANCE_DIR}
    find . -type f -exec sed -i "s|${STARTERKIT_DEFAULT}|${INSTANCE_POSTFIX}|g" {} \;
    for D in $(find . -type f -and -name "*${STARTERKIT_DEFAULT}*"); do
      mv "${D}" "`echo ${D} | sed s/${STARTERKIT_DEFAULT}/${INSTANCE_POSTFIX}/`"
    done
    cd ..
  fi
}

while getopts ":f:n:t:d:c:k:iph" opt; do
  case $opt in
    f) FEATURE_NAME=$OPTARG; if [[ $OPTARG = -* ]]; then ((OPTIND--)); continue; fi;;
    n) CONTENT_NAME=$OPTARG; if [[ $OPTARG = -* ]]; then ((OPTIND--)); continue; fi;;
    t) FEATURE_TITLE=$OPTARG; if [[ $OPTARG = -* ]]; then ((OPTIND--)); continue; fi;;
    d) FEATURE_DESCRIPTION=$OPTARG; if [[ $OPTARG = -* ]]; then ((OPTIND--)); continue; fi;;
    c) CONTENT_HUMAN_NAME=$OPTARG; if [[ $OPTARG = -* ]]; then ((OPTIND--)); continue; fi;;
    k) PACKAGE_NAME=$OPTARG; if [[ $OPTARG = -* ]]; then ((OPTIND--)); continue; fi;;
    i) IS_INFO_INSTANCE=true;;
    p) IS_POLITICAL_INSTANCE=true;;
    h) usage; exit 0;;
    \?) usage; echo -e "\nError: Invalid option." >&2; exit 1;;
    :) usage; echo -e "\nError: Option -$OPTARG requires an argument." >&2; exit 1;;
  esac
done
parameter_checking

# ------------------------------------------------------------------------------
# Copy skeleton.
cp -a ${STARTERKIT_FEATURE_NAME} ${FEATURE_NAME}
cd ${FEATURE_NAME}

create_subfeature true ${DEFAULT_POSTFIX}
create_subfeature ${IS_INFO_INSTANCE} ${INFO_POSTFIX}
create_subfeature ${IS_POLITICAL_INSTANCE} ${POLITICAL_POSTFIX}

# Removing starterkit default dir, no longer necessary to be.
RMDIR="${STARTERKIT_FEATURE_NAME}_${STARTERKIT_DEFAULT}"
rm -rf ${RMDIR}

# Renaming directories.
for D in $(find . -type d -and -name "${STARTERKIT_FEATURE_NAME}*"); do
  echo "${D}"
  mv "${D}" "`echo ${D} | sed s/${STARTERKIT_FEATURE_NAME}/${FEATURE_NAME}/`"
done

# Renaming files.
for F in $(find . -type f -and -name "${STARTERKIT_FEATURE_NAME}*"); do
  mv "${F}" "`echo ${F} | sed s/${STARTERKIT_FEATURE_NAME}/${FEATURE_NAME}/`"
done

# Replacing dt_skeleton to machine name.
SED="
s|${STARTERKIT_FEATURE_NAME}|${FEATURE_NAME}|g
s|${STARTERKIT_CONTENT_NAME}|${CONTENT_NAME}|g
s|${STARTERKIT_CONTENT_HUMAN_NAME}|${CONTENT_HUMAN_NAME}|g
s|${STARTERKIT_FEATURE_TITLE}|${FEATURE_TITLE}|g
s|${STARTERKIT_FEATURE_DESCRIPTION}|${FEATURE_DESCRIPTION}|g
s|${STARTERKIT_PACKAGE_NAME}|${PACKAGE_NAME}|g
"
find . -type f -exec sed -i "${SED}" {} \;
