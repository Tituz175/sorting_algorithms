#include "sort.h"

void count_sort(int *array, size_t size, int index);

void count_sort(int *array, size_t size, int index)
{
    unsigned int i, temp;
    int *count_array, *sorted_array;

    count_array = malloc(sizeof(int) * 10);

    if (count_array == NULL)
        return;
    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
    {
        free(count_array);
        return;
    }

    for (i = 0; i < 10; i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
    {
        temp = array[i] / index;
        count_array[temp % 10]++;
    }

    for (i = 1; i < 10; i++)
        count_array[i] = count_array[i] + count_array[i - 1];


    for (i = size - 1; (int)i > -1; i--)
    {
        temp = array[i] / index;
        sorted_array[count_array[temp % 10] - 1] = array[i];
        count_array[temp % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = sorted_array[i];

    print_array(array, size);

    free(sorted_array);
    free(count_array);
}

void radix_sort(int *array, size_t size)
{
    unsigned int i;
    int max_value = array[0];

    for (i = 1; i < size; i++)
        max_value = max_value > array[i] ? max_value : array[i];

    for (i = 1; max_value / i > 0; i *= 10)
        count_sort(array, size, i);
}