#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

/// @brief Creates node with given value and no references
/// @param value value to assign to node
/// @return created node
struct ListNode*
create_node(int value)
{
    struct ListNode* node = malloc(sizeof(struct ListNode));
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
struct LinkedList* create_linked_list()
{
    struct LinkedList* l = malloc(sizeof(struct LinkedList));
    if (l == NULL) {
        return NULL;
    }

    l->head = NULL;
    l->tail = NULL;

    return l;
}

/// @brief Destroyes linked list and frees nodes occupied memroy
/// @param list list to destroy
void destroy_linked_list(struct LinkedList** list)
{
    if (*list == NULL) {
        return;
    }

    struct ListNode* cur_node = (*list)->head;

    while (cur_node) {
        struct ListNode* del_node = cur_node;
        cur_node = cur_node->next;
        free(del_node); // TODO mb store **node, then *node = NULL ?
    }

    free(*list);
    *list = NULL;
}

/// @brief Appends node to the end of the list
/// @param list list to append to
/// @param node node to append to list
void append_node(struct LinkedList* list, struct ListNode* node)
{
    if (list->tail == NULL) {
        // when no nodes are present in list
        list->head = node;
        list->tail = node;
    } else {
        struct ListNode* tail_node = list->tail;
        tail_node->next = node;
        node->prev = tail_node;
        list->tail = node;
    }
}

/// @brief Searches node in linked list by pointer
/// @param list - list to search node in
/// @param node - node to search for
/// @return pointer to found node
struct ListNode* find_node(const struct LinkedList* list, const struct ListNode* node)
{
    struct ListNode* cur_node = list->head;

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
struct ListNode*
find_node_by_value(const struct LinkedList* list, int value)
{
    struct ListNode* cur_node = list->head;

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
struct ListNode*
remove_node_by_value(struct LinkedList* list, int value)
{
    struct ListNode* node_to_rm = find_node_by_value(list, value);
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
struct ListNode*
remove_node(struct LinkedList* list, struct ListNode* node)
{
    if (node == NULL) {
        return NULL;
    }

    struct ListNode* node_to_rm = find_node(list, node);

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
void print_linked_list(struct LinkedList* list)
{
    if (list == NULL) {
        return;
    }

    struct ListNode* cur_node = list->head;

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
