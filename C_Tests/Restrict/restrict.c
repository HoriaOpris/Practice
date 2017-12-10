#include <stdio.h>

void initTwoVars(int *restrict a, int *restrict b, int *restrict c)
{
    *a += *c;
    *b += *c;
}

int main(void)
{
    int x = 1;
    int y = 5;
    int z = 10;

    initTwoVars(&z, &y, &z);

    /*
    Expected vs actual result
    x = 1   |   1
    y = 25  |   25 
    z = 20  |   20
    */
    printf("Result\n"
           "x:%d\n"
           "y:%d\n"
           "z:%d\n",
           x, y, z);

    return 0;
}