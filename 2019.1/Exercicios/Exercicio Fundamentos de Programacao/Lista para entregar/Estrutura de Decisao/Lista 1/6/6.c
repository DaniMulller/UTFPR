/*Elaborar um programa que, dada a idade de um nadador, classifique-o em uma das
seguintes categorias:
infantil A = 5 a 7 anos
infantil B = 8 a 10 anos
juvenil A = 11 a 13 anos
juvenil B = 14 a 17 anos
s�nior = maiores de 17 anos
n�o categorizado como atleta = menor de 5 anos, mas se o valor informado � negativo
informar o usu�rio que o valor � inv�lido para o escopo da solu��o.*/

# include <stdio.h>

int main(void)

{
    int idade;

    printf("Informe a idade: ");
    scanf("%d",&idade);

    if (idade >= 5 && idade <= 7)
    {
        printf("\nE um atleta Infantil A!\n");
    }
    else if (idade >7 && idade <=10)
    {
        printf("\nE um atleta Infantil B!\n");
    }
    else if (idade > 10 && idade <=13)
    {
        printf("\nE um atleta Juvenil A!\n");
    }
    else if (idade > 13 && idade <=17)
    {
        printf("\nE um atleta Juvenil B!\n");
    }
    else if (idade > 17)
    {
        printf("\nE um atleta Senior!\n");
    }
    else if (idade < 5)
    {
        printf("\nAinda nao e categorizado como atleta!\n");
    }
    else
    {
        printf("\nInforme um valor valido!\n");
    }
}
