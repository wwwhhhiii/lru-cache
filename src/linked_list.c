#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

/// @brief Creates node with given value and no references
/// @param value value to assign to node
/// @return created node
ListNode*
create_node(int value)
{
    ListNode* node = malloc(sizeof(ListNode));
    if (node == NULL) {
        return NULL;
    }

    node->val = value;
    node->next = NULL;
    node->prev = NULL;
}

/// @brief Creates an empty linked list
/// if failed to allocate either list or node - returns NULL
/// @return created linked list
LinkedList* create_linked_list()
{
    LinkedList* l = malloc(sizeof(LinkedList));
    if (l == NULL) {
        return NULL;
    }

    l->head = NULL;
    l->tail = NULL;

    return l;
}

/// @brief Destroyes linked list and frees nodes occupied memroy
/// @param list list to destroy
void destroy_linked_list(LinkedList** list)
{
    if (*list == NULL) {
        return;
    }

    ListNode* cur_node = (*list)->head;

    while (cur_node) {
        ListNode* del_node = cur_node;
        cur_node = cur_node->next;
        free(del_node); // TODO mb store **node, then *node = NULL ?
    }

    free(*list);
    *list = NULL;
}

/// @brief Appends node to the end of the list
/// @param list list to append to
/// @param node node to append to list
void append_node(LinkedList* list, ListNode* node)
{
    if (list->tail == NULL) {
        // when no nodes are present in list
        list->head = node;
        list->tail = node;
    } else {
        ListNode* tail_node = list->tail;
        tail_node->next = node;
        node->prev = tail_node;
        list->tail = node;
    }
}

/// @brief Searches node in linked list by pointer
/// @param list - list to search node in
/// @param node - node to search for
/// @return pointer to found node
ListNode* find_node(const LinkedList* list, const ListNode* node)
{
    ListNode* cur_node = list->head;

    while (cur_node) {
        if (cur_node == node) {
            return cur_node;
        }

        cur_node = cur_node->next;
    }

    return cur_node;
}

/// @brief Searches for node in linked list by value
/// @param list list to search
/// @param value value to search by
/// @return found node
ListNode*
find_node_by_value(const LinkedList* list, int value)
{
    ListNode* cur_node = list->head;

    while (cur_node) {
        if (cur_node->val == value) {
            return cur_node;
        }
        cur_node = cur_node->next;
    }

    return cur_node;
}

/// @brief Removes first node from list by value
/// @param list list to remove node from
/// @param value value of node to remove
/// @return removed node
ListNode*
remove_node_by_value(LinkedList* list, int value)
{
    ListNode* node_to_rm = find_node_by_value(list, value);
    if (node_to_rm == NULL) {
        return NULL;
    }

    if (node_to_rm->prev != NULL) {
        node_to_rm->prev->next = node_to_rm->next;
    } else {
        // when head is removed
        list->head = node_to_rm->next;
    }
    if (node_to_rm->next != NULL) {
        node_to_rm->next->prev = node_to_rm->prev;
    } else {
        // when tail is removed
        list->tail = node_to_rm->prev;
    }

    return node_to_rm;
}

/// @brief Removes node from linked list
/// @param list linked list to remove node from
/// @param node node to remove from list
/// @returns removed node
ListNode*
remove_node(LinkedList* list, ListNode* node)
{
    if (node == NULL) {
        return NULL;
    }

    ListNode* node_to_rm = find_node(list, node);

    if (node_to_rm == NULL) {
        return NULL;
    }

    if (node_to_rm->prev != NULL) {
        node_to_rm->prev->next = node_to_rm->next;
    } else {
        // when head is removed
        list->head = node_to_rm->next;
    }
    if (node_to_rm->next != NULL) {
        node_to_rm->next->prev = node_to_rm->prev;
    } else {
        // when tail is removed
        list->tail = node_to_rm->prev;
    }

    return node_to_rm;
}

/// @brief Convinient print for linked list
/// @param list list to print
void print_linked_list(LinkedList* list)
{
    if (list == NULL) {
        return;
    }

    ListNode* cur_node = list->head;

    while (cur_node) {
        if (cur_node == list->head) {
            printf("%i", cur_node->val);
        } else {
            printf("->%i", cur_node->val);
        }
        cur_node = cur_node->next;
    }
    printf("\n");
}
