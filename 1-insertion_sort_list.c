#include "sort.h"

/**
 * insertion_sort_list - This function sorts list of data by building
 *			the final sorted array one at a time
 * @list: pointer to a pointer to the head of the linked list
 *
 * Description: It implements the insertion sort to sort the
 *		allgoritm
 *Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *ptr, *temp;

	if (list == NULL || *list == NULL)
		return;
	ptr = (*list)->next;
	while (ptr != NULL)
	{
		temp = ptr->next;
		current = ptr->prev;

		while (current != NULL && ptr->n < current->n)
		{
			swap_nodes(list, &current, ptr);
			print_list((const listint_t *)*list);
		}
		ptr = temp;
	}
}
/**
 * swap_nodes - swaps two nodes in doubly linked list
 *
 * @head: pointer to the head of the list
 * @node1: pointer to first node
 * @node2: pointer to second node
 * Return: nothing
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
