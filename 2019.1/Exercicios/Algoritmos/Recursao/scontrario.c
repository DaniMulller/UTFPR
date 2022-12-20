#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime_contrario(char s[],int tam){
  int t = strlen(s);
  if(tam==0){
    return;
  }
  else{
    imprime_contrario(s,tam-1);
    printf("%c",s[t-tam]);
  }
}

int main(void){
  char s[50];
  char caractere;
  int i=0;
  while(scanf("%c",&caractere) && caractere != '\n'){
    s[i] = caractere;
    i++;
  }
  s[i] = '\0';
  imprime_contrario(s,i);
  printf("\n");
  return 0;
}
