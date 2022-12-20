#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5 //ordem 5

typedef struct Folha{
  int n_chaves;
  int chaves[N-1];
  struct Folha *filho[N];
  int e_folha;
}Folha;

Folha* cria_sub(){
  Folha *arvore = (Folha *) malloc (sizeof(Folha));

  if(arvore == NULL) {
    return NULL;
  }

  int i;
  arvore->e_folha = 1;
  arvore->n_chaves = 0;

  for (i = 0; i < N; i++)
    arvore->filho[i] = NULL;

  return arvore;
}

int BuscaBinaria(Folha* Folha, int chave){
  int b = 0, m, e = Folha->n_chaves - 1;

  while(b <= e){
    m = (b + e)/ 2;
    if(Folha->chaves[m] == chave) return m;
    if(Folha->chaves[m] >= chave) e = m - 1;
    if(Folha->chaves[m] < chave) b = m + 1;
  }
  return b;
}

Folha* divide_pagina(Folha* Folha, int p){

  int i;
  struct Folha *esquerda, *direita;
  esquerda = Folha->filho[p];
  direita = cria_sub();
  direita->e_folha = esquerda->e_folha;

  int aux = round((N-1) / 2);
  direita->n_chaves = aux;

  for (i = 0; i < aux; i++){
    direita->chaves[i] = esquerda->chaves[i + aux];
  }

  if (!esquerda->e_folha)
  {
    for (i = 0; i < aux; i++){
      direita->filho[i] = esquerda->filho[i + aux];
    }
  }

  esquerda->n_chaves = (N - 1) / 2;
  for(i = Folha->n_chaves; i > p; i--){
    Folha->filho[i + 1] = Folha->filho[i];
  }

  Folha->filho[p + 1] = direita;
  Folha->filho[p] = esquerda;
  Folha->chaves[p] = direita->chaves[0];
  Folha->n_chaves++;

  for (i = 0; i < aux; i++) {
    direita->chaves[i] = direita->chaves[i + 1];
  }
  direita->n_chaves--;

  return Folha;

}

Folha* insereNFP(Folha* Folha, int chave){

   int i, p = BuscaBinaria(Folha,chave);

   if(Folha->e_folha){

     for(i = Folha->n_chaves; i > p; i--){
       Folha->chaves[i] = Folha->chaves[i - 1];
     }
     Folha->chaves[i] = chave;
     Folha->n_chaves++;
   }
   else{
     if(Folha->filho[p]->n_chaves == N - 1){
       Folha = divide_pagina(Folha, p);
       if(chave > Folha->chaves[p]) p++;
     }

     Folha = insereNFP(Folha->filho[p], chave);
   }

   return Folha;

}

Folha* insert(Folha* Folha, int chave){
  struct Folha *aux;
  struct Folha *arvore;
  aux = Folha;


  if(aux->n_chaves == N - 1){
    arvore  = cria_sub();
    arvore->e_folha = 0;
    arvore->filho[0] = aux;
    Folha = divide_pagina(arvore, 0);
    arvore  = insereNFP(arvore,chave);
  }
  else  aux = insereNFP(aux,chave);

  return Folha;
}

int altura(Folha *arvore)
{
  if (arvore->filho[0] != NULL)
  {
    return 1 + altura(arvore->filho[0]);
  }

  return 0;
}

int mediaRaiz(Folha *tree){
  int soma = 0, i=0;

  if(tree != NULL)
    while(i < tree->n_chaves){
      soma = soma + tree->chaves[i];
      i++;
    }
  return soma/tree->n_chaves;
}

int num_paginas(Folha *raiz){
  int soma = 0, i;

  if(raiz != NULL){
    for (i = 0; i <= raiz->n_chaves; i++)
    {
      if (raiz->filho[i] != NULL)
        soma =  soma + 1 + num_paginas(raiz->filho[i]);
    }
  }

  return soma;
}


int main(void){

  int n, i, chave;
  scanf(" %d", &n);
  Folha *arvore = cria_sub();
  for(i = 0; i < n; i++){
    scanf(" %d",&chave);
    arvore = insert(arvore, chave);
  }

  printf("%d\n", mediaRaiz(arvore));

  return 0;
}
