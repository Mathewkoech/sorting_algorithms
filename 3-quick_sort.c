#include "sort.h"
#include <stdbool.h>

/**
 * swap - interchanges two numbers
 * @a: first number in array
 * @b: second number in array
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - uses Hoare's partitions on the array/ sub-array
 * @arr: array of integers
 * @low: lowest index in array
 * @high: highest index in array
 * @size: of array
 * Return: returns the pivot index
 */

size_t partition(int *arr, size_t low, size_t high, size_t size)
{
	int pivot = arr[low];
	size_t i = low - 1, j = high + 1;

	while (true)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return (j);
		swap(&arr[i], &arr[j]);
		print_array(arr, size);
	}
}

/**
 * my_quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: input array of integers
 * @low: lowest index
 * @high: highest index
 * @size: of array
 */

void my_quick_sort(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		my_quick_sort(array, low, pivot, size);
		my_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 *quick_sort - sorts an array of integers in ascending
 *order using the Quick sort algorithm
 *@array: input array of integers
 *@size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	 my_quick_sort(array, 0, size - 1, size);
}
