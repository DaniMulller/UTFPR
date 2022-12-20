#include <stdio.h>

int main(void)

{
    int cookies;
    int carne_moida;
    float leite;
    float total;

    printf("(---------------Calculadora de gastos no mercado---------------)");
    printf ("\n\n\nInforme a quantidade de cookies comprados(para 1 caixa = 3R$): ");
    scanf ("%d",&cookies);
    printf ("Informe a quantidade de gramas de carne moida(para 100g = 5R$): ");
    scanf ("%d",&carne_moida);
    printf ("Informe a quantidade de litros de leite(para 2 litros = 3.5R$): ");
    scanf ("%f",&leite);


    total = cookies + carne_moida + leite;

    printf ("\nTotal gasto: %.2f R$\n ",total);
}

