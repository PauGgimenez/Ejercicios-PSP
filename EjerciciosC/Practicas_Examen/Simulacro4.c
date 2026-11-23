/* Comunicación bidireccional con números (2 Pipes anónimos)
El proceso Padre pide un número entero por teclado y se lo envía al proceso Hijo mediante una primera tubería (fd1). 
El Hijo lee ese número, calcula su cuadrado y 
devuelve el resultado al Padre a través de una segunda tubería (fd2). 
Finalmente, el Padre muestra el resultado por pantalla, 
espera a que el Hijo termine con waitpid() y se despide.

Te sirve de plantilla para: enviar tipos numéricos (&variable, sizeof(int)) en lugar de cadenas 
y montar comunicación de ida y vuelta sin bloqueos.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd1[2]; // Padre -> Hijo
    int fd2[2]; // Hijo  -> Padre
    pid_t pid;
    int status;

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("Error al crear los pipes");
        exit(1);
    }

    pid = fork();
    switch (pid) {
        case -1:
            perror("Error en fork");
            exit(1);

        case 0: // HIJO
            close(fd1[1]); // No escribe en fd1
            close(fd2[0]); // No lee de fd2

            int numRecibido, resultado;
            read(fd1[0], &numRecibido, sizeof(int));
            printf("[HIJO %d] He recibido el numero: %d\n", getpid(), numRecibido);

            resultado = numRecibido * numRecibido;
            write(fd2[1], &resultado, sizeof(int));

            close(fd1[0]);
            close(fd2[1]);
            exit(0);

        default: // PADRE
            close(fd1[0]); // No lee de fd1
            close(fd2[1]); // No escribe en fd2

            int numEnviar, resRecibido;
            printf("[PADRE %d] Introduce un numero entero: ", getpid());
            scanf("%d", &numEnviar);

            write(fd1[1], &numEnviar, sizeof(int));
            read(fd2[0], &resRecibido, sizeof(int));

            printf("[PADRE %d] El hijo me ha devuelto el cuadrado: %d\n", getpid(), resRecibido);

            close(fd1[1]);
            close(fd2[0]);
            waitpid(pid, &status, 0);
            printf("[PADRE %d] Mi hijo ha terminado.\n", getpid());
            break;
    }

    return 0;
}