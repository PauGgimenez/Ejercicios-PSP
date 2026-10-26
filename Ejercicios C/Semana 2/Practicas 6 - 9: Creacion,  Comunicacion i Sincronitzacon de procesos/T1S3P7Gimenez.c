#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) { 
    pid_t pid; 
    
    /* Bucle para crear exactamente 3 procesos hijos directos */
    for(int i = 0; i < 3; i++) {
        pid = fork();

        if (pid == 0) {
            /* El proceso hijo imprime su mensaje y termina inmediatamente */
            printf("Jo soc el fill %d, el meu pare és PID=%d, jo soc PID=%d.\n", (i + 1), getppid(), getpid());
            exit(0); 
        }
    }
    
    /* El proceso padre espera a que sus 3 hijos terminen para que no queden huérfanos */
    for(int i = 0; i < 3; i++) {
        wait(NULL); 
    }

    return 0;
}
