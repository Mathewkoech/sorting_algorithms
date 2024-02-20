#include "sort.h"

/**
 * swap - swaps two integers
 * @a: int
 * @b: int
 * Return:nothing
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partition - Partition an array and using pivot
 * @array: Array
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int l = low - 1, m;

	for (m = low; m <= high; m++)
	{
		if (array[m] <= pivot)
		{
			l++;
			if (l != m)
			{
				swap(&array[l], &array[m]);
				print_array(array, size);
			}
		}
	}
	return (l);
}
/**
 * lomuto_sort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, index - 1, size);
		lomuto_sort(array, index + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithm using lomuto partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort(int *array, size_t size)
{
	lomuto_sort(array, 0, size - 1, size);
}
