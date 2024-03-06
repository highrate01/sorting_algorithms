#include "sort.h"
/**
 * max_value - the maximum element in array
 * @array: array of integer
 * @size: The size of the array
 * Return: max integer
 *
 */
int max_value(int *array, int size)
{
	int max = array[0];
	int count;

	for (count = 1; count < size; count++)
	{
		if (array[count] > max)
			max = array[count];
	}
	return (max);
}
/**
 * counting_sort - This sorts an of integer in
 * ascending order
 *
 * @array: pointer to the array of the elements to be sorted
 * @size: size of the array
 * Description: It sorts elements of the array by counting
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int i, j;
	int *count, max;
	int *new_array;

	max = max_value(array, size);
	if (max == -1)
		return;
	if (array == NULL || size < 2)
		return;
	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
		return;
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(new_array);
		return;
	}
	j = (int)size;
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	for (i = 0; i < j; i++)
		count[array[i]] = count[array[i]] + 1;

	for (i = 1; i < (max + 1); i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < j; i++)
	{
		new_array[count[array[i]] - 1] = array[i];
		count[array[i]] = count[array[i]] - 1;
	}
	for (i = 0; i < j; i++)
		array[i] = new_array[i];
	free(new_array);
	free(count);
}
