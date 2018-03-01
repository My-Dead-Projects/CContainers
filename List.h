#pragma once

#include <stdlib.h>

typedef struct _listNode {
    struct _listNode * next;
    void * data;
} ListNode;

typedef struct {
    ListNode * m_head, * m_tail;
    unsigned m_size;
} List;

typedef void (*destructor)(void *);
typedef void (*iterator)(void *);

ListNode * initListNode(void * data)
{
    ListNode * n = malloc(sizeof(ListNode));
    n->data = data;
    n->next = NULL;
    return n;
}

List List_construct()
{
    List list;
    list.m_head = list.m_tail = NULL;
    list.m_size = 0;
    return list;
}

void List_append(List * list, void * element)
{
    if (!list->m_head)
    {
        list->m_head = list->m_tail = initListNode(element);
    }
    else
    {
        list->m_tail->next = initListNode(element);
        list->m_tail = list->m_tail->next;
    }
}

void List_dropHead(List * list, destructor destruct)
{
    ListNode * n = list->m_head;
    list->m_head = list->m_head->next;
    destruct(n->data);
    free(n);
}

void List_destruct(List * list, destructor destruct)
{
    while (list->m_head)
    {
        List_dropHead(list, destruct);
    }
}

void List_iterate(List * list, iterator iterate)
{
    for (ListNode * n = list->m_head; n != NULL; n = n->next)
    {
        iterate(n->data);
    }
}
