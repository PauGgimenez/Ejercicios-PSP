/*2. Árbol en abanico: 1 Padre y 2 Hijos independientes (2 Pipes)
Enunciado:
Un proceso Padre debe crear exactamente 2 procesos hijos (Hijo 1 e Hijo 2). 
El Padre enviará una tarea distinta a cada uno mediante dos tuberías 
independientes (fd1 para el Hijo 1 y fd2 para el Hijo 2). 
Cada hijo imprimirá el mensaje recibido junto a su propio PID y el de su padre (getppid()), 
y terminará con exit(0). El Padre debe esperar específicamente a que terminen ambos hijos con waitpid().

Te sirve de plantilla para: no caer en la trampa de hacer dos fork() seguidos 
(que crearían 4 procesos en vez de 3) y cerrar correctamente los 4 descriptores en cada rama.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];
    pid_t pid1, pid2;
    int status1, status2;

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("Error al crear los pipes");
        exit(1);
    }

    pid1 = fork();
    if (pid1 == -1) {
        perror("Error al crear Hijo 1");
        exit(1);
    }

    if (pid1 == 0) {
        // --- HIJO 1 ---
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);

        char buffer[100];
        read(fd1[0], buffer, sizeof(buffer));
        printf("[HIJO 1 | PID: %d | PPID: %d] Recibido: %s\n", getpid(), getppid(), buffer);

        close(fd1[0]);
        exit(0);
    } else {
        // --- PADRE (el segundo fork solo lo ejecuta el padre) ---
        pid2 = fork();
        if (pid2 == -1) {
            perror("Error al crear Hijo 2");
            exit(1);
        }

        if (pid2 == 0) {
            // --- HIJO 2 ---
            close(fd1[0]);
            close(fd1[1]);
            close(fd2[1]);

            char buffer[100];
            read(fd2[0], buffer, sizeof(buffer));
            printf("[HIJO 2 | PID: %d | PPID: %d] Recibido: %s\n", getpid(), getppid(), buffer);

            close(fd2[0]);
            exit(0);
        } else {
            // --- PADRE ---
            close(fd1[0]);
            close(fd2[0]);

            char msg1[] = "Tarea A para el Hijo 1";
            char msg2[] = "Tarea B para el Hijo 2";

            write(fd1[1], msg1, strlen(msg1) + 1);
            write(fd2[1], msg2, strlen(msg2) + 1);

            close(fd1[1]);
            close(fd2[1]);

            waitpid(pid1, &status1, 0);
            waitpid(pid2, &status2, 0);
            printf("[PADRE | PID: %d] Ambos hijos han terminado.\n", getpid());
        }
    }

    return 0;
}