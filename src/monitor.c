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
    if (mkfifo("fifo_cliente_servidor", O_RONLY) == -1)
    {
        printf("Error opening pipe cliente_servidor");
    };

    if(mkfifo("fifo_servidor_cliente", O_WRONLY) == -1)
    {
        printf("Error opening pipe servidor_cliente");
    };
    

    // abrir as pipes

    // ler o que vem das pipes (PID e timestamp(inical))

    // guardamos o pid e o timestamp

    // ler as pipes novamente e ver (PID e timestamp(final)) remover o que esta na memoria.

    return 0;
}