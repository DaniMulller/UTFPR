/*Um hotel cobra R$ 210,00 por diária mais uma taxa de serviços de acordo com:
R$ 10,50 por diária, se o número de diárias for maior que 15;
R$ 16,00 por diária, se o número de diárias for igual a 15;
R$ 18,00 por diária, se o número de diárias for menor que 15.
Elaborar um programa para determinar o valor a ser pago pelo cliente. Se
informado zero ou valor negativo para a quantidade de diárias não realizar o cálculo.*/

# include <stdio.h>

int main(void)

{
    int num_dia;
    float taxa;

    printf("Informe o numero de diarias: ");
    scanf("%d",&num_dia);

    if (num_dia > 0)
    {
        if (num_dia > 15)
        {
            taxa = 210 + 10.5*num_dia;

            printf("\nDevera ser pago %.fR$\n",taxa);
        }
        else if (num_dia == 15)
        {
            taxa = 210 + 16*15;

            printf("\nDevera ser pago %.2fR$\n",taxa);
        }
        else
        {
            taxa = 210 + 18*num_dia;

            printf("\nDevera ser pago %.2fR$\n",taxa);
        }
    }
    else
    {
        printf("\nInforme um numero de diarias valido\n");
    }
}
