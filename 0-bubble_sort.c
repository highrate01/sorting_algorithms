#include "sort.h"

/**
 * bubble_sort - This function swaps an array of integer
 * using the buble sort algorithm
 *
 * @array: array to be sorted
 * @size: it reps the total number of datas in the array
 * Description: This swaps two integers that area out of
 * place by comparing them
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}

/**
 * swap_int - swap two integers
 *
 * @a: first integer
 * @b: second integer
 *
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
