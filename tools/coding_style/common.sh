#!/bin/bash

ASTYLE_OPTIONS="
        -n \
        --style=stroustrup \
        --style=otbs \
        --indent=spaces=2 \
        --indent-switches \
        --indent-preproc-block \
        --indent-col1-comments \
        --pad-oper \
        --pad-header \
        --convert-tabs \
        --max-code-length=100 \
        --break-after-logical"

astyle_apply()
{
    local file=$1
    ${ASTYLE} ${ASTYLE_OPTIONS} ${file}
}

astyle_check()
{
    local file=$1
    local ret=0

    ${ASTYLE} ${ASTYLE_OPTIONS} < ${file} | cmp -s ${file} -
    ret=$?

    if [ ${ret} -ne 0 ]
    then
        echo "'${file}' doesn't respect coding style..." >&2
        ret=1
    fi

    return ${ret}
}

err()
{
    local line=$1
    local msg=$2

    echo "${SCRIPT_NAME} error (line:${line}): $msg..." >&2
    exit 1
}

ASTYLE=$(which astyle)
if [ $? -ne 0 ]; then
    err $LINENO "[!] astyle not installed. Unable to check source file format policy."
fi
