#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap_int(int *a, int *b);
int _strcmp(char *s1, char *s2);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort_recur(int *array, size_t size, int lower, int upper);
int partition(int *array, size_t size, int left, int right);
void shell_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void cocktail_sort_list(listint_t **list);
void f_swap_nodes(listint_t **list, listint_t **tail, listint_t **current);
void swap_node(listint_t **list, listint_t **tail, listint_t **current);
int max_value(int *array, int size);
void counting_sort(int *array, size_t size);
void merge_sub(int *div, int *buff, size_t front, size_t mid, size_t back);
void merge_recur(int *div, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void bin_heap(int *array, size_t size, size_t index, size_t tail);
void heap_sort(int *array, size_t size);
void count_sort(int *array, size_t size, int digit, int *buff);
int highest(int *array, int size);
void radix_sort(int *array, size_t size);
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2);

#endif /*MAIN_H*/
