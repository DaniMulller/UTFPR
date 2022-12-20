#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct item {
    int codigo;
    float peso;
};
struct lista {
    Item item[MAXTAM];
    int ultimo;
};

Lista * cria_lista_vazia() {
    Lista *l = malloc(sizeof(Lista));
    l->ultimo = -1;
    return l;
}

// retorna 1 se a lista está vazia ou 0 se não está vazia
int verifica_lista_vazia(Lista *l) {
    return l->ultimo == -1;
}

// retorna 1 se a lista está cheia ou 0 se não está cheia
int verifica_lista_cheia(Lista *l) {
    return l->ultimo == MAXTAM - 1;
}

void adiciona_item_fim_lista(Lista *l, int codigo, float peso) {
    if(verifica_lista_cheia(l)){
        printf("Lista cheia!\n");
        return;
    }
    Item novo_item;
    novo_item.codigo = codigo;
    novo_item.peso = peso;
    l->ultimo++;
    l->item[l->ultimo] = novo_item;
}

void imprime_lista(Lista *l) {
    int tam = l->ultimo + 1;
    int i;
    for(i = 0; i < tam; i++)
        printf("%d %.3f ", l->item[i].codigo, l->item[i].peso);
}

void libera_lista(Lista *l) {
    free(l);
}

int busca_maior(Lista *l){
  int i,aux=0;
  Item maior;
  maior.peso = l->item[0].peso;
  for(i=1;i<l->ultimo;i++){
    if(l->item[i].peso > maior.peso){
      maior = l->item[i];
      aux=i;
    }
  }
  return aux;
}

float remove_maior(Lista *l){
  int i;
  float aux;
  i= busca_maior(l);
  aux = l->item[i].peso;
  printf("%d %.3f ",l->item[i].codigo,l->item[i].peso);
  for(i;i<l->ultimo;i++){
    l->item[i] = l->item[i+1];
  }
  l->ultimo--;
  return aux;
}
