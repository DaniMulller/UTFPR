#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void){
  Fila *f = cria_fila_vazia();
  int num;
  int i;

  while(scanf("%d",&num) && num!=0){
    if(num==1){
      printf("Discarded cards: \n");
      printf("Remaining card: 1\n");
    }
    else{
      for(i=1;i<=num;i++){
        enfileira(f,i);
      }
      printf("Discarded cards: %d",desenfileira(f));
      for(i=num-1;i>=2;i--){
        enfileira(f,desenfileira(f));
        printf(", %d",desenfileira(f));
      }
      printf("\nRemaining card: %d\n",desenfileira(f));
    }
  }
  return 0;
}
