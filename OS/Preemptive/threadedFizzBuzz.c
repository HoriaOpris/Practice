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
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex3;

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

static void WaitToSync(unsigned thread, pthread_mutex_t *mutex, unsigned n)
{
    volatile _Atomic static unsigned index[4];
    volatile unsigned min, min_index;

    pthread_mutex_lock(mutex);
    index[thread] = n;
    pthread_mutex_unlock(mutex);
SPIN:
    min = index[0];
    min_index = 0;

    for (unsigned i = 1; i < 4; i++)
    {
        pthread_mutex_lock(mutex);
        if (index[i] < min)
        {
            min = index[i];
            min_index = i;
        }
        pthread_mutex_unlock(mutex);
    }

    if((index[0] == index[1]) && (index[0] == index[2]) && (index[0] == index[3]) && (index[0] == 15))
        return;

    if (min_index != thread)
        goto SPIN;
    //else
        //printf("   thread %d | %d %d %d %d\n", thread, index[0], index[1], index[2], index[3]);
}

static void *fizz()
{
    for (unsigned i = 1; i <= fizzBuzzSize; i++)
    {
        WaitToSync(0, &mutex0, i);

        if (((i % 3) == 0) && ((i % 5) != 0))
            printf("fizz, ");
    }

    return NULL;
}

static void *buzz()
{
    for (unsigned i = 1; i <= fizzBuzzSize; i++)
    {
        WaitToSync(1, &mutex0, i);

        if (((i % 5) == 0) && ((i % 3) != 0))
            printf("buzz, ");
    }
    return NULL;
}

static void *fizzbuzz()
{
    for (unsigned i = 1; i <= fizzBuzzSize; i++)
    {
        WaitToSync(2, &mutex0, i);

        if (((i % 3) == 0) && ((i % 5) == 0))
            printf("fizzbuzz, ");
    }

    return NULL;
}

static void *number()
{
    for (unsigned i = 1; i <= fizzBuzzSize; i++)
    {
        WaitToSync(3, &mutex0, i);
        if (((i % 3) != 0) && ((i % 5) != 0))
            printf("%d, ", i);
    }

    return NULL;
}

/* gcc threadedFizzBuzz.c -Wall -lpthread */
int main(void)
{
    printf("\nSingle threaded fizzbuzz:\n");
    FizzBuzz(fizzBuzzSize);

    printf("\nMultithreaded fizzbuzz:\n");
    pthread_t threads[4];

    pthread_mutex_init(&mutex0, NULL);
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_mutex_init(&mutex3, NULL);

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