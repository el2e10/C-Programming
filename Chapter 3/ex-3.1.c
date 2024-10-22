#include <stdio.h>

int binary_search(int[], int, int);

int main()
{
    int array[10] = {1, 3, 7, 10, 27, 32, 43, 55, 66, 89}, key = 89, size = 9;
    int index = binary_search(array, size, key);
    if (index == -1)
    {
        printf("The %d is not found in the array\n", key);
    }
    else
    {
        printf("%d is found in array at position %d\n", key, index);
    }
    return 0;
}

int binary_search(int array[], int size, int key)
{
    int start = 0, end = size, mid = (start + end) / 2;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (array[mid] < key)
        {
            printf("< %d %d\n", start, end);
            start = mid + 1;
        }
        else
        {
            printf("> %d %d\n", start, end);
            end = mid - 1;
        }
    }
    if (array[mid] == key)
    {
        return mid;
    }
    else
    {
        return -1;
    }
}
