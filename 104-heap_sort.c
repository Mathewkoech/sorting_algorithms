#include "sort.h"

/**
* heapify - heapify array at index i
* @i: index
* @heap: size of heap
* @size: size of array
* @array: array
*/

void heapify(int *array, int heap, int i, int size)
{
	int largest = i, left_child = 2 * i + 1, right_child = 2 * i + 2, temp;

	if (left_child < heap && array[left_child] > array[largest])
	{
		largest = left_child;
	}
	if (right_child < heap && array[right_child] > array[largest])
	{
		largest = right_child;
	}
	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, heap, largest, size);
	}
}

/**
* heap_sort - Sorts array with heap sort algorithm
* @array: array to sort
* @size: Size of array to sort
*/

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
		{
			print_array(array, size);
		}
		heapify(array, i, 0, size);
	}
}
