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
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

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