#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){

pid_t a = fork();
pid_t b = fork();
pid_t c = fork();

int e;
int f;
int g;
int moltiplicazione;


if(a == 0){
    e = 5 - 3;
    exit(e);
}

if(b == 0){
    f= 59 + 74;
    exit(f);
}
if(c == 0){
    g = 44 + 77;
    exit(g);
}

if(a > 0 && b > 0 && c > 0){
    int status_a;
    int status_b;
    int status_c;

    waitpid(a, &status_a, 0);
    waitpid(b, &status_b, 0);
    waitpid(c, &status_c, 0);

    int valore_a = WEXITSTATUS(status_a);
    int valore_b = WEXITSTATUS(status_b);
    int valore_c = WEXITSTATUS(status_c);

    moltiplicazione = valore_a * valore_b * valore_c;

    printf("Risultato totale = %d\n", moltiplicazione);
}

if(a < 0 || b < 0 || c < 0){
    perror("errore fork");
}


return 0;
}

