#ifndef argument_handler_h
#define argument_handler_h
#include <stdio.h>

char* expression_finder(int argc,const char* argv[]);
int* find_operators(int argc,const char* argv[]);
typedef enum operators { A, A_NUM, b, c, i, n, v, x, E, file_exist} operators;

#endif
