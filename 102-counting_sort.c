#include "sort.h"
#include <stdio.h>

/**
 * counting_sort -> this function implements the counting sort
 * algorithm
 *
 * @array: the arrays of integers to be sort
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	unsigned int i, temp, key;
	int *count_array, *sorted_array;

	if (!array || size < 2)
		return;

	key = array[0];
	for (i = 1; i < size; i++)
		key = key > (unsigned int)array[i] ? key : (unsigned int)array[i];
	count_array = malloc(sizeof(int) * key + 1);
	if (count_array == NULL)
		return;
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = 0; i <= key; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= key; i++)
		count_array[i] = count_array[i] + count_array[i - 1];

	print_array(count_array, key + 1);

	for (i = size - 1; (int)i > -1; i--)
	{
		count_array[array[i]] = count_array[array[i]] - 1;
		temp = count_array[array[i]];
		sorted_array[temp] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(count_array);
	free(sorted_array);
}
