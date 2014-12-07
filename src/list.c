#include "list.h"

node *list_node_create(void *data)
{
    node *nd = malloc(sizeof(node));
    nd->data = data;
    nd->next = NULL;

    return nd;
}

void list_node_destroy(node *nd, fn_ptr free_func)
{
    if (free_func) {
        free_func(nd->data);
    }
    free(nd);
}

list *list_create(fn_ptr free_func)
{
    list *ls = malloc(sizeof(list));
    ls->length = 0;

    // Create/set head and tail nodes
    ls->head = NULL;
    ls->tail = NULL;

    // Pointer to a function that frees node->data items
    ls->free_func = free_func;

    return ls;
}

void list_destroy(list *ls)
{
    node *curr, *next;

    curr = ls->head;
    while (curr)
    {
        next = curr->next;
        list_node_destroy(curr, ls->free_func);
        curr = next;
    }

    free(ls);
}

void list_append(list *ls, node *nd)
{
    // If first item in list, set head
    if (! ls->head)
    {
        ls->head = nd;
        ls->tail = nd;
    } else {
        ls->tail->next = nd;
        ls->tail = nd;
    }
}

node *list_get(list *ls, int index)
{
    int count = 0;
    node *curr = ls->head;

    while (count < index)
    {
        if (count++ > ls->length)
        {
            return NULL;
        }
        curr = curr->next;
    }
    return curr;
}

void list_remove(list *ls, int index)
{
    int count = 0;
    node *curr, *next;

    curr = ls->head;
    next = curr->next;
    while (count < index)
    {
        if (count++ > ls->length) return; // End function
        curr = next;
        next = curr->next;
    }

    // Update pointer and delete orphan
    curr->next = next->next;
    list_node_destroy(next, ls->free_func);

}

void list_map(list *ls, fn_ptr func)
{
    node *curr = ls->head;
    while (curr)
    {
        func(curr->data);
        curr = curr->next;
    }
}
