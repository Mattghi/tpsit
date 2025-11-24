#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *codice_thread(void * arg){
    printf("Ciao sono il thread!\n");
    return NULL;
}

int main(){
printf("Hey sono il main!\n");
pthread_t ptid;
pthread_create(&ptid, NULL, codice_thread, NULL);
sleep(2); //oppure pthread_join(ptid,NULL)
return 0;

}
