//how many different ways can a number be written as a sum of at least 2 integers
#include <stdio.h>
static unsigned ways[10][10];

int main(void)
{
    const unsigned number = 5;
    unsigned sum = 0;
    unsigned ways_count = 0;
    unsigned valid = 0;
    unsigned col = 0;

    for (unsigned i = 1; i < number; i++)
    {
        for (unsigned j = 1; j < number; j++)
        {
            sum = i + j;
            ways[valid][0] = i;
            ways[valid][1] = j;
            col = 2;

            while(1)
            {
                if(sum > number)
                {
                    break;
                }
                else if(sum == number)
                {
                    valid++;
                    ways_count++;
                    break;
                }
                else
                {
                    sum += i;
                    ways[valid][col] = i;
                    col++;
                }
                
            }
        }
    }

    for(unsigned i = 0; i < valid; i++)
    {
        for(unsigned j = 0; j < 10; j++)
        {
            printf("%d ", ways[i][j]);
        }
        printf("\n");
    }

    return 0;
}