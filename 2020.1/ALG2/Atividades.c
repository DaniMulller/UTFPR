#include <stdio.h>

int main(void){
  int n,i,j,k=0,l=1;
  scanf(" %d",&n);
  int ini[n], fim[n], exer[n];
  for(i=0;i<n;i++){
      scanf(" %d %d",&ini[i],&fim[i]);
  }
  int aux=fim[0];
  exer[0]=0;
  for(j=1;j<n;j++){
    for(i=k;i<n;i++){
      if(ini[i]>aux){
        aux=fim[i];
        exer[j]=i;
        k=i+1;
        l++;
        i=n;
      }
    }
  }
  printf("Aulas alocadas:");
  for(i=0;i<l;i++){
    printf(" %d",exer[i]);
  }
  return 0;
}
