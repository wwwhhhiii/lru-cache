#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct node ListNode;
typedef struct list LinkedList;

struct node {
    int val;
    ListNode* next;
    ListNode* prev;
};

struct list {
    ListNode* head;
    ListNode* tail;
};

ListNode*
create_node(int value);

LinkedList*
create_linked_list();

void destroy_linked_list(LinkedList** list);

void append_node(LinkedList* list, ListNode* node);

ListNode* find_node_by_value(const LinkedList* list, int value);

ListNode* find_node(const LinkedList* list, const ListNode* node);

ListNode* remove_node_by_value(LinkedList* list, int value);

ListNode* remove_node(LinkedList* list, ListNode* node);

void print_linked_list(LinkedList* list);

#endif
