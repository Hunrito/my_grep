#ifndef grep_command_picker_h
#define grep_command_picker_h
#include <stdbool.h>

void grep_execution(int* argument_array, char* current_line,const char* string_to_grep, int line_count, int byte_count, int* curr_a);
char* strstr_check_case_insensitive(const char* string1, const char* string2, bool case_insesitive);

#endif
