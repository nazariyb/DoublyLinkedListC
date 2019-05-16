#ifndef DL_LIST_DL_LIST_H
#define DL_LIST_DL_LIST_H

typedef struct list_node
    {
    int value;
    struct list_node *prev;
    struct list_node *next;
    } Node;

typedef struct dl_list
    {
    Node *head;
    Node *tail;
    size_t length;
    } List;

void list_init (List* list);
void list_insert (List *list, int value, const size_t* index);
void list_insert_first (List *list, int value);
void list_insert_last (List *list, int value);
void list_print_connections (List *list);
Node* list_get(List* list, const size_t* index);
int list_get_value(List* list, const size_t* index);
void list_remove(List *list, const size_t* index);
void list_remove_first(List *list);
void list_remove_last(List *list);

#endif //DL_LIST_DL_LIST_H
