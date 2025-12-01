#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


    void *thread(void * arg){
        int * iptr = (int *) arg;
        for(int i=0; i<*iptr; i++){
            printf("thread in esecuzione...\n");
            sleep(1); // dorme per 1 secondo per evitare di saturare la CPU
            }
        return NULL;
    }

    int main(){

        int a;
        printf("Inserisci un numero di passi dopo il quale terminare il thread:\n");
        scanf("%d", &a);
        pthread_t ptid = pthread_self();
        pthread_create(&ptid, NULL, thread, &a);
        pthread_join(ptid, NULL);
        printf("Thread terminato\n");
        return 0;


    
}