#include <stdlib.h>
#include <stdio.h>

int mochila_backtracking(int capacidade, int peso[], int valor[], int pos){
  int aux1, aux2;

  if(pos<0){
    return 0;
  }
  else if(peso[pos]>capacidade){
    return mochila_backtracking(capacidade, peso, valor, pos-1);
  }
  else {
    aux1 = mochila_backtracking(capacidade, peso, valor, pos-1);
    aux2 = valor[pos] + mochila_backtracking(capacidade - peso[pos], peso, valor, pos-1);
    if(aux1>aux2){
      return aux1;
    }
    return aux2;
  }
}

int main(void){
  int capacidade;
  int num_itens;

  scanf("%d", &capacidade);
  scanf("%d", &num_itens);

  int peso[num_itens];
  int valor[num_itens];

  int i = 0;

  while (i<num_itens){
    scanf("%d", &peso[i]);
    scanf("%d", &valor[i]);
    i++;
  }

  printf("%d\n", mochila_backtracking(capacidade, peso, valor, num_itens - 1));

  return 0;
}
