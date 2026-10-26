#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) { 
    pid_t pid1, pid2, pid3; 
    
    pid1 = fork(); /* El Padre crea al primer hijo */

    if (pid1 == 0) { 
        /* --- BLOQUE DEL HIJO 1 --- */
        printf("Soc el fill 1 (PID=%d, fill de %d)\n", getpid(), getppid()); 
        exit(0); 
        
    } else { 
        /* --- BLOQUE DEL PADRE --- */
        pid2 = fork(); /* El Padre crea al segundo hijo */
        
        if (pid2 == 0) { 
            /* --- BLOQUE DEL HIJO 2 --- */
            pid3 = fork(); /* El Fill 2 crea a su propio hijo (nieto) */
            
            if (pid3 == 0) {
                /* --- BLOQUE DEL NET --- */
                printf("Soc el net (PID=%d, fill de %d)\n", getpid(), getppid());
                exit(0);
            } else {
                /* --- CONTINUAA EL FILL 2 --- */
                wait(NULL); /* El Fill 2 espera a que termine el Net */
                printf("Soc el fill 2 (PID=%d, fill de %d)\n", getpid(), getppid());
                exit(0); 
            }
            
        } else { 
            /* --- CONTINUA EL PADRE ORIGINAL --- */
            waitpid(pid1, NULL, 0); 
            waitpid(pid2, NULL, 0); 
            
            printf("Soc el pare (PID=%d)\n", getpid()); 
        }
    }
    
    return 0; 
}
