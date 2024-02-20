#include "sort.h"

/**
 *swap- function that swaps two integers in array
 *@a:first element
 *@b:second element
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - function that orders subarray and places pivot
 * by using lomuto partitioning scheme
 *
 * @array: Array of integers to sort
 * @size: Size of array
 * @low: Starting index of subarray
 * @high: last index of subarray
 *
 * Return: index partition
 */
int lomuto_partition(int *array, size_t size, int low, int high)
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
 * lomuto_sort - fucntion that implement the quicksort algorithm
 * through recursion.
 * @array: array of integers to sort.
 * @size: The size of the array.
 * @low: starting index of the array
 * @high: last index of the array
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int index;

	if (high - low > 0)
	{
		index = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, index - 1);
		lomuto_sort(array, size, index + 1, high);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using quicksort algorithm
 * @array: Array of integers to sort
 * @size: Size of array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto_sort(array, 0, size, size - 1);
}
