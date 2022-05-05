/*Uma tribo gaulesa janta em comunidade a parr de uma mesa enorme com espaço para M
javalis grelhados. Quando um gaulês quer comer, serve-se e rera um javali da mesa
a menos que esta já esteja vazia. Nesse caso o gaulês acorda o cozinheiro e aguarda que
este reponha javalis na mesa. O código seguinte representa o código que implementa o
gaulês e o cozinheiro.

void Gaules(){
    while(true){
        Javali j = RetiraJavali();
        ComeJavali(j);
    }
}
void Cozinheiro(){
    while(true){
        ColocaJavalis(M);
    }
}

Implemente o código das funções RetiraJavali() e ColocaJavalis() incluindo
código de sincronização que previna deadlock e acorde o cozinheiro apenas quando a
mesa está vazia. Lembre que existem muitos gauleses e apenas um cozinheiro.
Idenfique regiões crícas na vida do gaules e do cozinheiro.
A solução deve aceitar um numero N de gauleses igual ao número de letras de seu
primeiro nome e 1 único cozinheiro.

Cada gaules terá um nome, dado pela letra correspondente
– Ex: dalcimar = 8 gauleses
Cada gaules deve imprimir na tela seu nome (dado pela letra) quando come e
quando acorda o cozinheiro.
– Ex: Gaules d(0) comendo
– Ex: Gaules a(1) acordou cozinheiro
A quandade javalis grelhados M deve ser igual ao número dos dois primeiros
dígitos de seu RA

A solução não deve ter nenhum comentário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define M 20

sem_t full, empty;
pthread_mutex_t mutex;

int mesa[M];
int counter;

pthread_t tid;

int ColocaJavalis(){
    if(counter < M){
        counter++;
        return 0;
    }
    else{
        return 1;
    }
}

int RetiraJavali(){
    if(counter > 0){
        counter--;
        return 0;
    }
    else{
        return 1;
    }
}

void* Gaules(void* i){
    unsigned long int tid = (long)i;
    int javali

    while(1){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        if(!RetiraJavali()){
            printf("Gaules %s(%d) comendo",Nome[tid],tid);
        }
        else{
            fprintf(stderr ,"Consumer report error condition\n");
        }

        pthread_mutex_unlock(&mutex);
        sem_wait(&empty);
    } 
}

void* Cozinheiro(){
    int javali;

    while(1){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        if(!ColocaJavalis()){
            printf("Cozinheiro colocou javali na mesa\n");
        }
        else{
            fprintf(stderr,"Producer report error condition\n");
        }

        pthread_mutex_unlock(&mutex);
        sem_wait(&full);
    }
}

void initializeData(){
    counter = 0;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, M);
}

void main(){
    int mainSleepTime = 10;
    char Nome[] = "daniel";
    int N = str_len(Nome);

    pthread_t threads[N];

    initializeData();
    
    for(i=0;i<N;i++){
        pthread_create(&threads[i], NULL, Gaules, (void*)(intptr_t)i);
    }
    pthread_create(&threads[0], NULL, Cozinheiro, NULL);

    sleep(mainSleepTime);
    printf("\nExit the program\n");
    pthread_exit(0);
}