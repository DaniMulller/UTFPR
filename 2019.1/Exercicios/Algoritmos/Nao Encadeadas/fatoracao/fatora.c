#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
  int n,i,j;
  int num;
  Pilha *p = cria_pilha_vazia();

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num);
    j=2;
    while(num!=1){
      if(num%j==0){
        empilha(p,j);
        num = num/j;
      }
      else{
        j++;
      }
    }
    imprime_pilha(p);
    desempilha_tudo(p);
    printf("\n");
  }
  libera_pilha(p);
  return 0;
}
