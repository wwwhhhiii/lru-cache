typedef struct {
    char name[20];
    int values[1000000000];
} HashTable;

HashTable* create_hash_table(const char name[]);

void add_item(HashTable* t, const char key[], int item);

int get_item(HashTable* t, const char key[], int default_v);

int remove_item(HashTable* t, const char key[]);

int _hash_string(const char s[]);
