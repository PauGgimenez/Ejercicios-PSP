#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#define MIDA_BUFFFER 80
#define TRUE 1


int main (void) {

	int fp;
	char buffer[MIDA_BUFFFER];
	int nbytes;

	mknod("FIFO1",S_IFOFO|0660,0);

fp = open("FIFO1", O_RDONLY);
    if (fp == -1) {
        printf("Error al abrir el FIFO\n");
        exit(1);
    }

    // Lee mientras haya datos transmitidos desde el productor
    while ((nbytes = read(fp, buffer, MIDA_BUFFER - 1)) > 0) {
        buffer[nbytes] = '\0';
        printf("Cadena rebuda: %s", buffer);
    }

    close(fp);

 
    unlink("FIFO1");

    return 0;
}
