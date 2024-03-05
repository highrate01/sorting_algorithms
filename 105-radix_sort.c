#include "sort.h"

/**
 * highest - fetch highest value in array
 * @array: reps array of integers
 * @size: reps the size of array
 * Return: The max integer
 */
int highest(int *array, int size)
{
	int max_num, i;

	for (max_num = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}
	return (max_num);
}

/**
 * count_sort - sort array in ascending order using counting sort
 *
 * @array: the array of integers
 * @size: The size of the array
 * @digit: The siginificant digit to sort
 * @buff: container to store sorted array
 * Return: nothing
 */
void count_sort(int *array, size_t size, int digit, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - This function sorts array of integer in ascending order
 * 		its imitates the radix sort algorithm
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 * Description: This function uses the counting sort algorithm to count
 * 		and swap the significant digit whic is the highest in the array
 *
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int max_num, digit, *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	max_num = highest(array, size);

	for (digit = 1; max_num / digit > 0; digit *= 10)
	{
		count_sort(array, size, digit, buff);
		print_array(array, size);
	}
	free(buff);
}
