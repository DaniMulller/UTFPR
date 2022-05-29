#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

#define QTD_JAVALIS 20

typedef struct _P1{
    int javalis;
}P1;

typedef struct _P2{
    char pipe;
}P2;

//declarando as structs
P1 j;
P2 p;
int fd[2];

void main(){
    mkfifo("retirar", 0666);
    mkfifo("servir", 0666);
    fd[0] = open("retirar", O_RDONLY); //lê
    fd[1] = open("servir", O_WRONLY); //escreve
    j.javalis = QTD_JAVALIS;
    printf("Cozinheiro repoe %d javalis\n", j.javalis);

    write(fd[1], &j, sizeof(P1));

    while(1){
        read(fd[0], &p, sizeof(P2));
        if(p.pipe == 'E'){
            j.javalis = QTD_JAVALIS;
            printf("Cozinheiro repoe %d javalis\n", j.javalis);
            write(fd[1], &j, sizeof(P1)); //+1 javali
            read(fd[0], &p, sizeof(P2)); //-1 espaço buffer
        }
        if(p.pipe == 'B'){
            j.javalis--;
        }
        write(fd[1], &j, sizeof(P1));
    }
}
