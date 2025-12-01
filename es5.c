//Nel main stampa il pid del processo, stampa il tid del thread principale e stampa il tid di questo nuovo thread,
//nel thread stampa il pid del processo e stampa il tid del thread.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *codice_thread(void * arg){
    pid_t pid = getpid();
    printf("Pid del processo: %d\n", pid);
    printf("tid del thread: %lu\n", pthread_self());
    return NULL;
}

int main(){
    pid_t pid = getpid();
printf("Pid del processo: : %d\n tid del thread principale: %lu\n",pid, pthread_self());
pthread_t ptid;
pthread_create(&ptid, NULL, codice_thread, NULL);
printf("tid del nuovo thread: %lu\n", ptid);
pthread_join(ptid, NULL);
return 0;

}