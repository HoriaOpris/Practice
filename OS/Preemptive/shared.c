#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <stdatomic.h>

//_Atomic int shared = 0;
int shared = 0;
int integrity = ~0;
atomic_flag lock = ATOMIC_FLAG_INIT;
pthread_mutex_t mutex;

void *Thread0()
{
    for (int i = 0; i < 10000000; i++)
    {
        while (atomic_flag_test_and_set(&lock))
            ;
        //pthread_mutex_lock(&mutex);

        if (shared == ~integrity)
        {
            shared++;
            integrity = ~shared;
        }
        else
        {
            printf("\n fail ");
            break;
        }

        atomic_flag_clear(&lock);
        //pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[3];
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&threads[0], NULL, Thread0, (void *)0);
    pthread_create(&threads[1], NULL, Thread0, (void *)1);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("%d\n", shared);

    pthread_exit(NULL);

    return 0;
}