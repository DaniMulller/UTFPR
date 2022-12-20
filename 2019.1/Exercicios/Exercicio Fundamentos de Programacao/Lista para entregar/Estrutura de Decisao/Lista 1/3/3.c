/*Faca um algoritmo que leia o gênero, a idade e o tempo de
trabalho de uma pessoa e
determine se ela pode se aposentar. Assuma que homens se aposentam com 45 anos de
trabalho ou idade superior a 70 anos e mulheres de aposentam com 40 anos de trabalho
ou idade superior a 65 anos.*/

# include <stdio.h>

int main(void)

{
    char genero;

    printf("Informe o genero(h para homem ou m para mulher): ");
    scanf("%c",&genero);

    if (genero == 'h')
    {
        int idade, trabalho;

        printf("Informe a idade: ");
        scanf("%d",&idade);

        if (idade > 70)
        {
            printf("\nJa pode aposentar\n");
        }
        else
        {
            printf("Informe o tempo de trabalho em anos: ");
            scanf("%d",&trabalho);

            if (trabalho > 45)
            {
                printf("\nJa pode aposentar\n");
            }
            else
            {
                printf("\nNao pode aposentar\n");
            }
        }

    }
    else if (genero == 'm')
    {
        int idade, trabalho;

        printf("Informe a idade: ");
        scanf("%d",&idade);

        if (idade > 65)
        {
            printf("\nJa pode aposentar\n");
        }
        else
        {
            printf("Informe o tempo de trabalho em anos: ");
            scanf("%d",&trabalho);

            if (trabalho > 40)
            {
                printf("\nJa pode aposentar\n");
            }
            else
            {
                printf("\nNao pode aposentar\n");
            }
        }
    }
    else
    {
        printf("\nInforme o genero corretamente!\n");
    }
}
