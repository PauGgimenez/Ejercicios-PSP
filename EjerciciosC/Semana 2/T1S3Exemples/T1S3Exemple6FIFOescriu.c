#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fp;
	char salutacio[]="Salutacions!!!";
	fp=open("FIFO1",1); // OBRE LA FIFO

	if (fp==-1) {
		printf ("Error a l'obrir l'arxiu\n");
		exit(1);
	}
	printf ("Enviant informació al FIFO...\n");
	write (fp,salutacio,strlen(salutacio));
	close(fp); // TANQUE LA FIFO
	return 0;
}