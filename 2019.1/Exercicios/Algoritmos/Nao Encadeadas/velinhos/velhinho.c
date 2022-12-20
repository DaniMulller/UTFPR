#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void){
  Fila *n = cria_fila_vazia();
  Fila *i = cria_fila_vazia();
  int senha;
  char caractere;
  while(scanf("%c",&caractere) && caractere != 'F'){
    if(caractere == 'N'){
      scanf("%d",&senha);
      enfileira(n,senha);
    }
    else if(caractere == 'I' || caractere == 'G'){
      scanf("%d",&senha);
      enfileira(i,senha);
    }
    else if(caractere == 'C'){
      if(verifica_fila_vazia(i)==0){
        printf("%d ",desenfileira(i));
      }
      else if(verifica_fila_vazia(n)==0){
        printf("%d ",desenfileira(n));
      }
    }
  }
  printf("\nRestaram %d pessoas na fila\n", tamanho_fila(n) + tamanho_fila(i));
  libera(f);
  return 0;
}
