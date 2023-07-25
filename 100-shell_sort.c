#include "sort.h"

/**
 * shell_sort -> this function implements shell sort algorithm
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	int tmp, i;
	size_t j, gap = 1;

	if (!array || !size || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] < array[i])
				{
					tmp = array[i + gap];
					array[i + gap] = array[i];
					array[i] = tmp;
				}
				else
					break;
			}
		}
		print_array(array, size);
	}
}
