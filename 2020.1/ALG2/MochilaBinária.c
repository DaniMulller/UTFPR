#include <stdio.h>

int valor_max(int capacidade,int n,int peso[],int valor[]){
  int i,soma=peso[0];

  for(i=1;i<n;i++){
    if(soma<capacidade){
      soma+=peso[i];
    }
  }
}

int main(void){
  int capacidade;
  int n;
  int i;
  scanf(" %d",&capacidade);
  scanf(" %d",&n);
  int peso[n],valor[n];
  for(i=0;i<n;i++){
    scanf(" %d %d",&peso[i],&valor[i]);
  }
  printf("\n%d",valor_max(capacidade,n,peso[],valor[]));

  return 0;
}
