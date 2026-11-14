/* Enunciado

👴 Abuelo: crea al proceso Padre y le envía la cadena "Hola desde el abuelo" mediante un primer pipe (fd1).
Después espera a que el Padre termine con waitpid() e imprime su propio PID al despedirse.

👨 Padre: crea al proceso Nieto, lee el mensaje del Abuelo desde fd1, lo muestra junto a su PID
 y lo reenvía al Nieto por un segundo pipe (fd2). Espera a que termine el Nieto y acaba con exit(0).

👶 Nieto: lee el mensaje desde fd2, lo muestra por pantalla junto a su PID (getpid())
 y el de su padre (getppid()), y termina con exit(0).*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t pid1, pid2;
    int status1, status2;

    int fd1[2], fd2[2];
    pipe(fd1); // Abuelo --- Padre
    pipe(fd2); // Padre ---- Nieto

    char salutacioAviPare[] = "Salutacions del teu pare.\0";
    char salutacioPareNet[] = "Salutacions del teu pare.\0";
    char salutacioNetPare[] = "Salutacions del teu fill.\0";
    char salutaciolPareAvi[] = "Salutacions del teu fill.\0";
    char buffersalutacioAviPare[strlen(salutacioAviPare) + 1];
    char buffersalutacioPareNet[strlen(salutacioPareNet) + 1];
    char buffersalutacioNetPare[strlen(salutacioNetPare) + 1];
    char buffersalutacioPareAvi[strlen(salutaciolPareAvi) + 1];

    pid1 = fork();
    switch (pid1)
    {

    case -1:
        printf("No se ha podido crear el proceso");
        break;
    case 0: // Padre
        pid2 = fork();
        switch (pid2)
        { /* Abuelo -- Padre
             Padre ---- Abuelo*/
        case -1:
            printf("No se ha podido crear el proceso");
            break;
        case 0: // Nieto
            close(fd1[0]);
            close(fd1[1]);
            close(fd2[1]);
           

            read(fd2[0], buffersalutacioNetPare, sizeof(buffersalutacioNetPare));
            printf("Soy el hijo mi ID es: %d y el ID de mi padre es %d \n", getpid(), getppid());
            printf("He recibido un mensaje de mi padre:  %s\n", buffersalutacioNetPare);
            exit(0);

            break;

        default: // Padre
            close(fd1[1]);
            close(fd2[0]);
            read(fd1[0], buffersalutacioAviPare, sizeof(buffersalutacioAviPare));
            printf("Soy el padre de ID %d y el ID del abuelo es: %d\n", getpid(), getppid());
            printf("He recibido un mensaje del abuelo: %s\n", buffersalutacioAviPare);
            write(fd2[1], salutacioPareNet, strlen(salutacioPareNet) + 1);
            waitpid(pid2, &status1, 0);
            exit(0);
            break;
        }
        break;

    default: // Abuelo
        close(fd1[0]);
        close(fd2[1]);
        close(fd2[0]);
        write(fd1[1], salutacioAviPare, strlen(salutacioAviPare) + 1);
        waitpid(pid1, &status1, 0);
        printf("Soy el abuelo mi ID: %d\n", getpid());

        break;
    }

    return 0;
}
