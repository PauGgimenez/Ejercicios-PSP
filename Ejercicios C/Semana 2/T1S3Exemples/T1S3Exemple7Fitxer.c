#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void main(void)
{
	char salutacio[] = "Salutacions!!!";
	char buffer[2]="";
	int fd, bytesllegits;

	// PRIMERA PART: ESCRIC MISSATGE EN EL FITXER
	fd = open("text.txt",O_CREAT|O_WRONLY,0644); // OBRE EL FITXER PER ESCRIPTURA
	if (fd==-1) {
		printf ("Error a l'obrir l'arxiu\n");
		exit(1);
	}
	printf("Escric la salutació que vaig a guardar en fitxer: %s...\n",salutacio);
	write(fd,salutacio,strlen(salutacio));
	close(fd); // TANQUE EL FITXER

	// SEGONA PART: LLIG MISSATGE DEL FITXER
	fd = open("text.txt",O_RDONLY|O_CREAT); // OBRE EL FITXER PER LECTURA
	printf("Contingut del fitxer\n");
	// LLIG DE BYTE EN BYTE I ELS GUARDE EN buffer
	bytesllegits = read(fd,buffer,1);
	while (bytesllegits!=0) {
		printf("%s",buffer); // ESCRIC BYTE LLEGIT
		bytesllegits = read(fd,buffer,1); // LLIG UN ALTRE BYTE
	}
	close(fd); // TANQUE EL FITXER
	printf("\n");
}
