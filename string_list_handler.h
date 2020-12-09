#ifndef string_list_handler_h
#define string_list_handler_h

typedef struct string_list
{
    char *current_string;
    int array_size;
    struct string_list *next;
}string_list;

string_list *create_node(char *string_to_add, int array_size);
void to_lower_case_list(string_list *string_to_search);
void free_string_list(string_list *string_to_search);
void add_node_to_list(string_list *current_node, string_list **p_head);
void print_list(string_list **p_head);

#endif
