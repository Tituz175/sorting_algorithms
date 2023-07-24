#include "sort.h"

/**
 * partition -> this function partition the array, loop through the array
 * and swap array element if it's less than the pivot value and return the
 * position of the recently sorted pivot element
 *
 * @array: array of integers to be partitioned
 * @low: the lowest index of the array
 * @high: the highest index of the array
 * @size: the size of the array
 * Return: the position of the most recently sorted pivot element
 */

int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	i = low - 1;
	pivot = array[high];

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * lomuto -> this function recursively calls itself and
 * the partition function
 *
 * @array: array of integers
 * @low: the lowest index of the array
 * @high: the highest index of the array
 * @size: the size of the array
 */

void lomuto(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		lomuto(array, low, pi - 1, size);
		lomuto(array, pi + 1, high, size);
	}
}

/**
 * quick_sort -> this function implements the quick sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	lomuto(array, 0, size - 1, size);
}
