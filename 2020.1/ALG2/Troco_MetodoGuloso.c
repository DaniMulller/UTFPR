#include <stdio.h>

int main(void){
  int i;
  int troco;
  int n_moedas;
  int aux;
  int j;

  scanf("%d",&troco);
  scanf("%d",&n_moedas);

  int moedas[n_moedas];

  for(i=0;i<n_moedas;i++){
    scanf("%d",&moedas[i]);
  }

  while(troco!=0){
    aux=troco+1;
    for(i=0;i<n_moedas;i++){
      if(troco/moedas[i]<=aux&&troco/moedas[i]!=0){
        aux=troco/moedas[i];
        j=i;
      }
    }
    for(i=0;i<aux;i++){
      printf("%d\n",moedas[j]);
    }
    troco -= moedas[j]*aux;
  }
  return 0;
}
