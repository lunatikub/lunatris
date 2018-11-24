#!/bin/bash

SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=${SCRIPT_DIR}/../..

source ${SCRIPT_DIR}/common.sh

# Directories with sources to check
dir_list=(
    src
    include
    tests
)

ret=0

for dir in ${dir_list[@]}
do
    for file in $(find ${ROOT_DIR}/${dir} -regex ".*\.[c|h][c|h]?")
    do
        astyle_check $file
        [ $? -ne 0 ] && ret=1
    done
done

echo -n "Coding Style: "
[ ${ret} -eq 0 ] && echo "OK" || echo "KO"

exit ${ret}
