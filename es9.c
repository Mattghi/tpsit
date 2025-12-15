#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>



void *moltiplicazione1(void *args){
    int *c = malloc(sizeof(int));
    *c = 5 * 4;
    return c;
   
}
void *moltiplicazione2(void *args){
    int *b = malloc(sizeof(int));
   *b = 7 * 3;
    return b;
    
}
void *somma(void *args){    
    int** som = (int**)args;
    int *a = malloc(sizeof(int));
    *a = *(som[0]) + *(som[1]) + 9;
    return a;
}
   

int main(){
    
    int *a;
    int *b;
    int *c;
    
    pthread_t e;
    pthread_t f;
    pthread_t g;

pthread_create(&e, NULL, moltiplicazione1, NULL);
pthread_create(&f, NULL, moltiplicazione2, NULL);
pthread_join(e, (void**)&c);
pthread_join(f, (void**)&b);
int *molt[2] = {c,b};

pthread_create(&g, NULL, somma, molt);
pthread_join(g, (void**)&c);
printf("La somma e' %d", *c);
free(b);
free(c);

  
   return 0;
   
}
