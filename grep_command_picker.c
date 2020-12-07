#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "argument_handler.h"
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

char** regular_or_splitter(char* string_to_grep)
{
    char** or_array;
    char* string1 = strdup(string_to_grep);
    char* string2 = strdup(string_to_grep);
    int i, j, k, first_instance, str1_len, str2_len, start_counting1, start_counting2 = 0;
    for ( i = 0; string1[i] != '\0'; i++ )
    {
        if ((string_to_grep[i] !=  '(') || (first_instance == 1))
        {
        string1[j] = string_to_grep[i];
        string2[k] = string_to_grep[i];
        j++;
        k++;
        first_instance = 1;
        }
        if ((string_to_grep[i] ==  '('))
        {
            i++;
            while(string_to_grep[i] != '|')
            {
                string1[j] = string_to_grep[i];
                j++;
                i++;
            }
            i++;
            while(string_to_grep[i] !=')')
            {
                string2[k] = string_to_grep[i];
                k++;
                i++; 
            }
        }
    }
    or_array[0] = string1;
    or_array[1] = string2;
    return or_array;
}

char* e_get_string_array(char* string_to_grep, char** e_string_array, int array_size, int index)
{
    //declare array ouside of function
    //char ** e_string_array = malloc(ARRAY_BUFFER * sizeof(char*));
    char* current_string = strdup(string_to_grep);
    if (index == 100)
    {
        e_string_array = realloc(e_string_array, (array_size + ARRAY_BUFFER) * sizeof(char*));
        index = 0;
    }
    int i, j = 0;
    for ( i = 0; string_to_grep[i] != '\0'; i++ )
    {
        if ((string_to_grep[i] ==  '\\'))
        {
            string_to_grep = remove_first_instance_of_char(string_to_grep, '//');
        }
        if ((string_to_grep[i] ==  '('))
        {

        }
        if ((string_to_grep[i] ==  ')'))
        {

        }
        if ((string_to_grep[i] ==  '\.'))
        {

        }
        if ((string_to_grep[i] ==  '['))
        {

        }
        if ((string_to_grep[i] ==  ']'))
        {
            
        }
        if  ((string_to_grep[i] ==  '\o'))
        {
            return e_string_array[index] = string_to_grep;
        }
    }
    return e_string_array;
}

void check_for_a_seperation(int* argument_array, char* current_line, char* string_to_grep,
                                                         int* curr_a, bool case_insensitive)
{
    if((strstr_check_case_insensitive(current_line, string_to_grep, case_insensitive) != NULL) 
                                               && (argument_array[A] == 1) && (*curr_a == -1))
        {
            printf("--\n");
            *curr_a -= 1;
        }
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