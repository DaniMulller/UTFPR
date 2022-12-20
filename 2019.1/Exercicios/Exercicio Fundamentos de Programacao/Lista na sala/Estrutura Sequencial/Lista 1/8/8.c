/*Escreva um algoritmo que converta um valor temperatura de graus Fahrenheit para
graus Celsius, cuja fórmula de conversão é: (graus Fahrenheit - 32) * (5/9).*/

# include <stdio.h>

int main(void)

{
    float fahr, celsius;

    printf("Informe a temperatura em Fahr: ");
    scanf("%f",&fahr);

    celsius = (fahr - 32) * ((float)5/9);

    printf("\n%.2f graus Fahr sao %.2f graus Celsius\n",fahr,celsius);
}
