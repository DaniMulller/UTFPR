/*Calcular o imposto de renda de uma pessoa de acordo com a seguinte tabela:

    Renda anual                             Alíquota*           Dedução**

    Até R$ 10000,00                             0%              Isento
    > R$ 10000,00 e <= R$ 25000,00              10%             R$ 1000,00
    Acima de R$ 25000,00                        25%             R$ 4750,00

*Alíquota é o percentual para realizar o cálculo do imposto a ser pago.
**Dedução é o valor deduzido após calculado o valor com base na alíquota.

Se informado valor negativo não realizar o cálculo e informar o usuário.*/

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
