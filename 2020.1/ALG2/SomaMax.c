#include <stdio.h>

int somamax(int vet[],int ini,int tam){
  int meio;
  if(ini==tam){
    if(vet[ini]>0){
      return vet[ini];
    }
    else{
      return 0;
    }
  }
  else{
    meio=(ini+tam)/2;
    return somamax(vet,ini,meio)+somamax(vet,meio+1,tam);
  }
}

int main(void){
  int tam,i;
  scanf(" %d",&tam);
  int vet[tam];
  for(i=0;i<tam;i++){
    scanf(" %d",&vet[i]);
  }
  printf("%d\n",somamax(vet,0,tam-1));
  return 0;
}
