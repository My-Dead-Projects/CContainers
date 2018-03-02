#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct _listNode
{
    struct _listNode * next;
    void * data;
} ListNode;

typedef struct
{
    ListNode * m_head, * m_tail;
    unsigned m_size;
} List;

typedef struct
{
    ListNode * m_node;
} ListIterator;

typedef void (*destructor)(void *);
typedef void (*iterator)(void *);

ListNode * ListNode_init(void * data);

List List_construct();

void List_append(List * list, void * element);

void List_dropHead(List * list, destructor destruct);

void List_destruct(List * list, destructor destruct);

void List_iterate(List * list, iterator iterate);

ListIterator List_begin(List * list);

void * ListIterator_get(ListIterator * iter);

void ListIterator_next(ListIterator * iter);
