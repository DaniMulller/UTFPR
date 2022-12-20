#include <stdlib.h>
#include <stdio.h>
#include "1.h"

struct item{
  int chave;
};

struct lista{
  Item item[MAXTAM];
  int ultimo;
};

Lista *cria_lista_vazia(){
  Lista *l = malloc(sizeof(Lista));
  l->ultimo = -1;
  return l;
}

void adiciona_item_fim_lista(Lista *l, int chave) {
    Item novo_item;

    if(verifica_lista_cheia(l)){
        printf("Erro: a lista está cheia.\n");
        return;
    }
    else {
        novo_item.chave = chave;
        l->ultimo++;
        l->item[l->ultimo] = novo_item;
    }
}

void adicionar_item(Lista *l,int indice,int chave){
  if(verifica_lista_cheia){
    return;
  }
  if(verifica_lista_vazia) {
    adiciona_item_fim_lista(l,chave);
  }
  else{
    Item novo_item;
    int i;
    novo_item.chave = chave;
    l->ultimo++;
    for(i=l->ultimo;i>indice;i--){
      l->item[i] = l->item[i-1];
    }
    l->item[indice] = novo_item;
  }
}

void imprime_lista(Lista *l) {
    int tam = l->ultimo + 1;
    int i;
    for(i = 0; i < tam; i++)
        printf("Chave: %d\n", l->item[i].chave);
}

int verifica_lista_vazia(Lista *l) {
    return l->ultimo == -1;
}

int verifica_lista_cheia(Lista *l) {
    return l->ultimo == MAXTAM - 1;
}
