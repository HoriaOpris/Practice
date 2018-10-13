#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
// gcc start.c -lpthread

int g = 0; 
  
void *myThreadFun(void *vargp) 
{ 
    static int s = 0; 
  
    printf("Thread ID: %d, Static: %d, Global: %d\n", *((int *)vargp), ++s, ++g); 
} 
  
int main() 
{ 
    int i; 
    pthread_t tid; 
  
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, myThreadFun, &tid); 
  
    pthread_exit(NULL); 
    return 0; 
} 
