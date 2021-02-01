#include<stdio.h>

static unsigned input[] = {
    #include"input.txt"
};

static unsigned *Sort(unsigned *arr, unsigned size)
{
    return (unsigned *)0;
}

static unsigned GetPairMultiplication(unsigned *arr, unsigned size)
{
    return 0;
}

int main(void)
{


    for(unsigned i = 0; i < sizeof(input) / sizeof(input[0]); i++)
        printf("%d\n", input[i]);

    return 0;
}