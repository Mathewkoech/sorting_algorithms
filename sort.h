#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

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
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
/*lomuto partion scheme*/
void lomuto_sort(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
/*utils*/
void swap(int *a, int *b);
int get_high(int *array, int size);
/* advanced*/
void cocktail_sort_list(listint_t **list);
/*inside cocktail*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current);
void swap_node_behind(listint_t **list, listint_t **current);
void cocktail_sort_list(listint_t **list);
void swapp(int *a, int *b);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heapify(int *array, int heap, int i, int size);
void heap_sort(int *array, size_t size);
int pivot_partition(int *array, int low, int high, size_t size);
void hoare_qsort(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);
#endif
