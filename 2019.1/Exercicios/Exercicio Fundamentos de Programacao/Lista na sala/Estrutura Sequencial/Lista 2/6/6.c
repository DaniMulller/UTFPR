/*Fa�a um programa que leia o pre�o de uma mercadoria com diferen�a de um m�s (ler
o valor da mercadoria no m�s passado e no m�s atual) e calcule a taxa de infla��o mensal
dessa mercadoria. A infla��o � o percentual da diferen�a de pre�os (atual menos o
anterior) sobre o pre�o anterior.*/

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
