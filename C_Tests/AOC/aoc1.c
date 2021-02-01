#include<stdio.h>
#include <stdlib.h>

#define ARR_SIZE(arr) sizeof(arr) / sizeof(arr[0])

static unsigned input[] = {
    #include"input.txt"
};

static unsigned *Sort(unsigned *arr, unsigned size)
{
    unsigned *sorted = malloc(size);


    return sorted;
}

static unsigned GetPairMultiplication(unsigned *arr, unsigned size)
{
    return 0;
}

int main(void)
{
    unsigned *sorted = Sort(input, ARR_SIZE(input));

    for(unsigned i = 0; i < ARR_SIZE(input); i++)
        printf("%d\n", sorted[i]);

    return 0;
}