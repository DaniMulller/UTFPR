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

//gcc sem_jantar_gauleses.c -o sem_jantar_gauleses -lpthread -lrt 

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define JAVALIS 20
#define N_COZINHEIROS 1
#define TIME 1

sem_t mutex, java, coz;

int javalis=JAVALIS, qtd=0;
char Nome[6] = "DANIEL";

int ColocaJavalis(){
    sem_wait(&coz); //espera ser acordado
    javalis = JAVALIS; //repoe os javalis
    sem_post(&java); //libera os gauleses

    return javalis;
}

int RetiraJavali(unsigned long int i){
    unsigned long int tid = (long)i;
    sem_wait(&mutex);

    if(javalis==0){
        sem_post(&coz); //acorda o cozinheiro
        printf("Gaules %c(%ld) acordou o cozinheiro\n", Nome[tid], tid);
        sem_wait(&java);
    }
    javalis--;

    sem_post(&mutex);
    return (javalis+1);
}

void* Gaules(void* i){
    unsigned long int tid = (long)i;
    while(1){
        qtd = RetiraJavali(tid);
        sem_wait(&mutex);
        printf("Gaules %c(%ld) comendo\tJAVALIS RESTANTES = %d\n", Nome[tid], tid, qtd-1);
        sem_post(&mutex);
    } 
}

void* Cozinheiro(void* i){
    unsigned long int tid = (long)i;
    while(1){
        ColocaJavalis();
        printf("Cozinheiro(%ld) colocou javali na mesa\tJAVALIS NA MESA = %d\n",tid,javalis);
    }
}

void main(void){
    int N_GAULESES = strlen(Nome);
    int i;
    int main_time=TIME;

    pthread_t gaules[N_GAULESES];
    pthread_t cozinheiro[N_COZINHEIROS];

    sem_init(&mutex, 0, 1);
    sem_init(&java, 0, 0);
    sem_init(&coz, 0, 0);
    
    for(i=0;i<N_COZINHEIROS;i++){
        pthread_create(&cozinheiro[i], NULL, Cozinheiro, (void*)(intptr_t)i);
    }
    for(i=0;i<N_GAULESES;i++){
        pthread_create(&gaules[i], NULL, Gaules, (void*)(intptr_t)i);
    }

    sleep(main_time);
}