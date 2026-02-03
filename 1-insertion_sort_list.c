#include "sort.h"

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 */
static void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev)
        left->prev->next = right;
    if (right->next)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;

    left->prev = right;
    right->next = left;

    if (!right->prev)
        *list = right;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;
    while (current)
    {
        temp = current;
        while (temp->prev && temp->n < temp->prev->n)
        {
            swap_nodes(list, temp->prev, temp);
            print_list(*list);
        }
        current = current->next;
    }
}
