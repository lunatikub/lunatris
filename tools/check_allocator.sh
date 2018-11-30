#!/bin/bash

# Detect usage of malloc, calloc and free instead of
# MALLOC, CALLOC and FREE.
# realloc is forbidden.

SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=${SCRIPT_DIR}/..

ret=0

echo "Command to reproduce:"
echo "grep -En \"[ )](free|malloc|calloc)\(.*;$\" <file>"
echo ""

for file in $(find ${ROOT_DIR}/src -regex "^[^#]*\.[c|h]")
do
    # excluse 'memory.c'
    [ "$(basename ${file})" = "memory.c" ] && continue

    line=$(grep -En "[ )](free|malloc|calloc)\(.*;$" ${file})
    [ $? -eq 0 ] && echo "${file}: KO" >&2
done

echo -n "check allocator: "
[ ${ret} -eq 0 ] && echo "OK" || echo "KO"

exit ${ret}
