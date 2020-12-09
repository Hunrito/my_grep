#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "string_list_handler.h"

#define BUFFER 5
string_list *create_node(char *string_to_add, int array_size)
{
    string_list *node = (string_list*)malloc(sizeof(string_list));
    
    node->current_string = (char *)malloc((strlen(string_to_add) + BUFFER) * sizeof(char));
    strcpy(node->current_string, string_to_add);
    node->next = NULL;
    node->array_size = array_size;
    return (node);
}

void to_lower_case(string_list *string_to_search)
{
    string_list *head = string_to_search;
    
    while (head != NULL)
    {
        //toLowerCase(head->current_string);
        head = head->next;
    }
}

void free_string_list(string_list *string_to_search)
{
    while(string_to_search != NULL)
    {
        free(string_to_search->current_string);
        string_list *helper = string_to_search->next;
        free(string_to_search);
        string_to_search = helper;
    }
}

void add_node_to_list(string_list *current_node, string_list **p_head)
{
    string_list *temp_node = *p_head;
    if (temp_node == NULL)
    {
        *p_head = current_node;
    }
    else
    {
        while (temp_node->next != NULL)
        {
            temp_node = temp_node->next;
        }
        
        temp_node->next = current_node;
    }
}

void print_list(string_list **p_head)
{
    string_list *temp_node = *p_head;
    
    while (temp_node != NULL)
    {
        printf("%s\n",temp_node->current_string);
        temp_node = temp_node->next;
    }
}