#pragma once

#include "List.h"

static const size_t HS_TABLE_SIZE = 100;

typedef size_t (*hash_func)(void *);
typedef bool (*equality_predicate)(void *, void *);

typedef struct
{
    List m_hashTable[HS_TABLE_SIZE];
    hash_func hash;
} HashSet;

HashSet HashSet_construct(hash_func hash);

void HashSet_destruct(HashSet * set, destructor destruct);

void HashSet_insert(HashSet * set, void * element);

void HashSet_iterate(HashSet * set, iterator iterate);

void * HashSet_find(HashSet * set, void * element, equality_predicate are_equal);
