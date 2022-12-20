#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
  Lista *A = cria_lista_vazia();
  Lista *B = cria_lista_vazia();
  Lista *C = cria_lista_vazia();

  inserir_inicio(A,1);
  inserir_inicio(A,2);
  inserir_inicio(A,3);
  inserir_inicio(A,4);
  inserir_inicio(A,5);
  inserir_inicio(A,6);
  imprime_esq_dir(A);
  printf("\n");
  exercicio3(A,B,C);
  imprime_esq_dir(B);
  printf("\n");
  imprime_esq_dir(C);

  return 0;
}
