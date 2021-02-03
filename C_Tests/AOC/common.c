#include "common.h"

//Bubble
extern void Sort(unsigned *arr, unsigned size)
{
    unsigned swap;

    for (unsigned i = 0; i < size - 1; i++)
    {
        for (unsigned j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}