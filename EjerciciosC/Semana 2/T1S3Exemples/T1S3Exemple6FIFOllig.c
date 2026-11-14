#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define TAM_BUF 80
#define TRUE 1

int main(void)
{
	int fp;
	char buffer[TAM_BUF];
	int nbytes;

	mknod("FIFO1",S_IFIFO|0660,0); //CREA FIFO

	while(TRUE) { //OBRE, LLIG, TANCA FIFO ETERNAMENT
		fp=open("FIFO1",O_RDONLY); //OBRE FIFO
		nbytes=read(fp,buffer,TAM_BUF-1); //LLIG DE LA FIFO
		buffer[nbytes]='\0'; //CARÀCTER FINAL CADENA EN C
		printf("Cadena rebuda: %s \n",buffer);
		close(fp); //TANCA FIFO
	}
	return 0;
}