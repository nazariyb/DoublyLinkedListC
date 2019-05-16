#include <stdio.h>
#include "dl_list.h"


int main ()
{
    List list;
    list_init(&list);
    printf("list size: %zu\n", list.length);

    list_insert_last (&list, 10);
    printf("list size: %zu\n", list.length);
    printf("list head: %d\n", list.head->value);
    printf("list tail: %d\n", list.tail->value);

    list_insert_last (&list, 20);
    printf("list size: %zu\n", list.length);
    printf("list head: %d\n", list.head->value);
    printf("list tail: %d\n", list.tail->value);

    list_print_connections(&list);

    list_insert_last (&list, 30);
    printf("list size: %zu\n", list.length);
    printf("list head: %d\n", list.head->value);
    printf("list middle: %d\n", list.head->next->value);
    printf("list tail: %d\n", list.tail->value);

    list_print_connections(&list);

    list_insert_first(&list, -10);
    list_print_connections(&list);

    list_insert_first(&list, -20);
    list_print_connections(&list);

    size_t two = 2;
    list_insert(&list, 5, &two);
//    printf("list size: %zu\n", list.length);
//    printf("list head: %d\n", list.head->value);
//    printf("list 1: %d\n", list.head->next->value);
//    printf("list 2: %d\n", list.head->next->next->value);
//    printf("list 3: %d\n", list.head->next->next->next->value);
//    printf("list 4: %d\n", list.head->next->next->next->next->value);
//    printf("list tail: %d\n", list.tail->value);
    list_print_connections(&list);

    size_t zero = 0;
    list_insert(&list, -5, &zero);
    list_print_connections(&list);

    printf("\nval first: %d\n", list_get_value(&list, &zero));
    size_t four = list.length - 1;
    printf("\nval last: %d\n", list_get_value(&list, &four));

    list_print_connections(&list);
    list_remove_last(&list);
    list_print_connections(&list);
    size_t last = list.length - 1;
    printf("\nval last: %d\n", list_get_value(&list, &last));

    list_print_connections(&list);
    list_remove_first(&list);
    list_print_connections(&list);
    printf("\nval first: %d\n", list_get_value(&list, &zero));

    last = list.length - 1;
    size_t one = 0;
    printf("\nval 0: %d\n", list_get_value(&list, &one));
    ++one;
    printf("\nval 1: %d\n", list_get_value(&list, &one));
    ++one;
    printf("\nval 2: %d\n", list_get_value(&list, &one));
    ++one;
    printf("\nval 3: %d\n", list_get_value(&list, &one));
    ++one;
    printf("\nval 4: %d\n", list_get_value(&list, &one));

    list_print_connections(&list);
    --one;
    --one;
    printf("del %zu", one);
    list_remove(&list, &one);
    list_print_connections(&list);

    return 0;
}