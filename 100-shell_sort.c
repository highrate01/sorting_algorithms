#include "sort.h"

/**
 * shell_sort - This function compares elements
 * that are distance apart and then sort them
 * in ascending order
 *
 * @array: array of the elements to be sorted
 * @size: size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (array == NULL || size < 2)
		return;
	while (gap < (size / 3))
	{
		gap *= 3 + 1;
	}
	while (gap >= 1)
	{
		i = gap;
		while (i < size)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_int(array + j, array + (j - gap));
				j -= gap;
			}
			i++;
		}
		print_array(array, size);
		gap /= 3;
	}
}
/**
 * swap_int - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int blank;

	blank = *a;
	*a = *b;
	*b = blank;
}
