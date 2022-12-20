/*Elabore um algoritmo que leia um número inteiro menor que 1000 e imprima a
quantidade de centenas, dezenas e unidades que o mesmo possui. Observar os termos no
plural a colocação do "e", da vírgula entre outros. Exemplo: 326 = 3 centenas, 2 dezenas
e 6 unidades. 120 = 1 centena e 2 dezenas.*/

# include <stdio.h>

int main(void)

{
    int num,centena,dezena,unidade;

    printf("Informe um numero menor que 1000: ");
    scanf("%d",&num);

    unidade = num%10;
    dezena = num%100/10;
    centena = num/100;

    printf("\nEste numero possui %d centenas, %d dezenas e %d unidades\n",centena,dezena,unidade);
}
