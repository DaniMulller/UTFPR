# include <stdio.h>

int main(void)

{
    int quantidade_kilowatts;
    int total_desconto;

    printf("(---------------Calculadora de gasto de energia em Kilowatts---------------)");
    printf("\n\nConsiderando 700R$ o salario minimo e 100Kw custando 1/7 do salario minimo");
    printf("\n\n\nInforme a quantidade de kilowatts consumido: ");
    scanf("%d",&quantidade_kilowatts);

    total_desconto = quantidade_kilowatts - (quantidade_kilowatts * 1/10);

    printf("\nCusto de cada Kilowatt: 1 R$\n");
    printf("\nTotal gasto sem desconto = %d R$\n",quantidade_kilowatts);
    printf("\nTotal gasto com desconto = %d R$\n",total_desconto);

}
