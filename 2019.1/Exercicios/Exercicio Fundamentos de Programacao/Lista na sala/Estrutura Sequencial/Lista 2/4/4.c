/*Escreva um algoritmo que dados a quantidade de litros de combust�vel utilizada, os
quil�metros percorridos por um autom�vel e o valor do litro de combust�vel, calcule o
gasto em reais por km.*/

# include <stdio.h>

int main(void)

{
    float litros, quilometros, valor;
    float gasto;

    printf("Informe a quantidade de litros utilizada: ");
    scanf("%f",&litros);
    printf("Informe a quantidade de quilometros percorridos: ");
    scanf("%f",&quilometros);
    printf("Informe o valor do litro de combustivel: ");
    scanf("%f",&valor);

    gasto = (litros*valor)/quilometros;

    printf("\nFoi gasto %.2f R$ por km\n",gasto);
}
