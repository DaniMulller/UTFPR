/*Escreva um algoritmo que calcule o valor da conversão para dólares de um valor lido
em reais. Primeiro calcule o valor de saída esperado e utilize esses valores para verificar
se o seu algoritmo está correto.*/

# include <stdio.h>

int main(void)

{
    float dolar, real, cotacao;

    printf("Informe o valor em reais: ");
    scanf("%f",&real);
    printf("Informe a cotacao do dolar: ");
    scanf("%f",&cotacao);

    dolar = real/cotacao;

    printf("\nA quantidade final de dolares e de: %.2f $\n",dolar);
}
