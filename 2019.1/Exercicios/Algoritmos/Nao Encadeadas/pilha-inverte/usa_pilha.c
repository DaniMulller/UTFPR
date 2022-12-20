#include "inverte.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
  char caractere;
  int i;
  int qtd;

  scanf("%d",&qtd);
  getchar();
  Pilha *p = cria_pilha_vazia(p);

  for(i=0;i<qtd;i++){
    while(scanf("\%c",&caractere) && caractere != '.'){
      if(caractere != ' '){
        empilha(p,caractere);
      }
      else{
        imprime_pilha(p);
        desempilha_tudo(p);
        printf(" ");
      }
    }
    getchar();
    imprime_pilha(p);
    printf("\n");
    desempilha_tudo(p);
  }
  libera_pilha(p);
  return 0;
}
