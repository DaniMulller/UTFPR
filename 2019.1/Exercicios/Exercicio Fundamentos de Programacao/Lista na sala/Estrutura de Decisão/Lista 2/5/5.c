/*Calcular o imposto de renda de uma pessoa de acordo com a seguinte tabela:

    Renda anual                             Al�quota*           Dedu��o**

    At� R$ 10000,00                             0%              Isento
    > R$ 10000,00 e <= R$ 25000,00              10%             R$ 1000,00
    Acima de R$ 25000,00                        25%             R$ 4750,00

*Al�quota � o percentual para realizar o c�lculo do imposto a ser pago.
**Dedu��o � o valor deduzido ap�s calculado o valor com base na al�quota.

Se informado valor negativo n�o realizar o c�lculo e informar o usu�rio.*/

# include <stdio.h>

int main(void)

{
    float renda, imposto, renda_imp;

    printf("Informe a renda anual: ");
    scanf("%f",&renda);

    if (renda>0)
    {
        if (renda <= 10000)
        {
            printf("\nRenda de: %.2fR$ , Aliquota de 0%% e isento a Deducao\n",renda);
        }
        else if (renda > 10000 && renda <= 25000)
        {
            imposto = (renda*10/100) - 1000;
            renda_imp = renda - imposto;

            printf("\nRenda de %.fR$ , Aliquota de 10%% e 1000R$ de Deducao\n",renda_imp);
        }
        else
        {
            imposto = (renda*25/100) - 4750;
            renda_imp = renda - imposto;

            printf("\nRenda de %.2fR$ , Aliquota de 25%% e 4750R$ de Deducao\n",renda_imp);
        }
    }
    else
    {
        printf("\nInforme um valor valido!\n");
    }


}
