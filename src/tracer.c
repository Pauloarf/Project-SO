#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

struct timeval tv;

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "execute") == 0)
    {
        if (strcmp(argv[2], "-u") == 0)
        {
            if (argv[3] == NULL)
            {
                write(STDOUT_FILENO, "Not enough arguments! (program missing)", 41);
            }
            else
            {
                // fazer um fork, guardar PID do filho
                // devolver o PID do filho ao user e ao servidor
                // enviar o timestamp imediatamente antes do exec
                // executar o programa no filho
                // esperar que o program filho termine (wait)
                // após terminar o programa, enviar ao servidor PID e timestamp apos o término
                // notificar tb o utilizador do tempo de execução
            }
        }
        if (strcmp(argv[2], "-p") == 0)
        {
            if (argv[3] == NULL)
            {
                //funcionalidades avançadas
            }
            else
            {
                // funcionalidades avançadas
            }
        }
    }
    if (strcmp(argv[1], "status") == 0)
    {
        // Listar um por linha os programas que estão a ser executados
        // cada programa deve conter PID, nome, tempo de execução até ao momento
        // aceder ao servidor e confirmar quais programas é que ainda não terminaram.
    }
    /*
    if(argc < 3){
        printf("Argumentos insuficientes.\n");
        exit(1);
    }*/
}