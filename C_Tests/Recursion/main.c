#include <stdio.h>

// 1,1,2,3,5,8,13

int fib(int f)
{
    if (f == 0)
    {
        return 0;
    }
    else if (f == 1)
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
    if (n == 0)
    {
        return 1;
    }

    return factorial(n - 1) * n;
}

int sum(int n)
{
    if (n == 1)
        return 1;

    return sum(n - 1) + n;
}

// sn = sn−1 + 3. Calculate its first four terms, by considering that:
//(a) s0 = 0, and (b) s0 = 4. Provide a nonrecursive definition of sn in both cases.
int ex_1(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return ex_1(n - 1) + 3;
}


// Exercise 2.1 — Let n be some positive integer. Consider the problem of determining the number of bits set
//  to 1 in the binary representation of n (i.e., n expressed in base 2). For example, for n = 25 = 11001
//  (the subscript indicates the base in which a number is expressed), the result is three bits set to 1.
//  Indicate the size of the problem and provide a mathematical expression for such size.
unsigned int bitsSetTo1(unsigned int n)
{
    if ((n == 0) || (n == 1))
        return n;

    return bitsSetTo1(n >> 1) + (n & 1);
}

// print digits with a new line
void PrintDigits(unsigned int n)
{
    if(n == 0)
        return;

    PrintDigits(n / 10);
    printf("\t%d\n", n % 10);
}

// Define a recursive function that calculates the largest value in a list a of n elements, 
// where the decomposition simply reduces the size of the problem by a unit.
int largestElement(int n[], int size)
{
    static int max = -1000;

    if(size == 0)
        return max;

    if(n[0] > max)
        max = n[0];

    return largestElement(++n, size - 1) ;
}

int main(void)
{
    printf("%d \n", fib(7));
    printf("%d \n", factorial(9));
    printf("%d \n", sum(5));
    printf("%d \n", ex_1(4));
    printf("0x%x No of 1s: %d \n", 25, bitsSetTo1(25));
    PrintDigits(2743);
    int arr[] = {5,8,1,3,0,-1,2, -5, 12, 1, 3, 4};
    printf("Largest element: %d\n", largestElement(arr, (sizeof(arr)/sizeof(arr[0]))));

    return 0;
}