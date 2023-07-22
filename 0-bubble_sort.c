#include "sort.h"

void bubble_sort(int *array, size_t size)
{
    unsigned long int i, j;
    int tmp;
    int swapped = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - (i + 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j + 1] = tmp;
                print_array(array, size);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}