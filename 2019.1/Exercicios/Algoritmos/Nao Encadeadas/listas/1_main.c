#include <stdlib.h>
#include <stdio.h>
#include "1.h"

int main(void){
  Lista *l = cria_lista_vazia();
  int i;

  adicionar_item(l,0,0);
  adicionar_item(l,1,1);
  adicionar_item(l,2,2);
  adicionar_item(l,3,3);
  adicionar_item(l,2,17);

  imprime_lista(l);

  return 0;
}
