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

static const unsigned fizzBuzzSize = 15;

static void FizzBuzz(unsigned n)
{
    for (unsigned i = 1; i <= n; i++)
    {
        if ((i % 3) == 0)
        {
            printf("fizz");
        }

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
    printf("1");

    return NULL;
}

static void *buzz()
{
    printf("2");

    return NULL;
}

static void *fizzbuzz()
{
    printf("3");

    return NULL;
}

static void *number()
{
    printf("4");

    return NULL;
}

/* gcc threadedFizzBuzz.c -Wall -lpthread */
int main(void)
{
    printf("\nSingle threaded fizzbuzz:\n");
    FizzBuzz(fizzBuzzSize);

    printf("\nMultithreaded fizzbuzz:\n");
    pthread_t threads[4];
    //pthread_mutex_init(&mutex, NULL);

    pthread_create(&threads[0], NULL, fizz, (void *)0);
    pthread_create(&threads[1], NULL, buzz, (void *)1);
    pthread_create(&threads[2], NULL, fizzbuzz, (void *)2);
    pthread_create(&threads[3], NULL, number, (void *)3);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    printf("\n\n");
    return 0;
}