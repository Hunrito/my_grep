#! /usr/bin/env tcsh

./my_grep a ~nimrodav/grep_tests/emptyfile | diff ~nimrodav/grep_tests/emptyfile -

valgrind --quiet --leak-check=yes ./my_grep a ~nimrodav/grep_tests/emptyfile | diff ~nimrodav/grep_tests/emptyfile -
