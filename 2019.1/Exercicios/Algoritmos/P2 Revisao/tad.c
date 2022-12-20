#include <stdio.h>
#include <stdlib.h>
#include "tad_lista.h"

int main(void){
  Lista *l = cria_lista_vazia();
  insere_final(l,5);
  insere_inicio(l,1);
  insere_inicio(l,2);
  insere_inicio(l,3);
  insere_inicio(l,4);
  insere_meio(l,4,8);

  imprime(l);

  return 0;
}
