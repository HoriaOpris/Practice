//how many different ways can a number be written as a sum of at least 2 integers
#include <stdio.h>
#include "common.h"

#define COL_SIZE 10
#define ROW_SIZE 40

static unsigned ways[COL_SIZE][ROW_SIZE];

static void RemoveDuplicates(void)
{
    unsigned cnt = 0;
    
    for (unsigned i = 0; i < ROW_SIZE; i++)
    {
        for (unsigned j = 0; j < ROW_SIZE; j++)
        {
            cnt = 0;
            
            if (i == j)
                continue;
            
            for (unsigned k = 0; k < COL_SIZE; k++)
            {
                if (ways[i][k] == ways[j][k])
                {
                    cnt++;
                }
            }
            
            //delete line
            if (cnt == COL_SIZE)
            {
                for (unsigned l = 0; l < COL_SIZE; l++)
                {
                    ways[j][l] = 0;
                }
            }
        }
    }
}

static unsigned CountWays(void)
{
    unsigned ways_count = 0;
    
    for(unsigned i = 0; i < ROW_SIZE; i++)
    {
        for(unsigned j = 0; j < COL_SIZE; j++)
        {
            if(ways[i][j] != 0)
            {
                ways_count++;
                break;
            }
        }
    }
    
    return ways_count;
}

int main(void)
{
    const unsigned number = 6;
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
            
            while (1)
            {
                if (sum > number)
                {
                    for(unsigned k = 0; k < COL_SIZE; k++)
                    ways[valid][k] = 0;
                    break;
                }
                else if (sum == number)
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
    
    for (unsigned i = 0; i < valid; i++)
    {
        Sort(&ways[i][0], COL_SIZE);
    }
    
    RemoveDuplicates();
    printf("Ways: %d \n", CountWays());
    
    for (unsigned i = 0; i < valid; i++)
    {
        for (unsigned j = 0; j < COL_SIZE; j++)
        {
            if(ways[i][j]!=0)
                printf("%d ", ways[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
