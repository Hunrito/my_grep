#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "argument_handler.h"
#include "string_list_handler.h"
#include "regular_expression_handler.h"

const int ARRAY_BUFFER = 100;

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
char* remove_first_instance_of_char(char* expression, char char_to_remove)
{
    int i, j, first_instance = 0;
    for ( i = 0; expression[i] != '\0'; i++ )
    {
        if ((expression[i] !=  char_to_remove) || (first_instance == 1))
        {
        expression[j++] = expression[i];
        first_instance = 1;
        }
    }
    expression[j] = '\0';
    return expression;
}

char* remove_substring_from_string(char* string, char* substring)
{
    char *p, *q, *r;
    if ((q = r = strstr(string, substring)) != NULL) {
        size_t len = strlen(substring);
        while ((r = strstr(p = r + len, substring)) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    return string;
}

void grep_execution(int* argument_array, char* current_line, char* string_to_grep,
                                     int line_count, int byte_count, int* curr_a)
{
    bool case_insensitive = (argument_array[4] == 1);
    if(argument_array[E] == 1)
    {
        //string_to_grep = remove_backslash(string_to_grep);
    }
    if(argument_array[c] == 1)
    {
        return;
    }
    check_for_a_seperation(argument_array, current_line, string_to_grep, curr_a, case_insensitive);
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
        else if(*curr_a > -1)
        {
           *curr_a -= 1;
           
           if(*curr_a != -1)
           {
               if (argument_array[n] == 1)
               {
                   printf("%d-",line_count);
               }
               if (argument_array[b] == 1)
               {
                   printf("%d-",byte_count);
               }
               printf("%s", current_line);
           }
        }       
    }
    if(argument_array[v] == 1)
    {
        if(strstr_check_case_insensitive(current_line, string_to_grep, case_insensitive) != NULL)
        {
            return;
        }
        else
        {
            printf("%s",current_line);
            return;
        }
    }
    if(argument_array[x] == 1)
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
    if(strstr_check_case_insensitive(current_line, string_to_grep, case_insensitive) != NULL)
    {
        printf("%s",current_line);
        return;
    }   
    return;
}