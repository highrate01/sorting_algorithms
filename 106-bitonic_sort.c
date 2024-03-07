#include "sort.h"

/**
 * bitonic merge - This is recursive function that merges
 * splitted arrays
 *
 * @array: An array of integer
 * @size: size of the array
 * @start: starting index
 * @sequence: size of the new array to sort
 * @direc: The direction to to follow
 *
 * Return: nothing:
 */
void bitonic_merge(int *array, size_t size, size_t start,
		size_t sequence, char direc)
{
	size_t i, push = sequence / 2;

	if (sequence > 1)
	{
		i = start;
		while (i < start + push)
		{
			if ((direc == UP && array[i] > array[i + push]) ||
					(direc == DOWN && array[i] < array[i + push]))
				swap_int(array + i, array + i + push);
			i++;
		}
		bitonic_merge(array, size, start, push, direc);
		bitonic_merge(array, size, start + push, push, direc);
	}
}
/**
 * bitonic_sequence - converts to bitonic sequence
 * @array: array of integers
 * @size: size of array
 * @start: starting index
 * @sequence: size of sequence
 * @direc: The direction to sort
 * Return: nothing
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t sequence,
		char direc)
{
	size_t slice = sequence / 2;
	char *str = (direc == UP) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu%lu] (%s): \n", sequence, size, str);
		print_array(array + start, sequence);

		bitonic_sequence(array, size, start, slice, UP);
		bitonic_sequence(array, size, start + slice, slice, DOWN);
		bitonic_merge(array, size, start, sequence, direc);

		printf("Result [%lu%lu (%s):\n", sequence, size, str);
		print_array(array + start, sequence);
	}
}
/**
 * bitonic_sort - Sort an array of integer order in ascending order
 *
 * @array: An array of integer
 * @size: size of the array
 * Description:  works for 2^k where k >= 0
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sequence(array, size, 0, size, UP);
}
/**
 * swap_int - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
