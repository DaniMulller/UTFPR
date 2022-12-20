/*Ler um número que representa a quantidade de dias. Informe os anos (com 360 dias),
meses (considere-os com 30 dias) e os dias contidos nesse valor.
Exemplo: 390 dias contêm 1 ano(s), 1 mês(es) e 0 dia(s). */

# include <stdio.h>

int main(void)

{
    int num, anos, meses, dias;

    printf("Informe uma qunatidade de dias: ");
    scanf("%d",&num);

    anos = num/360;
    meses = num%360 / 30;
    dias = meses%30;

    printf("\n%d dias tem %d anos, %d mes e %d dias\n",num,anos,meses,dias);
}
