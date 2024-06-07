struct HashTable {
    char name[20];
    int values[1000000000];
};

struct HashTable* create_hash_table(const char name[]);

void add_item(struct HashTable* t, const char key[], int item);

int get_item(struct HashTable* t, const char key[], int default_v);

int remove_item(struct HashTable* t, const char key[]);

int _hash_string(const char s[]);
