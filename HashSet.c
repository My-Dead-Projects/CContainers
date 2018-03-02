#include "HashSet.h"

HashSet HashSet_construct(hash_func hash)
{
    HashSet map;
    map.hash = hash;
    for (size_t i = 0; i < HS_TABLE_SIZE; i++)
    {
        map.m_hashTable[i] = List_construct();
    }
    return map;
}

void HashSet_destruct(HashSet * set, destructor destruct)
{
    for (size_t i = 0; i < HS_TABLE_SIZE; i++)
    {
        List_destruct(&set->m_hashTable[i], destruct);
    }
}

void HashSet_insert(HashSet * set, void * element)
{
    size_t index = set->hash(element) % HS_TABLE_SIZE;
    List_append(&set->m_hashTable[index], element);
}

void HashSet_iterate(HashSet * set, iterator iterate)
{
    for (size_t i = 0; i < HS_TABLE_SIZE; i++)
    {
        List_iterate(&set->m_hashTable[i], iterate);
    }
}

void * HashSet_find(HashSet * set, void * element, equality_predicate are_equal)
{
    size_t index = set->hash(element) % HS_TABLE_SIZE;
    List slot = set->m_hashTable[index];
    ListIterator iter = List_begin(&slot);
    void * e;
    for (;(e = ListIterator_get(&iter)) != NULL; ListIterator_next(&iter))
    {
        if (are_equal(element, e))
            return e;
    }
    return NULL;
}
