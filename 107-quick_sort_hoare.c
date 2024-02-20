#include "sort.h"

/**
 * swapp - swaps two integers
 * @a: int
 * @b: int
 * Return:nothing
 */
void swapp(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * pivot_partition - Partition an array
 * @array: Array
 * @lowest: integer
 * @highest: integer
 * @size: size of array
 * Return: index of pivot
 */
int pivot_partition(int *array, int lowest, int highest, size_t size)
{
	int pivot = array[highest];
	int i = lowest, j = highest;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swapp(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}
/**
 * hoare_qsort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @lowest: The lowest value of the array
 * @highest: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void hoare_qsort(int *array, int lowest, int highest, size_t size)
{
	int i;

	if (lowest < highest)
	{
		i = pivot_partition(array, lowest, highest, size);
		if (i > lowest)
		{
			hoare_qsort(array, lowest, i, size);
		}
		hoare_qsort(array, i + 1, highest, size);
	}
}
/**
 * quick_sort_hoare - Quick Sort using hoare partition
 * @array: Array
 * @size: Size of The Array
 * Return: Sorted Array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	hoare_qsort(array, 0, size - 1, size);
}
