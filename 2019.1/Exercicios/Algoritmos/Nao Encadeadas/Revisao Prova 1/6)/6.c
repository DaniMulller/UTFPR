#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int x,i,codigo;
  float limite,mala,peso_total,peso;
  Lista *l = cria_lista_vazia();

  scanf("%f",&limite);
  scanf("%f",&mala);
  scanf("%d",&x);

  peso_total = mala;
  for(i=0;i<x;i++){
    scanf("%d %f",&codigo,&peso);
    peso_total = peso_total + peso;
    adiciona_item_fim_lista(l,codigo,peso);
  }

  while(peso_total >= limite){
      peso_total = peso_total - remove_maior(l);      
  }
  printf("\n");
  return 0;
}
