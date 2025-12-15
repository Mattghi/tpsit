#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){

int x = 1;
printf("[P] Valore iniziale di x = %d\n", x);

pid_t pid = fork();

if(pid == 0){

    x = 2;
    printf("[F] x nel figlio = %d\n", x);
    exit(0);

}else if(pid > 0){
    int status;
    wait(&status);
    printf("[P] x nel padre dopo la terminazione del figlio = %d\n", x);
}else{
    perror("errore fork");
}
return 0;
}


//Mi aspetto che x  nel figlio sia 2 , mentre nel padre stampi 1, perche' il figlio e il padre hanno spazi di memoria separati e quindi
//la modifica di x nel figlio non influenza il valore di x nel padre.


