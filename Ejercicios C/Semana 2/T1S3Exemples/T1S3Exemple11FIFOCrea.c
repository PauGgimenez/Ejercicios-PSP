#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#define MIDA_BUFFFER 80
#define TRUE 1

int main(void)
{
	int fp;
	char buffer[MIDA_BUFFFER];
	int nbytes;

	mknod("FIFO1",S_IFIFO|0660,0);

	while(TRUE)
	{
		fp=open("FIFO1",O_RDONLY);
		nbytes=read(fp,buffer,MIDA_BUFFFER-1);
		buffer[nbytes]='\0';
		printf("Cadena rebuda: %s \n",buffer);
		close(fp);
	}

	return 0;
}
