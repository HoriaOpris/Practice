#include <stdio.h>

int list[] = {5,4,6,1,4};
extern void Sort(int *a, int size);

int main(void)
{
    Sort(list, 5);

    for(unsigned i =0; i < 5; i++)
        printf("%d ", list[i]);

    return 0;
}