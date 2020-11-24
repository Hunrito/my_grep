#! /usr/bin/env tcsh

./my_grep bla ~nimrodav/grep_tests/3lines | diff ~nimrodav/grep_tests/out3 -

valgrind --quiet --leak-check=yes ./my_grep bla ~nimrodav/grep_tests/3lines | diff ~nimrodav/grep_tests/out3 -

