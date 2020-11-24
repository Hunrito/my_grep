#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "argument_handler.h"

char* strstr_check_case_insensitive(const char* string1, const char* string2, bool case_insesitive)
{
    if(case_insesitive)
    {
        return (strcasestr(string1, string2));
    }
    else
    {
        return (strstr(string1, string2));
    }
}

int strcmp_check_case_insensitive(char* string1, char* string2, bool case_insesitive)
{
    if(case_insesitive)
    {
        return (strcasecmp(string1, string2));
    }
    else
    {
        return (strcmp(string1, string2));
    }
}

void grep_execution(int* argument_array, char* current_line,const char* string_to_grep, int line_count, int byte_count, int* curr_a)
{
    bool case_insensitive = (argument_array[4] == 1);
    if(argument_array[c] == 1)
    {
        return;
    }
    if(argument_array[n] == 1)
    {
        if(strstr_check_case_insensitive(current_line, string_to_grep, case_insensitive) != NULL)
        {
            printf("%d:",line_count);
        }    
    }
    if(argument_array[b] == 1)
    {
        if(strstr_check_case_insensitive(current_line, string_to_grep, case_insensitive) != NULL)
        {
            printf("%d:",byte_count);
        }
    }
    if(argument_array[A] == 1)
    {
        if(strstr_check_case_insensitive(current_line, string_to_grep, case_insensitive) != NULL)
        {
            *curr_a = argument_array[A_NUM];
        }
        else if(*curr_a != -1)
        {
           *curr_a -= 1;
           
           if(*curr_a == -1)
           {
               printf("--\n");
           }
           else
           {
               printf("%s", current_line);
           }
           
        }
        
    }
    if(argument_array[v] == 1)
    {
        if(strstr_check_case_insensitive(current_line, string_to_grep, case_insensitive) == NULL)
        {
            printf("%s",current_line);
            return;
        }
    }
    if(argument_array[7] == 1)
    {
        char tmp_string[100];
        strcpy(tmp_string, string_to_grep);
        if((strcmp(strcat(tmp_string, "\n"),current_line) == 0))
        {
            printf("%s",current_line);
            return;
        }
        else
        {
            return;
        }
    }
    if(argument_array[8] == 1)
    {

    }
    if(strstr_check_case_insensitive(current_line, string_to_grep, case_insensitive) != NULL)
    {
        printf("%s",current_line);
        return;
    }   
    return;
}