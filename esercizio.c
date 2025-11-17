#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int funzione1() { 
    int a = 5*3;
    return a; 
}
int funzione2() { 
    int b = 9 * 4;
    return b; 
}
int funzione3() {
    int c = 7 * 4;
    return c; 
}

int main() {
    pid_t pid1, pid2, pid3;
    int status;
    int val1, val2, val3;


    pid1 = fork();
    if (pid1 == 0){ 
        exit(funzione1());
    }

    pid2 = fork();
    if (pid2 == 0){

        exit(funzione2());
    }

    pid3 = fork();
    if (pid3 == 0){
     exit(funzione3());
    }

    waitpid(pid1, &status, 0);
    val1 = WEXITSTATUS(status);

    waitpid(pid2, &status, 0);
    val2 = WEXITSTATUS(status);

    waitpid(pid3, &status, 0);
    val3 = WEXITSTATUS(status);

    int somma = val1 + val2 + val3;
    printf("La somma è: %d\n", somma);

    return 0;
}
