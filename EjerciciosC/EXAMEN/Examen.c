#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid1, pid2, pid3, pid4, pid5;

    pid1 = fork(); /* El Padre crea al hijo */

    if (pid1 == 0) {
        /* --- BLOQUE DEL HIJO --- */
        printf("Soy el Hijo (PID=%d, hijo de %d)\n", getpid(), getppid());
        pid2 = fork();
        /* --- NIETO 1 ---*/
        if (pid2 == 0) {
            printf("Soy el nieto 1 (PID=%d, hijo de %d)\n", getpid(), getppid());
        /* --- HIJO ---*/
        } else {
           
            pid3 = fork();
            /* --- NIETO 2 ---*/
            if (pid3 == 0) {
                printf("Soy el nieto 2 (PID=%d, hijo de %d)\n", getpid(), getppid());
                pid5 = fork();
                /* --- BISNIETO ---*/
                if (pid5 == 0) {
                    printf("Soy el Bisnieto 1 (PID=%d, hijo de %d)\n", getpid(), getppid());
                } else {
                    waitpid(pid5, NULL, 0);
                }
               /* --- HIJO ---*/
            } else {
               
                pid4 = fork();
                /* --- NIETO 3 ---*/
                if (pid4 == 0) {
                    printf("Soy el nieto 3 (PID=%d, hijo de %d)\n", getpid(), getppid());
                } else {
                    waitpid(pid2, NULL, 0);
                    waitpid(pid3, NULL, 0);
                    waitpid(pid4, NULL, 0);
                }
            }
        }

        exit(0);
    } else {
        /* --- BLOQUE DEL PADRE --- */
        waitpid(pid1, NULL, 0);
        printf("Soy Padre (PID=%d)\n", getpid());
    }
    return 0;
}
