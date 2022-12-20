/*Calcular o salário líquido de uma pessoa
. Sobre o salário bruto incidem descontos de
de imposto de renda e de INSS. Os descontos são informados em percentual.*/

# include <stdio.h>

int main(void)

{
    float salario_bruto;
    float inss;
    float imposto_renda;
    float salario_liquido;

    printf("Informe o salario bruto: ");
    scanf("%f",&salario_bruto);
    printf("Informe o percentual de INSS (Exemplo.5 para 5%%): ");
    scanf("%f",&inss);
    printf("Informe o percentual de IR (Ex.27 para 27%%): ");
    scanf("%f",&imposto_renda);

    salario_liquido = salario_bruto - (salario_bruto*inss/100) - (salario_bruto*imposto_renda/100);

    printf("\nSalario liquido e de R$ %.2f\n",salario_liquido);
}
