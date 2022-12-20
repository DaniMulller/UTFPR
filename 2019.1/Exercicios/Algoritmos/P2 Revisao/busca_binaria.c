#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int v[],int p,int r,int num){
  int q = (p+r)/2;
  if(v[q]==num){
    return q;
  }
  else{
    if(v[q]<num){
      return busca_binaria(v,q+1,r,num);
    }
    else{
      return busca_binaria(v,p,q-1,num);
    }
  }
  return -1;
}

int main(void){
  int v[10] = {1,2,3,4,5,6,7,8,9,10};
  int n;
  scanf("%d",&n);
  printf("%d\n",busca_binaria(v,0,4,n));

  return 0;
}
