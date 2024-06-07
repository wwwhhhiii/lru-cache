#include <stdio.h>
#include <assert.h>

#include "hash_table.h"
#include "linked_list.h"

int main()
{
    struct HashTable* table = create_hash_table("table");
    struct LinkedList* list = create_linked_list();

    // ...

    return 0;
};