#include <stdio.h>

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
{
    unsigned tempVal;
    unsigned tempID = 0;
    unsigned value1 = 0;
    unsigned value2 = 0;

    for (unsigned i = size; i > 0; i--)
    {
        value1 = arr[i];
        tempVal = 2020 - arr[i];

        for (unsigned j = tempID; j < size; j++)
        {
            if (tempVal > arr[j])
            {
                /*Do nothing, go to next index*/
            }
            else if (tempVal == arr[j])
            {
                value2 = arr[j];
                break;
            }
            else
            {
                tempID = j;
                break;
            }
        }
        if (value1 + value2 == 2020)
        {
            break;
        }
    }

    return value1 * value2;
}

int main(void)
{
    Sort(input, ARR_SIZE(input));
    printf("Mutliplied: %d\n", GetPairMultiplication(input, ARR_SIZE(input)));

    return 0;
}