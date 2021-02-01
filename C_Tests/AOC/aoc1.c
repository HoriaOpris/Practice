#include <stdio.h>

#define ARR_SIZE(arr) sizeof(arr) / sizeof(arr[0])

static unsigned input[] = {
#include "input.txt"
};

//Bubble
static void Sort(unsigned *arr, unsigned size)
{
    while (1)
    {
        unsigned count;

        for (unsigned i = 0; i < size - 1; i++)
        {
            unsigned temp;

            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            else
            {
                count++;
            }
        }

        if (count == (size - 1))
            break;
        else
            count = 0;
    }
}

static unsigned GetPairMultiplication(unsigned *arr, unsigned size)
{
    return 0;
}

int main(void)
{
    Sort(input, ARR_SIZE(input));

    for (unsigned i = 0; i < ARR_SIZE(input); i++)
        printf("%d\n", input[i]);

    return 0;
}