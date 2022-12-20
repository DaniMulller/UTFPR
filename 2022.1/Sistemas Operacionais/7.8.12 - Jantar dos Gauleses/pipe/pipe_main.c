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

int main(void){
    pid_t pid;

    pid = fork();
    if(pid > 0){
        system("gcc pipe_cozinheiro.c -o prod -lpthread");
        execl("./prod", "", NULL);
    } else if (pid == 0){
        system("gcc pipe_gaules.c -o cons -lpthread");
        execl("./cons", "", NULL);
    } else{
        printf("Erro\n");
    }
    exit(0);
}
