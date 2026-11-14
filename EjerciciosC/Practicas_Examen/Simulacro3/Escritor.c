#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fp;
    char mensaje[] = "Examen de PSP superado";

    mknod("MI_FIFO", S_IFIFO | 0660, 0);

    fp = open("MI_FIFO", O_WRONLY);

    if (fp == -1)
    {
        printf("Error al abrir el FIFO\n");
        exit(1);
    }

    printf("Mandando informacion al FIFO...\n");
    write(fp, mensaje, strlen(mensaje) + 1);

    close(fp);
    return 0;
}
