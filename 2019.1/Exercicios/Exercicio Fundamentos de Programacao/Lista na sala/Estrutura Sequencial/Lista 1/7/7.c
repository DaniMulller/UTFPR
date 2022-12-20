/*Escreva um algoritmo que converta um valor de temperatura de graus Celsius para
graus Fahrenheit, cuja fórmula de conversão é: (9 * graus Celsius + 160) /5.*/

# include <stdio.h>

int main(void)

{
        float celsius, fahr;

        printf("Informe a temperatura em graus Celsius: ");
        scanf("%f",&celsius);

        fahr = (9 * celsius + 160) / 5;

        printf("\n%.2f graus Celsius correspondem a %.2f graus Fahrenheit\n",celsius,fahr);

}
