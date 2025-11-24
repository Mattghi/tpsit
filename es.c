#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* function(){
    int *b = malloc(sizeof(int));      
    *b = 10;                            //contenuto nell'heap, non da segmentation fault.
    return b;
}

int main(){
    int *c;
    c = function();
    printf("%d\n", *c);
    free(c);                            //libero la memoria allocata nell'heap
    return 0;
}