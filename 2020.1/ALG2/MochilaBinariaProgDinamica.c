#include <stdio.h>
#include <stdlib.h>

int mochila_prog_dinamica(int capacidade, int peso[], int valor[], int numero){
  int custos[capacidade+1][numero+2];
  int valor_atual;
  int melhor1;
  int melhor2;
  int i, j;

  for(i = 0; i <= capacidade; i++){
    custos[i][0] = i;
    custos[i][1] = 0;
  }

  for(j = 2; j <= numero+1;j++){
    for(i = 0; i <= capacidade; i++){
      melhor1 = custos[i][j-1];
      if(i >= peso[j-2]){
        melhor2 = valor[j-2]+custos[i-peso[j-2]][j-1];
        if(melhor1 > melhor2){
          valor_atual = melhor1;
        }
        else{
          valor_atual = melhor2;
        }
      }
      else{
        valor_atual = melhor1;
      }
      custos[i][j] = valor_atual;
    }
  }
  return custos[capacidade][numero+1];
}

int main(void){
  int capacidade;
  int num_itens;

  scanf(" %d", &capacidade);
  scanf(" %d", &num_itens);

  int peso[num_itens];
  int valor[num_itens];

  int i = 0;

  while (i<num_itens)
  {
    scanf(" %d", &peso[i]);
    scanf(" %d", &valor[i]);
    i++;
  }

  printf("%d\n",mochila_prog_dinamica(capacidade, peso, valor, num_itens));

  return 0;
}
