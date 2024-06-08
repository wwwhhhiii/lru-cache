#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct {
    int values[1000000000];
} HashTable;

HashTable* create_hash_table();

void add_item(HashTable* t, const char key[], int item);

int get_item(HashTable* t, const char key[], int default_v);

int remove_item(HashTable* t, const char key[]);

int _hash_string(const char s[]);

#endif
