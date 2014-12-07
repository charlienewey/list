#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

// Define function as a type
typedef void (*fn_ptr)(void *);

/**
 * Self-referential linked data structure.
 *
 * Holds a pointer to some generic data and a pointer to the next
 * node in the sequence.
 */
typedef struct _node {
    void *data;
    struct _node *next;
} node;

/**
 * Linked list node main structure.
 *
 * Contains a pointer to the head and tail nodes, as well as an integer for
 * describing the length of the list. Also contains a pointer to a function to
 * free node data objects in case they were dynamically allocated.
 */
typedef struct {
    int length;
    node *head;
    node *tail;
    fn_ptr free_func; // Function to free node->data
} list;

/**
 * Create a list node containing a pointer to "data".
 *
 * @param data A (void *) argument pointing to the node's data.
 * @return nd A (node *) struct argument containing a pointer to "data".
 */
node *list_node_create(void *data);

/**
 * Destroy a list node, freeing all associated memory.
 *
 * @param nd A pointer to the list node to be destroyed.
 * @param free_func Pointer to "void function (void *)" that frees "nd->data".
 */
void list_node_destroy(node *nd, fn_ptr free_func);

/**
 * Create a list, initialising with a head node and freeing function.
 *
 * @see list_node_create
 * @param free_func Pointer to "void function (void *)" that frees "node->data"
 * @return A pointer to a list.
 */
list *list_create(fn_ptr free_func);

/**
 * Destroy a list from top to bottom, freeing memory for each node as it goes.
 * @param A pointer to list to be destroyed.
 */
void list_destroy(list *ls);

/**
 * Append a list node to a list.
 *
 * @param ls A pointer to the list to append a node to.
 * @param A pointer to the node to be appended to the list.
 */
node *list_get(list *ls, int index);

/**
 * Return a pointer to the list at the specified index (if it exists).
 *
 * @param ls A pointer to the list to get the corresponding node from.
 * @param index An integer describing the index of the desired node.
 * @return A list node at the desired index in the list.
 */
void list_append(list *ls, node *nd);

/**
 * Remove an item from the list at the specified index (if it exists).
 *
 * @param ls A pointer to the list to remove the specified node from.
 * @param index The index corresponding to the node to be removed.
 */
void list_remove(list *ls, int index);

/**
 * Map a function over a list.
 *
 * @param ls The list to map the function over.
 * @param func The function to map over the list.
 */
void list_map(list *ls, fn_ptr func);

#endif // LIST_H
