/* A Figura a seguir apresenta um exemplo fictício de árvore de decisão, tomando
atributos de clientes de alguma instituição financeira. Elabore o algoritmo que
implemente essa árvore de decisão. As entradas podem ser do tipo char, portanto,
considere a primeira letra de cada palavra como entrada.*/

# include <stdio.h>

int main(void)

{
    int saldo;
    char aplicacoes;

    printf("Informe o saldo da conta: ");
    scanf("%d",&saldo);

    if (saldo<0)
    {
        printf("\nTem aplicacoes?(s/n): ");
        fflush(stdin);
        scanf("%c",&aplicacoes);

        if (aplicacoes=='s')
        {
            printf("\nConta sem Risco!\n");
        }
        else if (aplicacoes=='n')
        {
            printf("\nConta em risco!\n");
        }
        else
        {
            printf("\nInforme apenas 's' ou 'n'!\n");
        }
    }
    else
    {
        printf("\nConta sem risco!\n");
    }
}
