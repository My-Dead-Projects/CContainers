#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "HashSet.h"

void * int_allocate(int n);
void int_print(void *i);
void * IntStrPair_allocate(int i, char *str, bool heapStr);
void IntStrPair_destruct(void * data);
void IntStrPair_print(void *pair);
size_t IntStrPair_hash(void *data);
bool IntStrPair_equal(void * a, void * b);

typedef struct {
    int i;
    char * str;
    bool heapStr;
} IntStrPair;

int main()
{
    List list = List_construct();

    List_append(&list, int_allocate(5));

    List_append(&list, int_allocate(10));

    List_append(&list, int_allocate(8));

    List_append(&list, int_allocate(2));

    List_iterate(&list, int_print);

    printf("\n");

    List_dropHead(&list, free);

    List_iterate(&list, int_print);

    List_destruct(&list, free);

    List_iterate(&list, int_print);

    printf("\n");

    HashSet map = HashSet_construct(IntStrPair_hash);

    HashSet_insert(&map, IntStrPair_allocate(5, "five", false));

    HashSet_insert(&map, IntStrPair_allocate(3, "three", false));

    HashSet_insert(&map, IntStrPair_allocate(10, "ten", false));

    HashSet_insert(&map, IntStrPair_allocate(110, "one hundred and ten", false));

    HashSet_iterate(&map, IntStrPair_print);

    printf("\n");

    IntStrPair * three = HashSet_find(&map, IntStrPair_allocate(3, NULL, false),
                                      IntStrPair_equal);
    IntStrPair_print(three);

    IntStrPair * ten = HashSet_find(&map, IntStrPair_allocate(10, NULL, false),
                                    IntStrPair_equal);
    IntStrPair_print(ten);

    IntStrPair * oneTen = HashSet_find(&map, IntStrPair_allocate(110, NULL, false),
                                       IntStrPair_equal);
    IntStrPair_print(oneTen);

    HashSet_destruct(&map, IntStrPair_destruct);

    return 0;
}

void * int_allocate(int n)
{
    int * i = malloc(sizeof(int));
    *i = n;
    return i;
}

void * IntStrPair_allocate(int i, char *str, bool heapStr)
{
    IntStrPair * pair = malloc(sizeof(IntStrPair));
    pair->i = i;
    pair->str = str;
    pair->heapStr = heapStr;
    return pair;
}

void int_print(void *i)
{
    printf("%d\n", *(int *)i);
}

void IntStrPair_print(void *pair)
{
    IntStrPair * p = (IntStrPair *)pair;
    printf("{ %d, %s }\n", p->i, p->str);
}

size_t IntStrPair_hash(void *data)
{
    return (size_t)((IntStrPair *)data)->i;
}

void IntStrPair_destruct(void * data)
{
    IntStrPair * pair = (IntStrPair *)data;
    if (pair->heapStr)
        free(pair->str);
    free(pair);
}

bool IntStrPair_equal(void * a, void * b)
{
    return ((IntStrPair *)a)->i == ((IntStrPair *)b)->i;
}
