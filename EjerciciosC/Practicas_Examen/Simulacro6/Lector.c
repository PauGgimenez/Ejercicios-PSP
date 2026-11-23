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
    int nbytes;

    mknod(FIFO_NAME, S_IFIFO | 0660, 0);

    printf("Esperando a que el escritor abra el FIFO...\n");
    fp = open(FIFO_NAME, O_RDONLY);
    if (fp == -1) {
        perror("Error al abrir el FIFO");
        exit(1);
    }

    while ((nbytes = read(fp, buffer, sizeof(buffer))) > 0) {
        if (strcmp(buffer, "FIN") == 0) {
            printf("Senal de salida recibida.\n");
            break;
        }
        printf("Mensaje recibido: %s\n", buffer);
    }

    close(fp);
    unlink(FIFO_NAME); // Borra el archivo FIFO del disco
    printf("Lector finalizado y FIFO eliminado.\n");
    return 0;
}