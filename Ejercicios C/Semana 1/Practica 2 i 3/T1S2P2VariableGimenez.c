#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid_hijo;
    int num= 6;
    int status;

    pid_hijo = fork();

    if (pid_hijo == 0) 
    { 
        
        num = num - 5;
        printf("Soc el Fill. Valor variable és %d\n", num);
    } 
    else 
    { 
        num = num + 5;
        printf("Soc el Pare. Valor variable és %d\n", num);
        
    
    }

    return 0;
}