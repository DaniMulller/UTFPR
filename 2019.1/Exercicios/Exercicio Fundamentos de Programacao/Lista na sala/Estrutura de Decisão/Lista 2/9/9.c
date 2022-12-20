/*Fazer o programa para o algoritmo representado no fluxograma a seguir*/

# include <stdio.h>

int main(void)

{
    float sal_base, sal_bruto, gratif, sal_liq, imposto;

    printf("Informe o salario base: ");
    scanf("%f",&sal_base);
    printf("Informe o gratificante: ");
    scanf("%f",&gratif);

    sal_bruto = sal_base + gratif;

    if (sal_bruto < 1000)
    {
        imposto = sal_bruto*(15/100);
        sal_liq = sal_bruto - imposto;

        printf("\nO salario liquido e de %.2fR$\n",sal_liq);
    }
    else
    {
        imposto = sal_bruto*(20/100);
        sal_liq = sal_bruto - imposto;

        printf("\nO salario liquido e de %.2fR$\n",sal_liq);
    }
}
