#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "grep_command_picker.h"
#include "grep_command_picker.h"

const char* file_name_finder(int size, const char* arguments[])
{
    const char* file_name;
    int last_index = size - 1;
    file_name = arguments[last_index];
    return(file_name);
}


int file_to_grep(int* argument_array, char* file_location, char* stdin_line, 
                const char* expression_to_grep, int stdin_count, int byte_count, int* curr_a)
{
    if(file_location == NULL)
    {
        grep_execution(argument_array, stdin_line, expression_to_grep, stdin_count, byte_count, curr_a);
        return 1;
    }
    else
    {
        char *line_buffer = NULL;
        size_t line_buffer_size = 0;
        int line_count = 0;
        ssize_t line_size;
        bool case_insensitive = (argument_array[4] == 1);
        ssize_t byte_count = 0;
        int c_argument_counter = 0;
        FILE *fp = fopen(file_location, "r");
        if (!fp)
        {
            return 0;
        }
        line_size = getline(&line_buffer, &line_buffer_size, fp);
        while (line_size != -1)
        {
            line_count++;
            grep_execution(argument_array, line_buffer,expression_to_grep, line_count, byte_count,curr_a);
            byte_count += line_size;
            line_size = getline(&line_buffer, &line_buffer_size, fp);
            if(strstr_check_case_insensitive(line_buffer, expression_to_grep, case_insensitive) != NULL)
            {
                c_argument_counter++;
            }
        }
        if(argument_array[3] == 1)
        {
            printf("%d\n", c_argument_counter);
        }
        free(line_buffer);
        line_buffer = NULL;
        fclose(fp);
        return 1;    
    }
    
}
