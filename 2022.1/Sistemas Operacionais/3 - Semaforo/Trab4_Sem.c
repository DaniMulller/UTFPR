#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N_THREADS 5
sem_t A,B,C,D,E;

//iniciar semaforo -> sem_init(sem_t *sem, int pshared, unsigned int value);
//desce um na fila -> int sem_wait(sem_t *sem);
//sobe na fila -> int sem_post(sem_t *sem);

void* proc_A(void* v){
    sem_wait(&A); 
    printf("Iniciando A\n");
    sleep((rand()%4)+1); //executa em um tempo aleatório de 1 a 5 seg
    printf("Finalizando A\n");
    sem_post(&C); //+1 na fila do semaforo C
}

void* proc_B(void* v){
    sem_wait(&B); 
    printf("Iniciando B\n");
    sleep((rand()%4)+1);
    printf("Finalizando B\n");
    sem_post(&C); //+1 na fila do semaforo C
}

void* proc_C(void* v){
    sem_wait(&C); //-1 na posição
    sem_wait(&C); //-1 na posição
    //C inicia na posição -2 da fila do semaforo e aguarda até que os posts sejam feitos e atinja o valor 0 da fila
    printf("Iniciando C\n");
    sleep((rand()%4)+1);
    printf("Finalizando C\n");
    //Processos D e E são iniciados quando C finaliza
    sem_post(&D); //+1 na fila do semaforo D
    sem_post(&E); //+1 na fila do semaforo E
}

void* proc_D(void* v){
    sem_wait(&D);
    printf("Iniciando D\n");
    sleep((rand()%4)+1);
    printf("Finalizando D\n");
    sem_post(&D);
}

void* proc_E(void* v){
    sem_wait(&E);
    printf("Iniciando E\n");
    sleep((rand()%4)+1);
    printf("Finalizando E\n");
    sem_post(&E);
}

void main(){
    pthread_t threads[N_THREADS];

    //Processos A e B iniciam rodando (1)
    sem_init(&A, 0, 1);  
    sem_init(&B, 0, 1);
    sem_init(&C, 0, 0);
    sem_init(&D, 0, 0);
    sem_init(&E, 0, 0);

    pthread_create(&threads[0], NULL, proc_A, NULL);
    pthread_create(&threads[1], NULL, proc_B, NULL);
    pthread_create(&threads[2], NULL, proc_C, NULL);
    pthread_create(&threads[3], NULL, proc_D, NULL);
    pthread_create(&threads[4], NULL, proc_E, NULL);
    
    for(int i = 0; i<5; i++){
        pthread_join(threads[i], NULL);
    }

    pthread_exit(0);
}