#include "sort.h"

/**
 * insertion_sort_list - This function sorts list of data by building
 * the final sorted array one at a time
 * @list: pointer to a pointer to the head of the linked list
 *
 * Description: It sorts array in ascending order
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *ptr, *temp, *prev_temp, *next_ptr;

	if ((list == NULL && *list == NULL) || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		ptr = current;
		temp = current->prev;

		while (temp != NULL && temp->n > ptr->n)
		{
			prev_temp = temp->prev;
			next_ptr = ptr->next;
			if (prev_temp != NULL)
				prev_temp->next = ptr;
			if (next_ptr != NULL)
				next_ptr->prev = temp;
			ptr->prev = prev_temp;
			temp->prev = ptr;
			temp->next = next_ptr;
			ptr->next = temp;

			if (ptr->prev == NULL)
				*list = ptr;

			temp = ptr->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
