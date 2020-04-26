#include<pthread.h>
#include<stdio.h>

#define NUMTHREADS 5
int val = 5;
pthread_mutex_t mutex;

void * hello(void * id) {
    pthread_mutex_lock(&mutex);
    printf("Hello world %ld, %d !\n", (long)id, val);
    val += val;
    pthread_mutex_unlock(&mutex);
}

void func(void) {
    printf("val %d\n", val);
}

int main() {
    pthread_t hilos[NUMTHREADS];
    for (long i = 0; i < NUMTHREADS; i++) {
        pthread_create(&hilos[i], NULL, hello,(void *)i);
    }
    pthread_exit(NULL);
}