#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
    struct ListNode* prev;
};

struct LinkedList {
    struct ListNode* head;
    struct ListNode* tail;
};

struct ListNode*
create_node(int value);

struct LinkedList*
create_linked_list();

void destroy_linked_list(struct LinkedList** list);

void append_node(struct LinkedList* list, struct ListNode* node);

struct ListNode* find_node_by_value(const struct LinkedList* list, int value);

struct ListNode* find_node(const struct LinkedList* list, const struct ListNode* node);

struct ListNode* remove_node_by_value(struct LinkedList* list, int value);

struct ListNode* remove_node(struct LinkedList* list, struct ListNode* node);

void print_linked_list(struct LinkedList* list);
