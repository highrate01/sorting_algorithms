#include "sort.h"

/**
 * swap_int - This function swaps two iteger
 *
 * @a: The first ineger
 * @b: The second integer to be swapped
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int blank;

	blank = *a;
	*a = *b;
	*b = blank;
}
/**
 * partition - This functions partition the elements
 * of the array, puttion the elements less than the pivot
 * to the right and the ones greater than the pivot to the left
 *
 * @array: pointer to array of element
 * @size: the size of the array
 * @left: The starting index of the elements
 * @right: The ending index
 * Return: 1 on success, 0 therwise
 */

int partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right, upper, lower;

	for (upper = lower = left; lower < right; lower++)
	{
		if (array[lower] < *pivot)
		{
			if (upper < lower)
			{
				swap_int(array + lower, array + upper);
				print_array(array, size);
			}
			upper++;
		}
	}
	if (array[upper] > *pivot)
	{
		swap_int(array + upper, pivot);
		print_array(array, size);
	}
	return (upper);
}
/**
 * quicksort_recur - This implements the recurrsion part
 * of the quick sort function
 *
 * @array: The array of the elements to sort
 * @size: The size of the array
 * @lower: The smallest numbers
 * @upper: The highest numbers
 * Return: void
 */
void quicksort_recur(int *array, size_t size, int lower, int upper)
{
	int partition_index;

	if (lower < upper)
	{
		partition_index = partition(array, size, lower, upper);
		quicksort_recur(array, size, lower, partition_index - 1);
		quicksort_recur(array, size, partition_index + 1, upper);
	}
}

/**
 * quick_sort - It sort elements of array in ascending order
 *
 * @array: array of the elements to be sorted
 * @size: The size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recur(array, size, 0, size - 1);
}
