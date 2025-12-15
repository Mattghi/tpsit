#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(){

    float *a = malloc(50 * sizeof(float));

    for(int i=0; i<50; i++){
        a[i] = i;
    }

    printf("Inserimento terminato\n");
    
    for(int i=0; i<50; i++){
        printf("Valore a[%d]: %f\n", i, a[i]);
    }

    free(a);  

    return 0;
}
