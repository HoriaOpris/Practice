//how many different ways can a number be written as a sum of at least 2 integers
#include <stdio.h>

int main(void)
{
    const unsigned number = 5;
    unsigned sum = 0;
    unsigned ways_count = 0;

    for (unsigned i = 1; i < number; i++)
    {
        for (unsigned j = 1; j < number; j++)
        {
            sum = i + j;
            printf(" %d %d", i, j);

            while(1)
            {
                if(sum > number)
                {
                    printf(" Fail");
                    break;
                }
                else if(sum == number)
                {
                    printf(" Correct");
                    ways_count++;
                    break;
                }
                else
                {
                    printf(" %d", i);
                    sum += i;
                }
                
            }

            printf("\n");
        }
    }

    printf("\nWays: %d\n", ways_count);

    return 0;
}