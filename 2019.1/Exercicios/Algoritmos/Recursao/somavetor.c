#include <stdio.h>
#include <stdlib.h>

int somavetor(int v[],int tam){
  if(tam==1){
    return v[0];
  }
  else{
    return v[tam-1] + somavetor(v,--tam);
  }

}

int main(void){
  int tam;
  scanf("%d",&tam);
  int v[tam];
  int i;
  for(i=0;i<tam;i++){
    scanf("%d",&v[i]);
  }
  printf("\nSoma: %d\n",somavetor(v,tam));
  return 0;
}
