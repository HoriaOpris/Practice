#include<stdio.h>
#include<stdlib.h>
#define ASCII_NORM 48u

//input line 1 number of items. line 2 space separated item color
//output total number of color pairs

struct in
{
    unsigned items;
    unsigned *color;//array the size of items 
};

static struct in InputGet(void)
{
    struct in input;
    char line[1024];
    scanf("%d\n", &input.items);
    
    input.color = malloc(sizeof(int) * input.items);

    char *str = fgets(line, 1024, stdin);
    unsigned item_no = 0;
    unsigned i = 0;
    //items are separated by space. loop and store items as separate array input
    while(1)
    {
        if(str[i] == ' ' || str[i] == '\n')
        {
            input.color[item_no] = str[i - 1] - ASCII_NORM;
            item_no++;
        }

        if(str[i] == '\n')
        {
            break;
        }
        else
        {
            i++;
        }
    }

    return input;
}

int main (void)
{
    struct in input = InputGet();

    printf("\n----\n");
    for(unsigned i = 0; i < input.items; i++)
    {
        printf(" %d",input.color[i]);
    }

    return 0;
}