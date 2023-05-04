#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Argumentos insuficientes.\n");
        exit(1);
    }
    else{
        struct timeval tv;
        if(strcmp(argv[1],"execute") == 0){
            if(strcmp(argv[2],"-u") == 0){
                if(argv[3] == NULL){
                    printf("Running PID %d\n",getpid());
                    printf("(output do programa)\n");
                    gettimeofday(&tv,NULL);
                    
                }
                else{
                    //parse da string
                }
                    //parse da string
            }
            if(strcmp(argv[2],"-p") == 0){
                if(argv[3] == NULL){

                }
                else{
                    //parse da string
                }
            }
        }
    }
}