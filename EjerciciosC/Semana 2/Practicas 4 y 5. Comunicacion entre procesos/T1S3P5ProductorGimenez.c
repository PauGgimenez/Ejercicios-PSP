#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int fp;
    char texto[100];

    
    fp = open("FIFO1", O_WRONLY);
    if (fp == -1) {
        printf("Error al abrir el FIFO\n");
        exit(1);
    }

    printf("Mandando información al FIFO...\n");

    while (1) {
        printf("Escribe mensaje (. para acabar): ");
        fgets(texto, sizeof(texto), stdin);

        // Si el usuario introduce únicamente '.', finaliza
        if (texto[0] == '.' && (texto[1] == '\n' || texto[1] == '\0')) {
            break;
        }

      
        write(fp, texto, strlen(texto));
    }

    close(fp);
    return 0;
}
