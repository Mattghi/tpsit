//Nella funzione che viene utilizzata per avviare il thread resituisci il numero 25. E' una funzione void * per cui possiamo restituire un qualunque puntatore.
//Nella funzione puoi semplicemente dichiarare una variabile e restituire il suo puntatore.
//Per il momento lascia la main vuota. 
//COsa succede al codice? (ps. errore stack) Procedi creando il threa, fare il join recuperando il valore restituito.
//La funzione restituisce l'indirizzo di una variabile che non esiste piu.
//Soluzione: utilizzare mallo c  int*x = malloc(sizeof(int)); *x=10; return x;  il chiamante DEVE fare free.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


    void *thread(void * arg){
        int *x = malloc(sizeof(int));
        *x = 10;                            //Codice giusto
        return x;
        //int a = 25;  Codice sbagliato
        //return &a;
    }

    int main(){

        pthread_t ptid;
        pthread_create(&ptid, NULL, thread, NULL);
        int *result; // puntatore per ricevere il risultato dal thread

        //&result passa l'indirizzo del puntatore result.
        //in questo modo result conterra l indirizzo del valore restituito dal thread
        //*result sara quindi il valore effettivo restituito dal thread
        //il cast a (void**) e' neccessario perch e pthread_join si aspetta un puntatore a void*
        //e non un puntatore a int*(e' solo un problema di comiliatore)
        int join_result = pthread_join(ptid, (void **) &result);
        printf("Risultato dal thread: %i\n", *result);
        return 0;



    
}