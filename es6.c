//il thread funziona all'infinito perche' il processo rimane in attesa dello scanf. inserito un numero, il thread termina.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread(void * arg){
    while(-1){
        printf("thread in esecuzione...\n");
        sleep(1); // dorme per 1 secondo per evitare di saturare la CPU
    }
    return NULL;
}

    int main(){

        int a;
        pid_t pid = getpid();
        pthread_t ptid = pthread_self();
        pthread_create(&ptid, NULL, thread, NULL);
        printf("Premi un numero per terminare il thread\n");
        scanf("%d", &a); 
        pthread_cancel(ptid);
        sleep(5);
        return 0;


    
}
