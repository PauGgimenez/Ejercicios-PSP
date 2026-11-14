// EXEMPLE: FILL ENVIA MISSATGE AL PARE PER PIPE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char saludoPadre[]="Bon dia, fill.\0";
	char buffer[25];

	int fd[2]; //DECLARE VECTOR SENCERS
	pipe(fd); //CREE EL PIPE

	pid_t pid;	
	pid=fork(); //CREE PROCÉS FILL

	switch(pid) {
		case -1: //ERROR
			printf("No s'ha pogut crear el fill\n");
			exit(-1);

		case 0: //FILL LLIG MISSATGE PEL DESCRIPTOR 0
			close (fd[1]); //TANCA EL DESCRIPTOR D'EIXIDA
			printf ("El fill llig del PIPE...\n", buffer);
			read (fd[0],buffer, sizeof(buffer));
			printf ("\tMissatge llegit:%s\n", buffer);
			break;
		default: //PARE ESCRIU MISSATGE PEL DESCRIPTOR 1
			close (fd[0]); //TANCA EL DESCRIPTOR D'ENTRADA
			printf ("\El pare escriu al PIPE%s\n",buffer);
			write (fd[1],saludoPadre, strlen(saludoPadre));
			wait(NULL); //PARE ESPERA AL FILL
			break;
	}
	return 0;
}

	




