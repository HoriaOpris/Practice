/*
Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

static const unsigned fizzBuzzSize = 15;
pthread_mutex_t mutex0;

unsigned *p1, *p2, *p3, *p4;

static void FizzBuzz(unsigned n)
{
    for (unsigned i = 1; i <= n; i++)
    {
        if ((i % 3) == 0)
            printf("fizz");

        if ((i % 5) == 0)
            printf("buzz");

        if (((i % 3) != 0) && ((i % 5) != 0))
            printf("%d", i);

        if (i == n)
            printf(".\n");
        else
            printf(", ");
    }
}

static void *fizz()
{
    p1 = malloc(sizeof(unsigned) * fizzBuzzSize);

    for (unsigned i = 1; i <= fizzBuzzSize; i++)
    {
        if (((i % 3) == 0) && ((i % 5) != 0))
            p1[i - 1] = 100;
    }

    return NULL;
}

static void *buzz()
{
    p2 = malloc(sizeof(unsigned) * fizzBuzzSize);

    for (unsigned i = 1; i <= fizzBuzzSize; i++)
    {
        if (((i % 5) == 0) && ((i % 3) != 0))
            p2[i - 1] = 200;
    }

    return NULL;
}

static void *fizzbuzz()
{
    p3 = malloc(sizeof(unsigned) * fizzBuzzSize);

    for (unsigned i = 1; i <= fizzBuzzSize; i++)
    {
        if (((i % 3) == 0) && ((i % 5) == 0))
            p3[i - 1] = 300;
    }

    return NULL;
}

static void *number()
{
    p4 = malloc(sizeof(unsigned) * fizzBuzzSize);

    for (unsigned i = 1; i <= fizzBuzzSize; i++)
    {
        if (((i % 3) != 0) && ((i % 5) != 0))
            p4[i - 1] = 400;
    }

    return NULL;
}

/* gcc threadedFizzBuzz.c -Wall -lpthread */
int main(void)
{
    printf("\nSinglethreaded fizzbuzz:\n");
    clock_t begin = clock();
    FizzBuzz(fizzBuzzSize);
    clock_t end = clock();
    double executionTime = (double)(end - begin);
    printf("Singlethreaded execution time: %f microseconds", executionTime);

    printf("\nMultithreaded fizzbuzz:\n");
    begin = clock();
    pthread_t threads[4];

    pthread_mutex_init(&mutex0, NULL);

    pthread_create(&threads[0], NULL, fizz, (void *)0);
    pthread_create(&threads[1], NULL, buzz, (void *)1);
    pthread_create(&threads[2], NULL, fizzbuzz, (void *)2);
    pthread_create(&threads[3], NULL, number, (void *)3);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    for(unsigned i = 0; i < fizzBuzzSize; i++)
    {
        if(p1[i] == 100 && p2[i] != 200)
            printf("fizz, ");

        if(p2[i] == 200 && p1[i] != 100)
            printf("buzz, ");
        
        if(p3[i] == 300)
            printf("fizzbuzz, ");

        if(p4[i] == 400)
            printf("%d, ",i + 1);
    }

    end = clock();
    executionTime = (double)(end - begin);
    printf("Multithreaded execution time: %f microseconds", executionTime);
    printf("\n\n");

    return 0;
}