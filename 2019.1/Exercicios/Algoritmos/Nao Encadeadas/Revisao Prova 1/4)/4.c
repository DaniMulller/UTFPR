#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void){
  int n,i,num;
  Fila *f = cria_fila_vazia();
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num);
    enfileira(f,num);
  }
  princess(f);

  return 0;
}
