#include <stdio.h>
#include <stdlib.h>

void binario(int n){
  if(n==1){
    printf("1");
    return;
  }
  else{
    return binario(n/2);
    printf("%d\n",n%2);
  }
}

int main(void){
  int n;
  scanf("%d",&n);
  binario(n);
  printf("\n");
  return 0;
}
