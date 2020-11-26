#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grep_command_picker.h"
#include "argument_handler.h"
#include "file_and_stdin_handler.h"
const int MAX_STDIN = 100;


int main(int argc, const char * argv[])
{
    char* file_name;
    char* stdin_line = malloc(MAX_STDIN);
    char* line_eof_helper;
    int read_from_file;
    int *argument_array = { 0 };
    int curr_a = -2;
    argument_array = find_operators(argc, argv);
    read_from_file = argument_array[9];
    char* expression = expression_finder(argc, argv);
    if (read_from_file == 1)
    {
        file_name = file_name_finder(argc,argv);
        file_to_grep(argument_array, file_name, NULL, expression, 0, 0, &curr_a);
    }
    else
    {
        bool case_insensitive = (argument_array[4] == 1);
        int c_argument_counter = 0;
        int stdin_count = 1;
        line_eof_helper = fgets(stdin_line, MAX_STDIN, stdin);
        if(line_eof_helper != NULL)
        {
            stdin_line = line_eof_helper;
        }

        int stdin_bytes = 0;
        while(line_eof_helper != NULL)
        {
            file_to_grep(argument_array, NULL, stdin_line, expression, stdin_count, stdin_bytes, &curr_a);
            stdin_bytes += sizeof(stdin_line);
            
            if(strstr_check_case_insensitive(stdin_line, expression, case_insensitive) != NULL)
            {
                c_argument_counter++;
            }
            line_eof_helper = fgets(stdin_line, MAX_STDIN, stdin);
            stdin_count++;

             if(line_eof_helper != NULL)
             {
                stdin_line = line_eof_helper;
             }
             
        }

        if(argument_array[3] == 1)
        {
            printf("%d\n", c_argument_counter);
        }
    }
    free(expression);
    free(stdin_line);
    return 0;
}
