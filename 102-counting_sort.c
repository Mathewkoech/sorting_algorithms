#include "sort.h"
/**
 * get_high - Get the highest value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The highest integer in the array.
 */
int get_high(int *array, int size)
{
	int high, i;

	for (high = array[0], i = 1; i < size; i++)
	{
		if (array[i] > high)
			high = array[i];
	}
	return (high);
}
/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *frequency, *sorted, high, i;

	if (array == NULL || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	high = get_high(array, size);
	frequency = malloc(sizeof(int) * (high + 1));
	if (frequency == NULL)
	{
		free(sorted);
		return;
	}
	for (i = 0; i < (high + 1); i++)
		frequency[i] = 0;
	for (i = 0; i < (int)size; i++)
		frequency[array[i]] += 1;
	for (i = 0; i < (high + 1); i++)
		frequency[i] += frequency[i - 1];
	print_array(frequency, high + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[frequency[array[i]] - 1] = array[i];
		frequency[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(frequency);
}
