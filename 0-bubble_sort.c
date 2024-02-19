#include "sort.h"

/**
*bubble_sort - sorts an array of integers in ascending
*order using the Bubble sort algorithm
*@array: input array of integers
*@size: size of array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int temp;
	bool swap = false;

	if (size < 2)
		return;
	while (j < size)
	{
		swap = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				swap = true;
				print_array(array, size);
			}
		}
		if (swap == false)
			break;
		j++;
	}
}
