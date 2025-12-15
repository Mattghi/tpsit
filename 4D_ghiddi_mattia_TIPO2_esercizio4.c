#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
void *f1 (void *arg){
    int *a = (int *)arg;
    int *min = malloc(10 * sizeof(int));
    *min = a[0];
    for(int i=0; i<10; i++){
        if(*min > a[i]){
            *min = a[i];
        }

    }   
    return min;
}
void *f2 (void *arg){
    int *a = (int *)arg;

    int *somma = malloc(sizeof(int));
    for(int i=0; i<10; i++){
        *somma += a[i];
    }   
    return somma;
}   

int main(){

    int a[10] = {1,2,3,4,5,10,20,30,40,50};
    
    pthread_t t1,t2;
    int *minimo;
    int *somma;
    pthread_create(&t1,NULL,f1,a);
    pthread_create(&t2,NULL,f2,a);
    pthread_join(t1,(void**)&minimo);
    pthread_join(t2,(void**)&somma);

    int risultato = *minimo + *somma;

    printf("Risultato finale: %d\n", risultato);

    free(minimo);
    free(somma);
    return 0;
}