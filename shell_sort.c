#include "sort.h"
#include <stdio.h>

void shell_sort(int *array, int size);

void shell_sort(int *array, int size)
{
    int j, i, tmp, gap = 1;

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
        print_array(array, (size_t)size);
    }
}

int main(void)
{
    int size;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

    size = sizeof(array) / sizeof(array[0]);
    print_array(array, (size_t)size);
    printf("\n");
    shell_sort(array, size);
    printf("\n");
    print_array(array, (size_t)size);

    return (0);
}