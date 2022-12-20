#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i;
  int n;
  int aux;
  char operador;
  scanf("%d",&n);
  getchar();

  Pilha *p = cria_pilha_vazia(p);

  for(i=0;i<n;i++){
    aux=0;
    while(scanf("%c",&operador) && operador != '\n'){
      if(operador == '('){
        empilha(p,operador);
      }
      else if(operador == ')'){
        if(verifica_pilha_vazia(p)==0){
          desempilha(p);
        }
        else{
          aux++;
        }
      }
    }
    if(verifica_pilha_vazia(p) && aux==0){
      printf("correct\n");
    }
    else{
      printf("incorrect\n");
    }
    desempilha_tudo(p);
  }
  return 0;
}
