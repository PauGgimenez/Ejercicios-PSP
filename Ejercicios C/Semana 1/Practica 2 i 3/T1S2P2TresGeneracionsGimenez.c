#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid_hijo, pid_nieto;
    int status;

    /* Abuelo crea hijo */
    pid_hijo  = fork();

    if (pid_hijo  == 0) 
    { 
        /* Codigio del hijo  */
        /* hijo  crea al nieto */
        pid_nieto = fork();

        if (pid_nieto == 0) 
        { 
            /* Codigo nieto */
            printf("Soc el net (%d, hijo de %d)\n", getpid(), getppid());
        } 
        else 
        { 
            
            waitpid(pid_nieto, &status, 0);
            printf("Soc el pare (%d, hijo de %d)\n", getpid(), getppid());
        }
    } 
    else 
    { 
        /* codigo abuelo: espera a que el hijo acabe  */
        waitpid(pid_hijo, &status, 0);
        printf("Soc l'avi (%d, hijode %d)\n", getpid(), getppid());
    }

    return 0;
}