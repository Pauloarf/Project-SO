#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/wait.h>


struct ProgramInfo
{
    pid_t pid;
    struct timeval start_time;
    struct timeval end_time;
};

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "execute") == 0)
    {
        if (strcmp(argv[2], "-u") == 0)
        {
            if (argv[3] == NULL)
            {
                write(STDOUT_FILENO, "Not enough arguments! (program missing)\n", 41);
            }
            else
            {
                pid_t pid;
                int status;
                char buffer[4096];
                size_t read_bytes;
                int fd_client_server = open("fifo_cliente_servidor", O_WRONLY);
                int fd_server_client = open("fifo_servidor_cliente", O_RDONLY);
                if (fd_client_server == -1)
                {
                    perror("Error opening pipe fifo_cliente_servidor");
                    exit(1);
                }

                if (fd_server_client == -1)
                {
                    perror("Error opening pipe fifo_servidor_cliente");
                    exit(1);
                }
                struct ProgramInfo program_info;
                if((pid = fork()) == 0){
                    program_info.pid = getpid(); // pid do filho
                    gettimeofday(&program_info.start_time, NULL);
                    printf("Start Time: %ld seconds, %ld microseconds\n", program_info.start_time.tv_sec, program_info.start_time.tv_usec);
                    //write(fd_client_server,&program_info,sizeof(program_info));
                    //while((read_bytes = read(fd_server_client,buffer,4096))>0){
                        //write(STDOUT_FILENO,buffer,read_bytes);
                    //}
                    //close(fd_client_server);
                    //close(fd_server_client);
                    _exit(0);
                }
                else{
                    pid_t filho = wait(&status);
                }
                // fazer um fork, guardar PID do filho         done 
                // devolver o PID do filho ao user e ao servidor        
                // enviar o timestamp imediatamente antes do exec      done 
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
    unlink("fifo_cliente_servidor");
    unlink("fifo_servidor_cliente");
}