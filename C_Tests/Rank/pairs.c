#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII_NORM 48u

//input line 1 number of items. line 2 space separated item color
//output total number of color pairs

struct in
{
    unsigned items;
    unsigned *color; //array the size of items
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
    while (1)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            input.color[item_no] = str[i - 1] - ASCII_NORM;
            item_no++;
        }

        if (str[i] == '\n')
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

static void Pairs(struct in *input)
{
    int colors[10][3];

    unsigned last_empty = 0;
    (void)memset(colors, 0, sizeof(colors));

    for (unsigned i = 0; i < input->items; i++)
    {
        for (unsigned j = 0; j < 10; j++)
        {
            if (colors[j][0] == input->color[i])
            {
                colors[j][1]++;
                break;
            }

            if (j == 9)
            {
                colors[last_empty][0] = input->color[i];
                colors[last_empty][1] = 1;
                last_empty++;
            }
        }
    }
    //calc pairs
    for(unsigned i = 0; i < 10; i++)
    {
        while((colors[i][1] / 2) != 0)
        {
            colors[i][1] = colors[i][1] / 2;
            colors[i][2]++;
        }
    }

    for (unsigned i = 0; i < 10; i++)
        printf("%d ", colors[i][2]);

    printf("\n");


}

int main(void)
{
    struct in input = InputGet();

    Pairs(&input);

    return 0;
}