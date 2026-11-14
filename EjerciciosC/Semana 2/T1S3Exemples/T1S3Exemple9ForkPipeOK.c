#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/wait.h>
 
int main() 
{ 
	int fd[2]; 
	pid_t pid; 
	char saludoPadre[]="Bon dia fill\0"; 
	char buffer[sizeof(saludoPadre)+1]; 
 
	pipe(fd); // CREE EL PIPE
	pid=fork(); // CREE EL PROCÉS FILL
 
	switch(pid) {
		case 1: //ERROR 
			printf("No s'ha pogut crear el procés fill\n"); 
			exit(1);
			
		case 0: // PROCÉS FILL REP
			close(fd[1]); // TANCA EL DESCRIPTOR D'EIXIDA
			read(fd[0],buffer,sizeof(saludoPadre)+1); // LLIG
			printf("Missatge llegit: %s\n",buffer);
			break; 
		default: // PROCÉS PARE ENVIA
			close(fd[0]); // TANCA EL DESCRIPTOR D'ENTRADA
			printf("El pare escriu al PIPE...\n");
			write(fd[1],saludoPadre,strlen(saludoPadre)+1); // ESCRIU
			wait(NULL); //espero al proceso hijo 
			break; 
	} 
	return 0; 
} 
