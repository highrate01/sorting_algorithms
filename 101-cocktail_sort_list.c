#include "sort.h"
/**
 * f_swap_nodes - moved swapped node forward
 *
 * @list: pointer to the head of the list
 * @tail: pointer to the end of the list
 * @current: pointer to current node
 */
void f_swap_nodes(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *tmp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*current)->prev;
	(*current)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = tmp;
	tmp->next = *current;
	*current = tmp;
}
/**
 * swap_node - This function swaps nodes in
 * doubly linked list
 *
 * @list: pointer to head of the nodes
 * @tail: pointer the end of the nodes
 * @current: pointer to help iterate through
 * the list of nodes
 * Return: void
 */
void swap_node(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *tmp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*current)->next;
	(*current)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = tmp;
	tmp->prev = *current;
	*current = tmp;
}
/**
 * cocktail_sort_list - This function sort list of elemennts
 * like bubble sort but it sort by moving elements both ways
 *
 * @list: pointer to the head of the list
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	bool moved = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tmp = *list; tmp->next != NULL;)
		tmp = tmp->next;
	while (moved == false)
	{
		moved = true;

		for (current = *list; current != tmp; current = current->next)
		{
			if (current->n > current->next->n)
			{
				f_swap_nodes(list, &tmp, &current);
				print_list((const listint_t *)*list);
				moved = false;
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node(list, &tmp, &current);
				print_list((const listint_t *)*list);
				moved = false;
			}
		}
	}
}
