#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>


int main () {
	
	int fd[2];
	pid_t pid;
	char saludoHijo[]="Hola papi\0";
	char buffer[sizeof(saludoHijo)+1];

	pipe(fd); 
	pid=fork();

	switch(pid) {

		case -1: // error
			printf("Error\n");
			exit(1);

		case 0:  // Hijo envía
			
			close(fd[0]);
			printf("El fill envia al pare...\n");
			write(fd[1],saludoHijo,strlen(saludoHijo)+1);
		
			break;
		default: // Padre lee
			
			close(fd[1]);
			read(fd[0],buffer,sizeof(saludoHijo)+1);
			printf("El pare rep del fill: %s\n", buffer);
			
			wait(NULL);
			break;

			
			
			



	}

	return 0;	




}
