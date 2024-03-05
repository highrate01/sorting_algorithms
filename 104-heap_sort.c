#include "sort.h"

/**
 * bin_heap - This function converts binary tree to binary heap
 *
 * @array: An array of integers
 * @size: size of the array
 * @index: The of the array
 * @tail: The tail of the array
 * Return: nothing
 */
void bin_heap(int *array, size_t size, size_t index, size_t tail)
{
	size_t left, right, large;

	left = 2 * tail + 1;
	right = 2 * tail + 2;
	large = tail;

	if (left < index && array[left] > array[large])
		large = left;
	if (right < index && array[right] > array[large])
		large = right;
	if (large != tail)
	{
		swap_int(array + tail, array + large);
		print_array(array, size);
		bin_heap(array, size, index, large);
	}
}
/**
 * swap_int - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heap_sort - sorts array of integers
 * @array: Represents array of integers
 * @size: reps size of integers
 *
 * Description: This is ordered binary tree that makes use
 * of max heap to sort algorithm.
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		bin_heap(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		swap_int(array, array + i);
		print_array(array, size);
		bin_heap(array, size, i, 0);
	}
}
