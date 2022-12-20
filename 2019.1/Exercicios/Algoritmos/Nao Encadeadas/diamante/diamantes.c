#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n;
  int i;
  int aux;
  char caractere;

  Pilha *p = cria_pilha_vazia();
  scanf("%d", &n);
  getchar();

  for(i=0;i<n;i++){
    aux=0;
    while(scanf("%c", &caractere) && caractere != '\n'){
      if(caractere == '<'){
        empilha(p,caractere);
      }
      else if(verifica_pilha_vazia(p) != 1 && caractere == '>'){
        desempilha(p);
        aux++;
      }
    }
    printf("%d\n",aux);
    desempilha_tudo(p);
  }
  return 0;
}
