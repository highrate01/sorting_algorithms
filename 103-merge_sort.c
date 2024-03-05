#include "sort.h"

/**
 * merge_sub - sort the sub array of the list
 *
 * @div: The divided array
 * @front: right index of the array
 * @back: The left index of the array
 * @mid: The middle index of the aray
 * @buff: buffer to store the array
 * Return: void
 */
void merge_sub(int *div, int *buff, size_t front, size_t mid, size_t back)
{
	size_t k = 0, i, j;

	printf("merging...\n[left]: ");
	print_array(div + front, mid - front);
	printf("[right]: ");
	print_array(div + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (div[i] < div[j]) ? div[i++] : div[j++];
	for (; i < mid; i++)
		buff[k++] = div[i];
	for (; j < back; j++)
		buff[k++] = div[j];
	for (i = front, k = 0; i < back; i++)
		div[i] = buff[k++];
	printf("[Done]: ");
	print_array(div + front, back - front);
}
/**
 * merge_recur - perform recutrsion on the merge sort function
 *
 * @div: The divided part of the array
 * @front: front index
 * @back: back index
 * @buff: buffer conatining the sorted array
 * Return: nothing
 */
void merge_recur(int *div, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_recur(div,buff, front, mid);
		merge_recur(div,buff, mid, back);
		merge_sub(div, buff, front, mid, back);
		merge_sub(div, buff, front, mid, back);
	}
}

/**
 * merge_sort - This program spoke aerray in halves until we are
 * left with individual item and sort the array
 *
 * @array: reps array of integers
 * @size: The size of the array
 *
 * Desription: Divides array into two until individual element is acheived
 */
void merge_sort(int *array, size_t size)
{
	int *container;

	if (array == NULL || size < 2)
		return;
	container = malloc(sizeof(int) * size);
	if (container == NULL)
		return;
	merge_recur(array, container, 0, size);
	free(container);
}
