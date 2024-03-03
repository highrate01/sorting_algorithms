#include "sort.h"

/**
 * selection_sort -This function selects the smallest item
 * from the unsorted partition and move it to the sorted
 * partition
 *
 * @array: pointer to the list of items to be sorted
 * @size: The size of the list
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap_int(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}

/**
 * swap_int - this func swaps two inetegrs
 *
 * @a: pointer to first integer
 * @b: pointer to second integer
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int blank;
	int *d = &blank;

	*d = *a;
	*a = *b;
	*b = *d;
}
