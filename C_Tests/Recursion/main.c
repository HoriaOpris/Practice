#include<stdio.h>

// 1,1,2,3,5,8,13

int fib(int f)
{
    if(f == 0)
    {
        return 0;
    }
    else if(f == 1)
    {
        return 1;
    }
    else
    {
        return fib(f - 1) + fib(f - 2);
    }
}

int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    
    return factorial(n - 1) * n;
}

int sum(int n)
{
    if(n == 1)
        return 1;

    return sum(n-1) + n;
}

int main(void)
{
    printf("%d \n", fib(7));
    printf("%d \n", factorial(9));
    printf("%d \n", sum(5));
    
    return 0;
}