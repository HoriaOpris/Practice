#include <stdio.h>
#include <time.h>

#define ARR_SIZE(arr) sizeof(arr) / sizeof(arr[0])

static unsigned input[] = {
#include "input.txt"
};

//Bubble
static void Sort(unsigned *arr, unsigned size)
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

static unsigned GetPairMultiplication(unsigned *arr, unsigned size)
{ //brute force
    unsigned multiplied = 0;

    for (unsigned i = 0; i < size; i++)
    {
        for (unsigned j = 0; j < size; j++)
        {
            if ((arr[i] + arr[j]) == 2020)
            {
                multiplied = arr[i] * arr[j];
                break;
            }
        }
    }

    return multiplied;
}

int main(void)
{
    double time_spent = 0.0;
    clock_t begin = clock();

    Sort(input, ARR_SIZE(input));

    printf("Mutliplied: %d\n", GetPairMultiplication(input, ARR_SIZE(input)));

    clock_t end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("It took your program %f to run\n", time_spent);

    return 0;
}