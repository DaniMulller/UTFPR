#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void imprime(int v[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d  ",v[i]);
  }
  printf("\n");
}

int troca(int *a,int *b){
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

void reseta_vetor(int v[],int v2[],int n){
  int i;
  for(i=0;i<n;i++){
    v2[i] = v[i];
  }
}

int separa(int v[],int primeiro,int ultimo){
  int pivo = v[ultimo];
  int esquerda = primeiro;
  int atual;
  for(atual=primeiro ; atual<ultimo ; atual++){
    if(v[atual]<=pivo){
      troca(&v[atual],&v[esquerda]);
      esquerda++;
    }
  }
  troca(&v[esquerda],&v[ultimo]);
  return esquerda;
}

void quick_sort(int v[],int p,int u){
  if(p<u){
    int j = separa(v,p,u);
    quick_sort(v,p,j-1);
    quick_sort(v,j+1,u);
  }
  return;
}

void merge(int v[],int p,int q,int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], R[n2];
  int i,j,k;
  for(i=0;i<n1;i++){
    L[i] = v[p+i];
  }
  for(j=0;j<n2;j++){
    R[j] = v[q+j+1];
  }
  i=0;
  j=0;
  k=p;
  while(i<n1 && j<n2){
    if(L[i] <= R[j]){
      v[k] = L[i];
      i++;
    }
    else{
      v[k] = R[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    v[k] = L[i];
    i++;
    k++;
  }
  while(j<n2){
    v[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int v[],int p,int r){
  int q;
  if(p<r){
    q = (p+r)/2;
    merge_sort(v,p,q);
    merge_sort(v,q+1,r);
    merge(v,p,q,r);
  }
  return;
}

void selection_sort(int v[],int n){
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
    troca(&v[min],&v[i]);
  }
}

void insertion_sort(int v[],int n){
  int i,j;
  int atual,aux;
  for(i=1;i<n;i++){
    aux = i;
    atual = v[i];
    j = i-1;
    while(j>=0 && v[j]>atual){
      troca(&v[j],&v[aux]);
      aux = j;
      j = j-1;
    }
  }
}

void bubble_sort(int v[],int n){
  int i,j;
  int flag=0;
  for(i=n-1;i>=1;i--){
      for(j=0;j<i;j++){
        if(v[j]>v[j+1]){
          troca(&v[j],&v[j+1]);
          flag=1;
        }
      }
      if(flag==0){
        return;
      }
  }
}

void gerar_vetor(int *v,int tam,int limite){
  srand(time(NULL));
  int i;
  for(i=0;i<tam;i++){
    v[i] = rand()%(limite+1);
  }
}

void inverte_vetor(int v[],int v2[],int n){
  int i,k=n-1;
  for(i=0;i<n;i++){
    v2[i] = v[k];
    k--;
  }
}
