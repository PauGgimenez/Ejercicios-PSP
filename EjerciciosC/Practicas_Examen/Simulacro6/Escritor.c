#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_NAME "CANAL_EXAMEN"

int main() {
    int fp;
    char buffer[100];

    mknod(FIFO_NAME, S_IFIFO | 0660, 0);

    printf("Esperando a que el lector abra el FIFO...\n");
    fp = open(FIFO_NAME, O_WRONLY);
    if (fp == -1) {
        perror("Error al abrir el FIFO");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Escribe un mensaje ('FIN' para salir): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Elimina el '\n' del Enter

        write(fp, buffer, sizeof(buffer));

        if (strcmp(buffer, "FIN") == 0) {
            break;
        }
    }

    close(fp);
    printf("Escritor finalizado.\n");
    return 0;
}