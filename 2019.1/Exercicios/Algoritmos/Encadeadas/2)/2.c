#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
  Lista *A = cria_lista_vazia();
  Lista *B = cria_lista_vazia();

  inserir_inicio(A,1);
  inserir_inicio(A,2);
  inserir_inicio(A,3);
  imprime_esq_dir(A);
  printf("\n");
  inserir_inicio(B,1);
  inserir_inicio(B,2);
  inserir_inicio(B,3);
  imprime_esq_dir(B);
  printf("\n");
  liga_lista(A,B);
  imprime_esq_dir(A);
  return 0;
}
