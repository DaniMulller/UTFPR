#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void){
  int lin=5,col=5;
  Matriz *m = inicializa_matriz(lin,col);
  int i,k;
  float valor;
  int tam = 5/1;
  int pos;
  Hash *h = cria_tabela(tam);
  Item *item;

  for(i=0;i<5;i++){
    scanf("%d %d %f",&lin,&col,&valor);
    k = lin*31 + col;
    //pos = hashing_divisao(k,tam);
    item = cadastra_item(k);
    insere_tratamento_lista_encadeada(h,item,tam);
    adiciona_celula(m,lin,col,valor);
  }
  printf("\n");
  imprime_tabela(h,tam);

  libera_matriz(m);
  libera_tabela(h,tam);
  return 0;
}
