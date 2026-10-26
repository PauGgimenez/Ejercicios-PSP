// EXEMPLE: FILL ENVIA MISSATGE AL PARE PER PIPE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd[2]; //DECLARE VECTOR SENCERS
	char buffer[30];
	pid_t pid;
	
	pipe(fd); //CREE EL PIPE

	pid=fork(); //CREE PROCÉS FILL

	switch(pid) {
		case -1: //ERROR
			printf("No s'ha pogut crear el fill\n");
			exit(-1);

		case 0: //FILL ESCRIU MISSATGE PEL DESCRIPTOR 1
			printf("El fill escriu al PIPE...\n");
			write (fd[1], "Hola papi" ,10); 
			break;

		default: //PARE LLIG MISSATGE PEL DESCRIPTOR 0
			wait(NULL); //PARE ESPERA AL FILL ABANS DE LLEGIR
			printf("El pare llig del PIPE...\n");
			read (fd[0], buffer ,10);
			printf ("\tMissatge llegit:%s\n",buffer);
			break;
	} //FI SWITCH
	return 0;
}