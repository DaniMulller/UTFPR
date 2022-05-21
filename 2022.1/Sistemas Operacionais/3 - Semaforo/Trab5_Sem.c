/*Considere o seguinte o grafo de precedência:

                  |-> procB x=x*2 -> procC x=x+1   | -> procD h=y+x   ->|
procA x=1 y=1 z=2 |----------------> procE y=y+2 ->|                    |->procF u=h+j/3    
                  |----------------> procG z=z/2   | -> procH j=z+y-4 ->|

Que será executado por três processos, conforme código abaixo:
P1: begin A; E; F; end;
P2: begin B; C; D; end;
P3: begin G; H; end;
Adicione semáforos a este programa, e as respectivas chamadas às suas operações, 
de modo que a precedência definida acima seja alcançada.
Obdeça as equações obtendo valor final de u dado as entradas de x, y e z
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N_THREADS 3
sem_t A,B,C,D,E,F,G,H;
int x=0,y=0,z=0,j=0,h=0,u=0;

//Thread 1: A->E->F->end
void* proc_1(void* v){
    sem_wait(&A); 
    printf("Iniciando A\n");
    x=1;
    y=1;
    z=2;
    //sleep((rand()%4)+1); //executa em um tempo aleatório de 1 a 5 seg
    printf("Finalizando A\n");
    sem_post(&B);
    sem_post(&E);
    sem_post(&G);

    sem_wait(&E);
    printf("Iniciando E\n");
    y=y+2;
    //sleep((rand()%4)+1);
    printf("Finalizando E\n");
    sem_post(&D);
    sem_post(&H);

    sem_wait(&F);
    sem_wait(&F);
    printf("Iniciando F\n");
    u=h+j/3;
    //sleep((rand()%4)+1);
    printf("Finalizando F\n");
    sem_post(&F);
}

//Thread 2: B->C->D->end
void* proc_2(void* v){
    sem_wait(&B); 
    printf("Iniciando B\n");
    x=x*2;
    //sleep((rand()%4)+1);
    printf("Finalizando B\n");
    sem_post(&C);

    sem_wait(&C);
    printf("Iniciando C\n");
    x=x+1;
    //sleep((rand()%4)+1);
    printf("Finalizando C\n");
    sem_post(&D);

    sem_wait(&D);
    sem_wait(&D);
    printf("Iniciando D\n");
    h=y+x;
    //sleep((rand()%4)+1);
    printf("Finalizando D\n");
    sem_post(&F);
}

//Thread 3: G->H->end
void* proc_3(void* v){
    sem_wait(&G);
    printf("Iniciando G\n");
    z=z/2;
    //sleep((rand()%4)+1);
    printf("Finalizando G\n");
    sem_post(&H);

    sem_wait(&H);
    sem_wait(&H);
    printf("Iniciando H\n");
    j=z+y-4;
    //sleep((rand()%4)+1);
    printf("Finalizando H\n");
    sem_post(&F);
}

void main(){
    pthread_t threads[N_THREADS];

    sem_init(&A, 0, 1);  
    sem_init(&B, 0, 0);
    sem_init(&C, 0, 0);
    sem_init(&D, 0, 0);
    sem_init(&E, 0, 0);
    sem_init(&F, 0, 0);
    sem_init(&G, 0, 0);
    sem_init(&H, 0, 0);

    //Criando uma Thread para cada processo
    pthread_create(&threads[0], NULL, proc_1, NULL); 
    pthread_create(&threads[1], NULL, proc_2, NULL); 
    pthread_create(&threads[2], NULL, proc_3, NULL); 
    
    for(int i = 0; i<N_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("\nu = %d\n",u);

    pthread_exit(0);
}