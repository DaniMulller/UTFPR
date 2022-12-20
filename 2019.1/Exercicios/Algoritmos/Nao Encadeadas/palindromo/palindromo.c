#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <math.h>

int main(void){
  Pilha *p = cria_pilha_vazia();
  int i=0;
  int tam=0;
  int aux=0;
  char caractere;
  char string[100];

  while(scanf("%c",&caractere) && caractere != '\n'){
    if(caractere != ' ' && caractere != ',' && caractere != '-'){
      string[i] = caractere;
      empilha(p,caractere);
      i++;
      tam++;
    }
  }
  for(i=0;i<(int)(tam/2);i++){
    if(desempilha(p)!=string[i]){
      aux++;
      break;
    }
  }
  libera_pilha(p);
  if(aux==0){
    printf("sim\n");
  }
  else{
    printf("nao\n");
  }
  return 0;
}
