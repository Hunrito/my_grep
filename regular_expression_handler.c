#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regular_expression_handler.h"
#include "string_list_handler.h"

const int MALLOC_SIZE = 100;

char* remove_all_backslash(char* expression)
{
    int i = 0;
    int j = 0;
    for ( i = 0; expression[i] != '\0'; i++ )
    {
        if (expression[i] !=  '\\')
        {
        expression[j++] = expression[i];
        }
    }
    expression[j] = '\0';
    return expression;
}
//works
char* insert_backslash_before_char(char* string, char insert_before_this_char)
{
    int i = 0;
    int j = 0;
    char* s = malloc((strlen(string) + 1) * sizeof(char));
    int first_instance = 0;
    while(string[i]!='\0')
    {
        if(string[i] == '\\')
        {
            s[j] = string[i];
            i++;
            j++;
            s[j] = string[i];
            i++;
        }
        else if((string[i] == insert_before_this_char) && (first_instance == 0))
        {
            first_instance = 1;
            s[j] = '\\';
        }
        else
        {
            s[j] = string[i];
            i++;
        }
        j++;
    }
    s[j] = '\0';
    return s;
}
//works
char* replace_period_with_char(char* string, char char_to_insert)
{
    int i=0;
    int first_period = 0;
    char* s = strdup(string);
    while(s[i]!='\0')
    {
        if((s[i] == '.') && (first_period == 0))
        {
            if(char_to_insert != '.')
            {
                s[i]=char_to_insert;
                first_period = 1;
            }
            else
            {
                s[i] = string[i];
            }
        }
        if (s[i]=='\\')
        {
            i++;
        }
        i++;
    }
    if((char_to_insert == '.') || (char_to_insert == '(') || (char_to_insert == '[') || (char_to_insert == '\\'))
    {
        return insert_backslash_before_char(s, char_to_insert);
    }
    return s;
}
// You must free the result if result is non-NULL.
char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }
    count = 1;
    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}
char** get_strings_from_or(char* string)
{
    int i =0;
    int j = 0;
    int k = 0;
    int l = 0;
    int string_chooser = 0;
    char* string_1 = malloc(sizeof(char)*MALLOC_SIZE);
    char* string_2 = malloc(sizeof(char)*MALLOC_SIZE);
    char* or_argument = malloc(sizeof(char)*MALLOC_SIZE);
    for ( i = 0; string[i] != ')'; i++ )
    {
        if((string[i] == '(') && (string_chooser == 0))
        {
            string_chooser = 1;
            or_argument[l] = string[i];
            l++;
        }
        else if((string[i] != '(') && (string_chooser == 1) && (string[i] != '|'))
        {
            string_1[j] = string[i];
            j++;
            or_argument[l] = string[i];
            l++;
        }
        else if((string[i] == '|') && (string_chooser == 1))
        {
            string_chooser = 2;
            or_argument[l] = string[i];
            l++;
        }
        else if((string[i] != '|') && (string_chooser == 2))
        {
            string_2[k] = string[i];
            k++;
            or_argument[l] = string[i];
            l++;
        }
    }
    string_1[j] = '\0';
    string_2[k] = '\0';
    or_argument[l] = ')';
    or_argument[l+1] = '\0';
    char **or_string_array = (char *[]){string_1, string_2, or_argument};
    return or_string_array;
}

char* get_bracket_expression(char* string)
{
    int i = 0;
    int j = 0;
    int in_brackets = 0;
    char* bracket_expression = malloc (sizeof (char) * MALLOC_SIZE);
    for ( i = 0; string[i] != ']'; i++ )
    {
        if((string[i] == '[') && (in_brackets == 0))
        {
            bracket_expression[j] = string[i];
            j++;
            in_brackets = 1;
        }
        else if(in_brackets == 1)
        {
            bracket_expression[j] = string[i];
            j++;
        }
        if((string[i] == '\\'))
        {
            i++;
        }
    }
    bracket_expression[j] = ']';
    j++;
    bracket_expression[j] = '\0';
    return bracket_expression;
}

char** e_get_string_list(char* string_to_grep, string_list** string_array)
{
    char temp_str1[2];
    char* bracket_expression;
    int i, j = 0;
    int start_bracket, stop_bracket;
    for ( i = 0; string_to_grep[i] != '\0'; i++ )
    {
        if ((string_to_grep[i] ==  '.'))
        {
            for(j = 32; j != 127; j++)
            {
                char* string_helper = replace_period_with_char(string_to_grep, j);
                e_get_string_list(string_helper, string_array);
                free(string_helper);
            }
            return NULL;

        }
        else if ((string_to_grep[i] ==  '('))
        {
            char* string_helper = str_replace(string_to_grep, get_strings_from_or(string_to_grep)[2], get_strings_from_or(string_to_grep)[1]);
            e_get_string_list(string_helper, string_array);
            char* string_helper2 = str_replace(string_to_grep, get_strings_from_or(string_to_grep)[2], get_strings_from_or(string_to_grep)[0]);
            e_get_string_list(string_helper2, string_array);
            free(string_helper);
            free(string_helper2);
            return NULL;
        }
        else if ((string_to_grep[i] ==  '['))
        {
            bracket_expression = get_bracket_expression(string_to_grep);
            start_bracket = bracket_expression[1];
            stop_bracket = bracket_expression[3];
            for(j = start_bracket; j < stop_bracket + 1; j++)
            {
                temp_str1[0] = j;
                temp_str1[1] = 0;
                char* string_helper = str_replace(string_to_grep, bracket_expression, temp_str1);
                e_get_string_list(string_helper, string_array);
                free(string_helper);
            }
            free(bracket_expression);
            return(NULL);
        }
        else if ((string_to_grep[i] ==  '\\'))
        {
            i++;
        }
    }
    string_list *helper = create_node(string_to_grep, (int)strlen(string_to_grep));
    add_node_to_list(helper, string_array);
    return string_array;
}