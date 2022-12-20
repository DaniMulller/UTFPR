/* Implemente o operador OU exclusivo.
Por exemplo: Ler a informa��o se uma pessoa recebe vale alimenta��o (S/N) e se recebe
auxilio transporte (S/N). Informar que a pessoa est� regularizada se ela recebe um e
somente um desses benef�cios.*/

# include <stdio.h>

int main(void)

{
    char alimentacao,transporte;
    printf("Informe se recebe vale alimentacao(s/n): ");
    scanf("%c",&alimentacao);

    printf("\nInforme se recebe auxilio transporte(s/n): ");
    fflush(stdin);
    scanf("%c",&transporte);

    if ((alimentacao=='s' && transporte=='n') ^ (alimentacao=='n' && transporte=='s'))
    {
        printf("\nEsta regularizada!\n");
    }
    else
    {
        printf("\nNao esta regularizada!\n");
    }
}
