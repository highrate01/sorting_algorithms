#include "sort.h"

/**
 * insertion_sort_list - This function sorts list of data by building
 * the final sorted array one at a time
 *
 * @list: pointer to a pointer to the head of the linked list
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *ptr, *temp;

	if ((list == NULL && *list == NULL) || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		ptr = current;
		temp = current->prev;

		while (temp != NULL && temp->n > ptr->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = ptr;
			if (ptr->next != NULL)
				ptr->next->prev = temp;
			ptr->prev = temp->prev;
			temp->prev = ptr;
			temp->next = ptr->next;
			ptr->next = temp;

			if (ptr->prev == NULL)
				*list = ptr;

			temp = ptr->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
