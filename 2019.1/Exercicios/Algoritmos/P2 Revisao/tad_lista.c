#include <stdio.h>
#include <stdlib.h>
#include "tad_lista.h"

struct item{
  int chave;
};

struct celula{
  Celula *prox;
  Item item;
};

struct lista{
  Celula *primeira;
  Celula *ultima;
};

Lista *cria_lista_vazia(){
  Lista *l = malloc(sizeof(Lista));
  l->primeira = NULL;
  l->ultima = NULL;
}

int verifica_lista_vazia(Lista *l){
  return l->primeira == NULL;
}

void insere_inicio(Lista *l,int chave){
  Celula *nova = malloc(sizeof(Celula));
  nova->item.chave = chave;
  if(verifica_lista_vazia(l)){
    nova->prox = NULL;
    l->ultima = nova;
  }
  else{
    nova->prox = l->primeira;
  }
  l->primeira = nova;
}

void insere_final(Lista *l,int chave){
  Celula *nova = malloc(sizeof(Celula));
  nova->item.chave = chave;
  nova->prox = NULL;
  if(verifica_lista_vazia(l)){
    l->primeira = nova;
  }
  else{
    Celula *anterior = l->ultima;
    anterior->prox = nova;
  }
  l->ultima = nova;
}

Celula *busca_chave(Lista *l,int chave){
  if(verifica_lista_vazia(l) ){
    return NULL;
  }
  Celula *busca = l->primeira;
  while(busca->item.chave != chave && busca != NULL){
    busca = busca->prox;
  }
  return busca;
}

void insere_meio(Lista *l,int chave_anterior,int chave){
  if(verifica_lista_vazia(l)){
    insere_inicio(l,chave);
    return;
  }
  Celula *anterior = busca_chave(l,chave_anterior);
  if(anterior == NULL){
    printf("NAO TEM ESSA CHAVE\n");
  }
  else{
    Celula *nova = malloc(sizeof(Celula));
    nova->prox = anterior->prox;
    anterior->prox = nova;
    nova->item.chave = chave;
  }
}

void imprime(Lista *l){
  Celula *i = l->primeira;
  while(i != NULL){
    printf("%d\n",i->item.chave);
    i = i->prox;
  }
}
