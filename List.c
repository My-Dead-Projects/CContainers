#include "List.h"

ListNode * ListNode_init(void * data)
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
        list->m_head = list->m_tail = ListNode_init(element);
    }
    else
    {
        list->m_tail->next = ListNode_init(element);
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

ListIterator List_begin(List * list)
{
    ListIterator iter;
    iter.m_node = list->m_head;
    return iter;
}

void * ListIterator_get(ListIterator * iter)
{
    if (iter->m_node)
        return iter->m_node->data;
    else
        return NULL;
}

void ListIterator_next(ListIterator * iter)
{
    if (iter->m_node)
        iter->m_node = iter->m_node->next;
}
