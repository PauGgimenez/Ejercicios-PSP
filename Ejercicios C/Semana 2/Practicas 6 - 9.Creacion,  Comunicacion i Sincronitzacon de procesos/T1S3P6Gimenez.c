#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) { 
    pid_t pid1; 
    int status1; 
    
    pid1 = fork();

    if (pid1 == 0) {
        /* Codigo del hijo */
        for(int i = 0; i < 10; i++) {
            printf("Soc el fill\n");        
        }
    } else {
        /* Codigo del padre */
        for(int i = 0; i < 10; i++) {
            printf("Soc el pare\n");        
        }
        
        /* El padre espera y avisa */
        waitpid(pid1, &status1, 0);
        printf("El meu procés fill ja ha acabat\n");   
    }

    return 0;
}
