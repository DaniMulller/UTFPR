#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<pthread.h>
#include<time.h>

#define N_THREADS 32
#define BILHAO 1000000000

//N_TREADS	//SERIE 1	//SERIE 2
//1		14.14s		21.68s
//2		6.94s		10.70s
//4		3.70s		5.43s
//8		1.90s		2.91s
//16		1.60s		2.69s
//32		1.53s		2.56s		


double parc[8*N_THREADS]; //8x para cada thread ter uma memória cache
double pi = 0;

void *funcao1(void* i){
  unsigned long int tid = (long)i;

  unsigned long int termos = BILHAO / N_THREADS;
  unsigned long int inicio = tid * termos;
  unsigned long int fim = tid * termos + termos;

	for(int i = inicio; i < fim; i++){
        parc[8*tid] += 4*((pow(-1,i)/ (2*i+1))); //Serie 1 da lista
  }
}

void *funcao2(void* i){
  unsigned long int tid = (long)i;

  unsigned long int termos = BILHAO / N_THREADS;
  unsigned long int inicio = tid * termos;
  unsigned long int fim = tid * termos + termos;

	for(int i = inicio; i < fim; i++){
      parc[8*tid] += sqrt(12)*(pow(-1,i))/((2*i+1)*pow(3,i)); //Serie x da lista
  }
}


int main(void){

  pthread_t threads[N_THREADS];
  struct timespec t1, t2;
  int i;

  pi = 0;
  for(i = 0; i < N_THREADS; i++){ 
    parc[8*i] = 0; //inicializar as parciais
  }

  clock_gettime(CLOCK_MONOTONIC, &t1);	
  for(i = 0; i < N_THREADS; i++){
      pthread_create(&threads[i], NULL, funcao1, (void*)(intptr_t)i);
  }
  for(i = 0; i < N_THREADS; i ++){
      pthread_join(threads[i], NULL);
      pi += parc[8*i]; 
  }
  clock_gettime(CLOCK_MONOTONIC, &t2);
  double temp = (double)(t2.tv_sec - t1.tv_sec) + (t2.tv_nsec - t1.tv_nsec)/1E9;

  printf("Serie 1\n");
  printf("N threads: %d\nValor de pi: %.50lf\nTempo: %lfs\n", N_THREADS, (double)pi, temp);

  //---------------------------FUNCAO 2----------------------------------------------------------------------//
  pi = 0; //resetar o valor de pi
  for(i = 0; i < N_THREADS; i++){  //reinicializar as parciais
    parc[8*i] = 0;
  }

  clock_gettime(CLOCK_MONOTONIC, &t1);	
  for(i = 0; i < N_THREADS; i++){
      pthread_create(&threads[i], NULL, funcao2, (void*)(intptr_t)i);
  }
  for(i = 0; i < N_THREADS; i ++){
      pthread_join(threads[i], NULL);
      pi += parc[8*i]; 
  }
  clock_gettime(CLOCK_MONOTONIC, &t2);
  temp = (double)(t2.tv_sec - t1.tv_sec) + (t2.tv_nsec - t1.tv_nsec)/1E9;

  printf("Serie 2\n");
  printf("N threads: %d\nValor de pi: %.50lf\nTempo: %lfs\n", N_THREADS, (double)pi, temp);
  
  pthread_exit(0);
}
