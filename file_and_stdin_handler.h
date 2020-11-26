#ifndef file_and_stdin_handler_h
#define file_and_stdin_handler_h

char* file_name_finder(int size, const char* arguments[]);
int file_to_grep(int* argument_array, char* file_location, char* stdin_line, 
                char* expression_to_grep, int stdin_count, int byte_count, int* curr_a);

#endif
