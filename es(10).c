#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>

void * thread1(void*args){
    int *g = malloc(sizeof(int));
    *g = 10  + 5;
    printf("Il risultato del thread1 e' %d\n", *g);
    return g;    
}

void * thread2(void*args){
    int *h = malloc(sizeof(int));
    *h = 7 * 3;
    printf("Il risultato del thread2 e' %d\n", *h);
    return h;
    
}



   

int main(){
    
pid_t pid = fork();

if(pid == 0){
    printf("Il mio PID e' %d, sono il figlio \n", getpid());
    pthread_t a;
    pthread_t b;
    int *d;
    int *c;
    pthread_create(&a, NULL, thread1, NULL);
    pthread_create(&b, NULL, thread2, NULL);
    pthread_join(a, (void**)&d);
    pthread_join(b, (void**)&c);
    int e = *d+*c+2;
    free(d);
    free(c);
    printf("La mia somma e' %d\n", e);
    
}else if(pid > 0){
    printf("Il mio PID e' %d, sono il padre \n", getpid());
    
}else{
    perror("Fork");
}




  
   return 0;
   
}
