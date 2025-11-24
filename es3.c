#include <stdio.h>
#include <pthread.h>

int main() {
    pthread_t tid = pthread_self();   // ottieni ID del thread corrente
    printf("Thread id: %lu\n", tid);
    return 0;
}
