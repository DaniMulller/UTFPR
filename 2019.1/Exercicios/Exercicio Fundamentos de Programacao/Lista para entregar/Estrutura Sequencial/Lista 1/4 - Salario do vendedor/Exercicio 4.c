# include <stdio.h>

int main(void)

{
    float salario_mensal;
    int carros;
    float salario_fixo;
    float comissao_fixa;
    float total_vendido;

    printf("Informe o valor do salario fixo em reais: ");
    scanf("%f",&salario_fixo);
    printf("informe o valor da comissao fixa em reais: ");
    scanf("%f",&comissao_fixa);
    printf("Informe a quantidade de carros vendidos: ");
    scanf("%d",&carros);
    printf("Informe o total em reais vendido: ");
    scanf("%f",&total_vendido);

    salario_mensal = salario_fixo + (comissao_fixa * carros) + (total_vendido * 5/100);

    printf("\nO salario mensal desse vendedor nessas condicoes e de %.2f R$\n",salario_mensal);
}

