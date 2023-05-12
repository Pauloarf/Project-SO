#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int make1 = mkfifo("fifo_cliente_servidor",0666);
    int make2 = mkfifo("fifo_servidor_cliente",0666);

    if (make1 == -1)
    {
        perror("Error opening pipe cliente_servidor");
    }

    if(make2 == -1)
    {
        perror("Error opening pipe servidor_cliente");
    }
    
    //int fd = open("fifo_cliente_servidor", O_RDONLY);
    //write
    // abrir as pipes

    // ler o que vem das pipes (PID e timestamp(inical))

    // guardamos o pid e o timestamp

    // ler as pipes novamente e ver (PID e timestamp(final)) remover o que esta na memoria.

    return 0;
}