#include "sort.h"

/**
 * selection_sort -> this function that sorts an array
 * of integers in ascending order using the Selection sort algorithm
 *
 * @array: an array of integers
 * @size: the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, smallest;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}

		if (smallest != i)
		{
			tmp = array[i];
			array[i] = array[smallest];
			array[smallest] = tmp;
			print_array(array, size);
		}
	}
}
