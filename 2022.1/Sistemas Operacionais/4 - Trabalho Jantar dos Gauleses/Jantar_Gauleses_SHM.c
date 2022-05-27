/*
Implemente o problema do Jantar de Gauleses usando shared memory:

Pode usar funções da shmem (system V) ou mmap (POSIX), escolha livre.
Recomendo padrão POSIX;

Deve, obrigatóriamente ter um executável, código fonte separado para o produtor
e outro para o consumidor;

Os programas podem ser lançados em background (&) ou ulizando fork/exec;
*/
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define ADDKEY 123
#define JAVALIS 20
#define N_COZINHEIROS 1

sem_t mutex, full, empty;

int counter=0;
char Nome[] = {'d','a','n','i','e','l'};

int ColocaJavalis(){
    if(counter < JAVALIS){
        counter++;
        return 1;
    }
    else{
        return 0;
    }
}

int RetiraJavali(){
    if(counter > 0){
        counter--;
        return 1;
    }
    else if(counter=0){
        return 0;
    }
}

void* Gaules(void* i){
    unsigned long int tid = (long)i;
    while(1){
        sem_wait(&full);
        sem_wait(&mutex);

        if(RetiraJavali()){
            printf("Gaules %c(%ld) comendo\n", Nome[tid], tid);
        }
        else{
            printf("Gaules %c(%ld) acordou o cozinheiro\n", Nome[tid], tid);
        }

        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    } 
}

void* Cozinheiro(void* i){
    unsigned long int tid = (long)i;
    while(1){
        sem_wait(&empty);
        sem_wait(&mutex);

        if(ColocaJavalis()){
            printf("Cozinheiro(%ld) colocou javali na mesa\n",tid);
        }

        sem_post(&mutex);
        sem_post(&full);
    }
}

int main(void){
    int mainSleepTime = 5;
    int N_GAULESES = strlen(Nome);
    int i;

    int shmid; // identificador da memoria comum
    int size = 1024;
    char *path="nome_de_arquivo_existente" ;
    char *mem;
    int flag = 0;

    //recuperação do shmid
    key_t key = ftok(path,ADDKEY);
    shmid = shmget(key, size,0);
    if (shmid == -1){
        perror("Erro no SHMget");
        exit(1); 
    }

    //acoplamento do processo a zona de memoria
    mem = shmat(shmid, 0, flag);
    if (mem == (char*)-1){
        perror("Acoplamento Impossivel");
        exit(1);
    }

    pthread_t gaules[N_GAULESES];
    pthread_t cozinheiro[N_COZINHEIROS];

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, JAVALIS);
    
    for (i=0;i<N_COZINHEIROS;i++)
    {
        pthread_create(&cozinheiro[i], NULL, Cozinheiro, NULL);
    }
    for(i=0;i<N_GAULESES;i++){
        pthread_create(&gaules[i], NULL, Gaules, (void*)(intptr_t)i);
    }

    sleep(mainSleepTime);
    printf("\nExiting the program...\n");
    return 0;
}