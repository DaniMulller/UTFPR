#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int main(void){
  int v[5] = {43,15,32,0,87};
  //printf("Selection Sort:\n");
  //selecao(v,5);
  //imprime(v,5);
  printf("\nInsertion Sort:\n");
  insercao(v,5);
  imprime(v,5);

}
