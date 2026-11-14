/*Crea un programa donde el padre pida un número entero por teclado
y se lo envíe a un proceso hijo mediante un pipe.
l hijo leerá ese número, calculará su cuadrado, se lo devolverá al padre por un segundo pipe y terminará con exit(0).
El padre esperará al hijo con waitpid() y mostrará el resultado final junto con su propio PID. */

#include <stdlib.h>   
#include <sys/types.h> 
#include <unistd.h>   
#include <stdio.h>    
#include <sys/wait.h>  

int main()
{
    pid_t pid;          // Guardará el resultado de fork() (0 en hijo, PID del hijo en padre)
    int num, resultado; 

    // Declaramos 2 tuberías (pipes) porque cada una solo va en un sentido:
    // Posición [0] = extremo de LECTURA | Posición [1] = extremo de ESCRITURA
    int fd1[2]; // Tubo 1: Padre ---> Hijo (envía 'num')
    int fd2[2]; // Tubo 2: Hijo  ---> Padre (devuelve 'resultado')

    // IMPORTANTE: Creamos los pipes ANTES del fork() para que ambos procesos los compartan
    pipe(fd1);
    pipe(fd2);

    // Duplicamos el proceso: a partir de aquí existen Padre e Hijo ejecutando este código
    pid = fork();

    switch (pid)
    {
    case -1: 
        printf("Error al crear el proceso\n");
        exit(-1);

    case 0: // === CÓDIGO DEL HIJO ===
        // 1. Cerramos los extremos que el hijo NO va a usar
        close(fd1[1]); // El hijo NO escribe en fd1 (solo lee)
        close(fd2[0]); // El hijo NO lee de fd2 (solo escribe)

        // 2. Lee del tubo 1 y guarda el entero en la dirección de 'num' (&num)
        // Se queda bloqueado esperando hasta que el padre escriba algo.
        // sizeof(num) indica cuántos bytes leer (sin '&', tamaño del int).
        read(fd1[0], &num, sizeof(num));

        // 3. Procesa el dato recibido
        resultado = num * num;

        // 4. Envía 'resultado' al padre por el extremo de escritura del tubo 2
        write(fd2[1], &resultado, sizeof(resultado));

        // 5. Cierra los extremos que ya usó
        close(fd1[0]);
        close(fd2[1]);

        // 6. Termina el hijo para que NO siga ejecutando código del padre
        exit(0);

    default: // === CÓDIGO DEL PADRE (pid > 0, contiene el PID del hijo) ===
        // 1. Cerramos los extremos que el padre NO va a usar (espejo del hijo)
        close(fd1[0]); // El padre NO lee de fd1 (solo escribe)
        close(fd2[1]); // El padre NO escribe en fd2 (solo lee)

        // 2. Pide el dato por teclado
        printf("Dame un numero entero para calcular su cuadrado:\n");
        scanf("%d", &num);

        // 3. Envía 'num' al hijo por el extremo de escritura del tubo 1
        write(fd1[1], &num, sizeof(num));

        // 4. Lee la respuesta del hijo desde fd2 y la guarda en 'resultado'
        // Se queda esperando hasta que el hijo escriba en fd2.
        read(fd2[0], &resultado, sizeof(resultado));

        // 5. Espera a que el proceso hijo termine del todo (evita procesos zombis)
        waitpid(pid, NULL, 0);

        // 6. Muestra su propio PID con getpid() (NO usar 'pid', que es el del hijo)
        printf("PID del padre: %d | Resultado: %d\n", getpid(), resultado);

        // 7. Cierra los extremos que ya usó
        close(fd1[1]);
        close(fd2[0]);
        break;
    }

    return 0;
}