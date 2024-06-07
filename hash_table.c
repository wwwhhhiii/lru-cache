#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

struct HashTable* create_hash_table(const char name[])
{
    struct HashTable* t = malloc(sizeof(struct HashTable));
    strcpy(t->name, name);
    // TODO add checks

    return t;
}

int
_hash_string(const char s[])
{
    unsigned long hash = 5381;
    int c;

    // save pointer to beginning of the string for debug
    const char* _p = &s[0];

    while (c = *s++) {
        hash = ((hash << 5) + hash) + c;
    }

    int hash_m = hash % 5381;
    
    // printf("[HASH] string '%s' hash is %i\n", _p, hash_m);

    return hash_m;
}

void 
add_item(struct HashTable* t, const char key[], int item)
{
    int hash = _hash_string(key);
    t->values[hash] = item;
}

int
get_item(struct HashTable* t, const char key[], int default_v)
{
    int hash = _hash_string(key);
    int val = t->values[hash];
    if (val == 0) {
        return default_v;
    }

    return val;
}

int
remove_item(struct HashTable* t, const char key[])
{
    int hash = _hash_string(key);
    int val = t->values[hash];
    t->values[hash] = 0;
    
    return val;
}
