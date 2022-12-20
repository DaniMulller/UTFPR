#include <stdio.h>

int potencia(int a,int b){
  if(b==0){
    return 1;
  }
  else{
    return a*potencia(a,b-1);
  }
}

int main(void){
  int a,b;
  scanf(" %d %d",&a,&b);
  printf("%d\n",potencia(a,b));
  return 0;
}
