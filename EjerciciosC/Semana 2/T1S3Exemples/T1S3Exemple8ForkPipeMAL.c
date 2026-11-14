#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <sys/wait.h>
 
int main() 
{
    int fd[2]; 
    char buffer[10]; 
    pid_t pid; 
   
    pipe(fd); // CREE EL PIPE
    pid=fork(); // CREE EL PROCÉS FILL
 
    switch(pid) 
    {
        case 1: //ERROR 
			printf("No s'ha pogut crear el procés fill\n"); 
			exit(1);
 
        case 0: // PROCÉS FILL ENVIA
			printf("El fill escriu al PIPE...\n");
			write(fd[1],"Hola papi\0",10);
			break; 
 
        default: // PROCÉS PARE REP
			wait(NULL); // PARE ESPERA A QUE ACABE EL FILL
			printf("El pare llig del PIPE...\n");
			read(fd[0],buffer,10);
			printf("Missatge llegit: %s\n",buffer);
			break; 
    } // FI SWITCH
}
