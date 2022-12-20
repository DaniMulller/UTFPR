#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct item {
  int chave;
  // demais campos
};

struct fila {
  Item item[MAXTAM];
  int primeiro;
  int ultimo;
  int tamanho;
};

Fila * cria_fila_vazia() {
  Fila *f = malloc(sizeof(Fila));
  f->primeiro = 0;
  f->ultimo = 0;
  f->tamanho = 0;
  return f;
}

int verifica_fila_vazia(Fila *f) {
  return f->tamanho == 0;
}

int verifica_fila_cheia(Fila *f) {
  return f->tamanho == MAXTAM;
}

void enfileira(Fila* f, int chave) {
  Item novo_item;

  if(verifica_fila_cheia(f)) {
		printf("Erro: a fila está cheia.\n");
    return;
  }
	else {
    novo_item.chave = chave;
		f->item[f->ultimo] = novo_item;
		f->ultimo = (f->ultimo + 1) % MAXTAM;
		f->tamanho++;
	}
}

void imprime(Fila* f) {
	int i = f->primeiro;
	int t = f->tamanho;
	while (t > 0) {
		printf("Chave: %d\n", f->item[i].chave);
		t--;
		i = (i+1) % MAXTAM;
	}
}

int desenfileira(Fila* f) {
	int aux = f->item[f->primeiro].chave;
	f->primeiro = (f->primeiro + 1) % MAXTAM;
	f->tamanho--;
  return aux;
}

void libera(Fila *f) {
  free(f);
}

void princess(Fila *f){
  int t = f->tamanho;
  int i,j,aux;
  while(t > 0){
    if(t==1){
      printf("%d  -1\n",desenfileira(f));
    }
    else{
      j=0;
      aux = desenfileira(f);
      printf("%d  ",aux);
      i = f->primeiro;
      while(i <= f->ultimo){
        if(f->item[i].chave > aux){
          printf("%d\n",f->item[i].chave);
          i = f->ultimo + 1;
          j++;
        }
        else{
          i = (i+1)%MAXTAM;
        }
      }
      if(j==0){
        printf("-1\n");
      }
    }
    t--;
  }
}
