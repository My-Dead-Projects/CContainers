#include <stdlib.h>
#include <stdio.h>
#include "List.h"

void * allocate_int(int n);
void iterPrint_int(void *i);

int main()
{
    List list = List_construct();

    List_append(&list, allocate_int(5));

    List_append(&list, allocate_int(10));

    List_append(&list, allocate_int(8));

    List_append(&list, allocate_int(2));

    List_iterate(&list, iterPrint_int);

    printf("\n");

    List_dropHead(&list, free);

    List_iterate(&list, iterPrint_int);

    List_destruct(&list, free);

    List_iterate(&list, iterPrint_int);

    return 0;
}

void * allocate_int(int n)
{
    int * i = malloc(sizeof(int));
    *i = n;
    return i;
}

void iterPrint_int(void * i)
{
    printf("%d\n", *(int *)i);
}
