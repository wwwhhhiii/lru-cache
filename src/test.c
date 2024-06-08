#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hash_table.h"
#include "linked_list.h"

void test_hash_table_create()
{
    HashTable* table = create_hash_table();

    free(table);
}

void test_hash_table_add_item()
{
    HashTable* table = malloc(sizeof(HashTable));

    const char key[] = "some random key";
    int value_to_add = 500;
    add_item(table, key, value_to_add);

    int item_hash = _hash_string(key);
    assert (table->values[item_hash] == value_to_add);

    free(table);
}

void test_hash_table_get_item()
{
    HashTable* table = malloc(sizeof(HashTable));

    const char key[] = "some_random_key";
    int val_to_add = 222;
    int item_hash = _hash_string(key);

    int default_val = 0;
    table->values[item_hash] = val_to_add;
    int retval = get_item(table, key, default_val);
    assert (retval == val_to_add);

    free(table);
}

void test_hash_table_remove_item()
{
    HashTable* table = malloc(sizeof(HashTable));

    const char key[] = "some_rnd_key";
    int val = 333;
    int item_hash = _hash_string(key);
    table->values[item_hash] = val;

    int removed_item = remove_item(table, key);
    assert (removed_item == val);
    assert (table->values[item_hash] == 0);

    free(table);
}

void test_create_node()
{
    int val = 5;
    ListNode* node = create_node(val);
    
    assert (node->val == val);
    assert (node->next == NULL && node->prev == NULL);

    free(node);
}

void test_create_linked_list()
{
    LinkedList* list = create_linked_list();

    assert (list->head == NULL);
    assert (list->tail == NULL);

    free(list);
}

void test_destroy_linked_list()
{
    LinkedList* list = create_linked_list();

    int elems_num = 10;
    ListNode* nodes[elems_num];

    for (int i = 0; i < elems_num; i++) {
        ListNode* node = create_node(i);
        nodes[i] = node;
        append_node(list, node);
    }

    destroy_linked_list(&list);

    assert (list == NULL);
    // TODO test nodes pointers when they will be set to NULL
}

void test_append_node_to_list()
{
    LinkedList* list = create_linked_list();
    ListNode* node = create_node(11);

    append_node(list, node);

    assert (list->tail == node);
    assert (list->head == node);
    assert (node->next == NULL);

    free(list);
    free(node);
}

void test_find_node_by_value()
{
    LinkedList* list = create_linked_list();
    
    for (int i = 0; i < 10; i++) {
        append_node(list, create_node(i));
    }

    ListNode* node_3 = find_node_by_value(list, 3);
    assert (node_3 != NULL && node_3->val == 3);
    ListNode* node_5 = find_node_by_value(list, 5);
    assert (node_5 != NULL && node_5->val == 5);
    ListNode* node_8 = find_node_by_value(list, 8);
    assert (node_8 != NULL && node_8->val == 8);

    free(list);
}

void test_find_node()
{
    LinkedList* list = create_linked_list();

    int elems_num = 10;
    ListNode* nodes[elems_num];

    for (int i = 0; i < elems_num; i++) {
        ListNode* node = create_node(i);
        nodes[i] = node;
        append_node(list, node);
    }

    ListNode* node_3 = find_node(list, nodes[3]);
    assert (node_3 != NULL);
    assert (node_3 == nodes[3]);

    ListNode* node_6 = find_node(list, nodes[6]);
    assert (node_6 != NULL);
    assert (node_6 == nodes[6]);
}

void test_remove_node_by_value()
{
    LinkedList* list = create_linked_list();

    int elems_num = 10;
    ListNode* nodes[elems_num];

    for (int i = 0; i < elems_num; i++) {
        ListNode* node = create_node(i);
        nodes[i] = node;
        append_node(list, node);
    }

    // node removal in middle
    ListNode* removed_node = remove_node_by_value(list, 5);
    assert (removed_node != NULL);
    assert (removed_node->val == 5);
    assert (removed_node == nodes[5]);
    assert (nodes[4]->next == nodes[6]);
    assert (nodes[6]->prev == nodes[4]);

    // remove already removed
    assert (remove_node_by_value(list, 5) == NULL);

    // head node removal
    assert (list->head == nodes[0]);
    removed_node = remove_node_by_value(list, nodes[0]->val);
    assert (removed_node != NULL);
    assert (list->head == nodes[1]);

    // tail node removal
    assert (list->tail == nodes[elems_num-1]);
    removed_node = remove_node_by_value(list, nodes[elems_num-1]->val);
    assert (remove_node != NULL);
    assert (list->tail == nodes[elems_num-2]);

    free(list);
}

void test_remove_node()
{
    LinkedList* list = create_linked_list();

    int elems_num = 10;
    ListNode* nodes[elems_num];

    for (int i = 0; i < elems_num; i++) {
        ListNode* node = create_node(i);
        nodes[i] = node;
        append_node(list, node);
    }

    // node removal in middle
    ListNode* removed_node = remove_node(list, nodes[5]);
    assert (removed_node != NULL);
    assert (removed_node == nodes[5]);
    assert (nodes[4]->next == nodes[6]);
    assert (nodes[6]->prev == nodes[4]);

    // head node removal
    assert (list->head == nodes[0]);
    removed_node = remove_node(list, nodes[0]);
    assert (removed_node != NULL);
    assert (list->head == nodes[1]);

    // tail node removal
    assert (list->tail == nodes[elems_num-1]);
    removed_node = remove_node(list, nodes[elems_num-1]);
    assert (removed_node != NULL);
    assert (list->tail == nodes[elems_num-2]);

    assert (remove_node(list, removed_node) == NULL);
}

int main()
{
    // hash table
    test_hash_table_create();
    printf("test_hash_table_create PASSED\n");
    test_hash_table_add_item();
    printf("test_hash_table_add_item PASSED\n");
    test_hash_table_get_item();
    printf("test_hash_table_get_item PASSED\n");
    test_hash_table_remove_item();
    printf("test_hash_table_remove_item PASSED\n");

    // linked list
    test_create_node();
    printf("test_create_node PASSED\n");
    test_create_linked_list();
    printf("test_create_linked_list PASSED\n");
    test_destroy_linked_list();
    printf("test_destroy_linked_list PASSED\n");
    test_append_node_to_list();
    printf("test_append_node_to_list PASSED\n");
    test_find_node_by_value();
    printf("test_find_node_by_value PASSED\n");
    test_find_node();
    printf("test_find_node PASSED\n");
    test_remove_node_by_value();
    printf("test_remove_node_by_value PASSED\n");
    test_remove_node();
    printf("test_remove_node PASSED\n");

    printf("\nAll tests passed\n");
}
