#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "dl_list.h"

void list_init (List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void list_insert (List *list, int value, const size_t* index)
{
    if (!index) { return; }
    if (!*index)
    {
        list_insert_first(list, value);
        return;
    }
    if (*index == list->length - 1)
    {
        list_insert_last(list, value);
        return;
    }
    size_t cur_index = 0;
    Node *cur_node;
    cur_node = list->head;
    while (cur_index < *index) {
        cur_node = cur_node->next;
        cur_index++;
    }
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->prev = cur_node->prev;
    node->next = cur_node;

    cur_node->prev->next = node;
    cur_node->prev = node;

    list->length++;
}

void list_insert_first (List *list, int value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->prev = NULL;

    if (list->length) {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    } else {
        list->head = node;
        list->tail = list->head;
        node->next = NULL;
    }
    list->length++;
}

void list_insert_last (List *list, int value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;

    if (list->length) {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    } else {
        node->prev = list->head;
        list->head = node;
        list->tail = list->head;
    }
    node->next = NULL;
    list->length++;
}

void list_print_connections (List *list)
{
    printf("\nList length: %zu\n", list->length);
    Node *cur_node;
    cur_node = list->head;
    do {
        printf("%d <=> ", cur_node->value);
        cur_node = cur_node->next;
    } while (cur_node->next);
    printf("%d\n", cur_node->value);
}

Node* list_get(List* list, const size_t* index)
{
    size_t cur_index;
    Node *cur_node;
    if (*index < list->length / 2) {
        cur_index = 0;
        cur_node = list->head;
        while (cur_index < *index) {
            cur_node = cur_node->next;
            cur_index++;
        }
    } else {
        cur_index = list->length - 1;
        cur_node = list->tail;
        while (cur_index > *index) {
            cur_node = cur_node->prev;
            cur_index--;
        }
    }
    return cur_node;
}

int list_get_value(List* list, const size_t* index)
{
    return list_get(list, index)->value;
}

void list_remove(List *list, const size_t* index)
{
    size_t cur_index;
    Node *cur_node;
    if (*index < list->length / 2) {
        cur_index = 0;
        cur_node = list->head;
        while (cur_index < *index) {
            cur_node = cur_node->next;
            cur_index++;
        }
    } else {
        cur_index = list->length - 1;
        cur_node = list->tail;
        while (cur_index > *index) {
            cur_node = cur_node->prev;
            cur_index--;
        }
    }
    cur_node->prev->next = cur_node->next;
    cur_node->next->prev = cur_node->prev;
    list->length--;
}

void list_remove_first(List *list)
{
    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;
    list->length--;
}

void list_remove_last(List *list)
{
    list->tail = list->tail->prev;
    free(list->tail->next);
    list->tail->next = NULL;
    list->length--;
}
