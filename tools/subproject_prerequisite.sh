#!/bin/bash

# Prerequisites for the subproject:
# + create the tarball in subprojects directory
# + create the wrap file from wrap.in in subproject directory
#
# usage: ./subproject_prerequisite.sh <subproject_name> <subproject_version>

NAME=$1
VERSION=$2
DIRECTORY=$3

SCRIPT_NAME=./$(basename $0)
SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=${SCRIPT_DIR}/..

err()
{
    local line=$1
    local msg=$2

    echo "${SCRIPT_NAME} error (line:${line}): $msg..." 2>&1
    exit 1
}

[ -z "${NAME}" ] && err $LINENO "name arg empty"
[ -z "${VERSION}" ] && err $LINENO "version arg empty"
[ -z "${DIRECTORY}" ] && err $LINENO "directory arg empty"

DEPS=${ROOT_DIR}/deps
SUBPROJECT=${ROOT_DIR}/subprojects

[ ! -d "${SUBPROJECT}" ] && err $LINENO "subproject directory doesn't exist"
[ ! -d "${DEPS}" ] && err $LINENO "deps directory doesn't exist"

IN_WRAP=${DEPS}/${NAME}.wrap.in
OUT_WRAP=${SUBPROJECT}/${NAME}.wrap

[ ! -f "${IN_WRAP}" ] && err $LINENO "file ${IN_WRAP} doesn't exist"

patch_filename="meson-${NAME}-${VERSION}.tar.gz"

pushd ${DEPS}
tar cfz ${patch_filename} ${DIRECTORY}
sha256=$(sha256sum ${patch_filename} | cut -d' ' -f1)
mv ${patch_filename} ${SUBPROJECT}
popd

sed -e "s,@@PATCH_URL@@,file:subprojects/${patch_filename}," \
    -e "s,@@PATCH_FILENAME@@,${patch_filename}," \
    -e "s,@@PATCH_HASH@@,${sha256}," \
    -e "s,@@DIRECTORY@@,${DIRECTORY}," \
    ${IN_WRAP} > ${OUT_WRAP}

exit 0
