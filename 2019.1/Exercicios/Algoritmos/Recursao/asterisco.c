#include <stdio.h>
#include <stdlib.h>

void asterisco(int n){
  if(n==1){
    printf("*");
    return;
  }
  else{
    printf("*");
    return asterisco(n-1);
  }
}

int main(void){
  int n;
  scanf("%d",&n);
  asterisco(n);
  printf("\n");
  return 0;
}
