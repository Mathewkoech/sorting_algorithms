#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithim with the Knuth sequence.
 * @array: array of integers to sort.
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
	{
		return;
	}

	/* Initialize the gap using knuth sequence */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;
	for (; gap > 0; gap /= 3)
	{
		/* perform a insertion sort for the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			/* shift elements that are greater than temp to the right */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}
		/* print array after decreasing the interval */
		print_array(array, size);
	}
}
