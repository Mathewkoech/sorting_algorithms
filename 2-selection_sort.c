#include "sort.h"
#include <stdbool.h>

/**
 *selection_sort - sorts an array of integers in ascending
 *order using the Bubble sort algorithm
 *@array: input array of integers
 *@size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int min;
	size_t x, i = 0, j = 0;
	bool sort;

	while (i < size)
	{
		j = i;
		sort = false;
		min = array[i];
		while (j < size - 1)
		{
			if (min > array[j + 1])
			{
				sort = true;
				min = array[j + 1];
				x = j + 1;
			}
			j++;
		}
		if (sort)
		{
			array[x] = array[i];
			array[i] = min;
			print_array(array, size);
		}
		i++;
	}
}
