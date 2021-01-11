#include<stdio.h>
#include<stdlib.h>

//input line 1 number of items. line 2 space separated item color
//output total number of color pairs

struct in
{
    unsigned items;
    int *color;//array the size of items 
};

static struct in InputGet(void)
{
    struct in input;
    scanf("%d", &input.items);
    input.color = malloc(sizeof(int) * input.items);

    input.color[1] = 3;

    return input;
}

int main (void)
{
    struct in input = InputGet();

    printf("in:%d val:%d\n", input.items, input.color[1]);

    return 0;
}