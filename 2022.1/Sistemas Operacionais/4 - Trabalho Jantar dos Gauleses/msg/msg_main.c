#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <mqueue.h>
#include <time.h>
#include <math.h>

int main(){
	pid_t pid;

    pid = fork();
	if(pid > 0)
	{
		system("gcc msg_cozinheiro.c -o cozinheiro -lrt");
		execl("./cozinheiro","", NULL);
	} else if (pid == 0) {

		sleep(1);
		system("gcc msg_gaules.c -o gaules -lpthread -lrt ");
		execl("./gaules", "", NULL);
	} else {
		printf("Erro\n");
	}
	exit(0);
}
