#include "sort.h"

/**
*bubble_sort - sorts an array of integers in ascending
*order using the Bubble sort algorithm
*@array: input array of integers
*@size: size of array
*/

void bubble_sort(int *array, size_t size)
{
    size_t i;
    int swapper = -1; /* for checking if swap has been done */
    int temp;

    if (size < 2)
    {
	return;
    }

    while (swapper)
    {
	swapper = 0;
	for (i = ; i < size-1; i++)
	{
	    if (array[i] > array[i + 1])
	    {
		temp = array[i];
		array[i] = array[i + 1];
		temp = array[i + 1];
		swapper++;
		print_array(array, size); /*print array*/
	    }
	}
    }

}
