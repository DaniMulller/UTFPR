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

//main executa os dois codigos automaticamente via fork
int main(void){
    pid_t pid;

    pid = fork();
    if(pid > 0){
        system("gcc pipe_cozinheiro.c -o cozinheiro -lpthread"); //main executa o código do cozinheiro
        execl("./cozinheiro", "", NULL);
    }else if (pid == 0){
        system("gcc pipe_gaules.c -o gaules -lpthread"); //filho executa o código dos gauleses
        execl("./gaules", "", NULL);
    }else{
        printf("Erro\n");
    }
    exit(0);
}
