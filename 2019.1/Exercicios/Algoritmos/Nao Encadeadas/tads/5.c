#include <stdio.h>
#include "funcoes5.h"
#include "funcoes5.c"

int main(){
    Fracao *fracao1;
    Fracao *fracao2;

    fracao1 = criaFracao(8,3);
    fracao2 = criaFracao(1,5);

    imprimeFracao(fracao1);
    imprimeFracao(fracao2);
    printf("\nSoma: ");
    imprimeFracao(somaFracao(fracao1,fracao2));
    printf("Diminuir: ");
    imprimeFracao(diminuirFracao(fracao1,fracao2));
    printf("Multiplicacao: ");
    imprimeFracao(multiplicarFracao(fracao1,fracao2));
    printf("Divisao: ");
    imprimeFracao(dividirFracao(fracao1,fracao2));

    return 0;
}
