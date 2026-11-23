/*4. Jerarquía en cadena ida y vuelta: Abuelo → Padre → Nieto → Padre → Abuelo (4 Pipes)
Enunciado:
El Abuelo crea al proceso Padre y le envía un saludo por una tubería (fdAP). 
El Padre crea al Nieto, lee el mensaje del Abuelo, lo muestra junto a su PID 
y envía un saludo al Nieto (fdPN). El Nieto lee el mensaje del Padre, 
imprime su PID y el de su padre (getppid()), y responde al Padre por otra tubería (fdNP). 
El Padre recoge la respuesta del Nieto, responde al Abuelo (fdPA), 
espera a que termine el Nieto con waitpid() y finaliza. 
Por último, el Abuelo lee la respuesta del Padre, espera a que este termine con waitpid() y se despide.

Te sirve de plantilla para: la versión completa (ida y vuelta) del clásico de tres generaciones 
sin riesgo de bloqueos. Usar nombres descriptivos en los pipes (fdAP, fdPN, fdNP, fdPA) 
evita liarse al cerrar extremos.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status1, status2;

    int fdAP[2]; // Abuelo -> Padre
    int fdPN[2]; // Padre  -> Nieto
    int fdNP[2]; // Nieto  -> Padre
    int fdPA[2]; // Padre  -> Abuelo

    if (pipe(fdAP) == -1 || pipe(fdPN) == -1 || pipe(fdNP) == -1 || pipe(fdPA) == -1) {
        perror("Error al crear los pipes");
        exit(1);
    }

    char msgAP[] = "Saludos del abuelo al padre.";
    char msgPN[] = "Saludos del padre al nieto.";
    char msgNP[] = "Respuesta del nieto al padre.";
    char msgPA[] = "Respuesta del padre al abuelo.";
    char buffer[100];

    pid1 = fork();
    switch (pid1) {
        case -1:
            perror("Error al crear al Padre");
            exit(1);

        case 0: // --- PADRE ---
            pid2 = fork();
            switch (pid2) {
                case -1:
                    perror("Error al crear al Nieto");
                    exit(1);

                case 0: // --- NIETO ---
                    // Solo usa fdPN[0] (leer del padre) y fdNP[1] (escribir al padre)
                    close(fdAP[0]);
                    close(fdAP[1]);
                    close(fdPA[0]);
                    close(fdPA[1]);
                    close(fdPN[1]);
                    close(fdNP[0]);

                    // 1. Lee del Padre
                    read(fdPN[0], buffer, sizeof(buffer));
                    printf("[NIETO  | PID: %d | PPID: %d] Recibido: %s\n", getpid(), getppid(), buffer);

                    // 2. Responde al Padre
                    write(fdNP[1], msgNP, strlen(msgNP) + 1);

                    close(fdPN[0]);
                    close(fdNP[1]);
                    exit(0);

                default: // --- PADRE ---
                    // Usa fdAP[0] (leer abuelo), fdPN[1] (escribir nieto),
                    //     fdNP[0] (leer nieto),  fdPA[1] (escribir abuelo)
                    close(fdAP[1]);
                    close(fdPN[0]);
                    close(fdNP[1]);
                    close(fdPA[0]);

                    // 1. Lee del Abuelo
                    read(fdAP[0], buffer, sizeof(buffer));
                    printf("[PADRE  | PID: %d | PPID: %d] Recibido del abuelo: %s\n", getpid(), getppid(), buffer);

                    // 2. Envía al Nieto
                    write(fdPN[1], msgPN, strlen(msgPN) + 1);

                    // 3. Lee respuesta del Nieto
                    read(fdNP[0], buffer, sizeof(buffer));
                    printf("[PADRE  | PID: %d | PPID: %d] Recibido del nieto: %s\n", getpid(), getppid(), buffer);

                    // 4. Responde al Abuelo
                    write(fdPA[1], msgPA, strlen(msgPA) + 1);

                    close(fdAP[0]);
                    close(fdPN[1]);
                    close(fdNP[0]);
                    close(fdPA[1]);

                    waitpid(pid2, &status2, 0);
                    exit(0);
            }
            break;

        default: // --- ABUELO ---
            // Solo usa fdAP[1] (escribir al padre) y fdPA[0] (leer del padre)
            close(fdAP[0]);
            close(fdPN[0]);
            close(fdPN[1]);
            close(fdNP[0]);
            close(fdNP[1]);
            close(fdPA[1]);

            // 1. Envía al Padre
            write(fdAP[1], msgAP, strlen(msgAP) + 1);

            // 2. Lee respuesta del Padre
            read(fdPA[0], buffer, sizeof(buffer));
            printf("[ABUELO | PID: %d] Recibido del padre: %s\n", getpid(), buffer);

            close(fdAP[1]);
            close(fdPA[0]);

            waitpid(pid1, &status1, 0);
            printf("[ABUELO | PID: %d] Todos han terminado. Fin.\n", getpid());
            break;
    }

    return 0;
}