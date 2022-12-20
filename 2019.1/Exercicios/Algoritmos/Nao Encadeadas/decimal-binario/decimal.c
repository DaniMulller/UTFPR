#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
  int n;
  int num;
  int i;
  Pilha *p = cria_pilha_vazia();

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&num);
    while(num>=1){
      empilha(p,num%2);
      num = num/2;
    }
    imprime_pilha(p);
    desempilha_tudo(p);
    printf("\n");
  }
  return 0;
}
