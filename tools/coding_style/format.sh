#!/bin/bash

SRC_FILE=$1

SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=${SCRIPT_DIR}/../..

source ${SCRIPT_DIR}/common.sh

[ -z "${SRC_FILE}" ] && err ${LINENO} "Source arg is empty"
[ ! -f "${SRC_FILE}" ] && err ${LINENO} "File ${SRC_FILE} doesn't exist"

astyle_apply $1

exit 0
