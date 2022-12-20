#include <stdio.h>
#include <stdlib.h>

void troca(int v[],int n,int x){
  int aux;
  aux = v[x];
  v[x] = v[n];
  v[n] = aux;
}

void imprime(int v[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d  ",v[i]);
  }
  printf("\n");
}

void selecao(int v[],int n){
  int i;
  int min;
  int j;
  for(i=0;i<n-1;i++){
    min = i;
    for(j=i+1;j<n;j++){
      if(v[j]<v[min]){
        min = j;
      }
    }
    troca(v,min,i);
  }
}

void insercao(int v[],int n){
  int i,j;
  int atual,aux;
  for(i=1;i<n;i++){
    aux = i;
    atual = v[i];
    j = i-1;
    while(j>=0 && v[j]>atual){
      troca(v,j,aux);
      aux = j;
      j = j-1;
    }
  }
}
