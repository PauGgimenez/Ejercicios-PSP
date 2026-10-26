#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int num;
    pid_t pid1, pid2;
    
    printf("Dime el orden de los procesos (1 o 2): ");
    scanf("%d", &num);
    printf("Introduit:  %d\n", num);

    if (num == 1) {
        /* ORDEN 1: Primero P1, luego P2 */
        pid1 = fork();
        
        if (pid1 == 0) {
            printf("Soc procés 1 i acabe\n");
            exit(0);
        }
        /* El padre espera a que P1 termine por completo antes de continuar */
        waitpid(pid1, NULL, 0); 
        
        /* Ahora el padre crea a P2 */
        pid2 = fork();
        
        if (pid2 == 0) {
            printf("Soc procés 2 i acabe\n"); 
            exit(0);
        }
        /* El padre espera a que P2 termine */
        waitpid(pid2, NULL, 0); 

    } else if (num == 2) {
        /* ORDEN 2: Primero P2, luego P1 */
        pid2 = fork();
        
        if (pid2 == 0) {
            printf("Soc procés 2 i acabe\n");
            exit(0);
        }
        /* El padre espera a que P2 termine por completo antes de continuar */
        waitpid(pid2, NULL, 0); 
        
        /* Ahora el padre crea a P1 */
        pid1 = fork();
        
        if (pid1 == 0) {
            printf("Soc procés 1 i acabe\n");
            exit(0);
        }
        /* El padre espera a que P1 termine */
        waitpid(pid1, NULL, 0); 
        
    } else {
        printf("Opción no válida. Introduce 1 o 2.\n");
    }

    return 0;
}
