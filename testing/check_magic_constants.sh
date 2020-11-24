#! /usr/bin/env bash

grep -H -n -E "([0-9][0-9]|[3-9])" *.c | grep -v "#define" | grep -v "_test\.c" | grep -v "http://" | grep -v "https://" | grep -v "int32_t" | grep -v "int64_t"

if ls *.h 1> /dev/null 2>&1; then
    grep -H -n -E "([0-9][0-9]|[3-9])" *.h | grep -v "#define" | grep -v "int32_t" | grep -v "int64_t"
fi
