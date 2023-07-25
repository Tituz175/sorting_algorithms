#!/usr/bin/python3

def shell_sort(arr):
    gap = len(arr)//2

    while gap >= 1:
        j = gap
        while (j < len(arr)):
            i = j - gap
            while (i >= 0):
                if (arr[i + gap] > arr[i]):
                    break
                else:
                    arr[i + gap], arr[i] = arr[i], arr[i + gap]
                    print(arr)
                i -= gap
            j += 1
        gap //= 2
    print(arr)


my_list = [23, 29, 15, 19, 31, 7, 9, 5, 2]

shell_sort(my_list)
