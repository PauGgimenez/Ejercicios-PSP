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
	char salutacio[]="Una salutació!!!";
	fp=open("FIFO1",1);

	if (fp==-1)
	{
		printf ("ERROR AL ABRIR ARCHIVO\n");
		exit(1);
	}

	printf ("Manant informació al FIFO...\n");
	write (fp,salutacio,strlen(salutacio));
	close(fp);
	return 0;
}
