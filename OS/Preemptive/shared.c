#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

int shared = 0;
unsigned lock = 0;
pthread_mutex_t mutex;

void *Thread0()
{
    for (int i = 0; i < 10000000; i++)
    {
        //while (lock == 1)
        //    ;
        pthread_mutex_lock(&mutex);
        //lock = 1;
        shared++;
        //lock = 0;
        pthread_mutex_unlock(&mutex);
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