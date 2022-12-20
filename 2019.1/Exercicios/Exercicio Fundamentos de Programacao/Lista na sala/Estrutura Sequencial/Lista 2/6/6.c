/*Faça um programa que leia o preço de uma mercadoria com diferença de um mês (ler
o valor da mercadoria no mês passado e no mês atual) e calcule a taxa de inflação mensal
dessa mercadoria. A inflação é o percentual da diferença de preços (atual menos o
anterior) sobre o preço anterior.*/

# include <stdio.h>

int main(void)

{
    float valor_atual, valor_passado;
    float inflacao;

    printf("Informe o valor atual do produto: ");
    scanf("%f",&valor_atual);
    printf("Informe o valor do mes passado do mesmo produto: ");
    scanf("%f",&valor_passado);

    inflacao = (valor_atual-valor_passado)/valor_passado*100;

    printf("\nA taxa de inflacao sobre esse produto foi de: %.2f %%\n",inflacao);

}
