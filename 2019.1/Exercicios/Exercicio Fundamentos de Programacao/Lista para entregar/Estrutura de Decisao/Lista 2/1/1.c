/*A contribuição para o INSS é calculada da seguinte forma:
 a) salário bruto de até três salários mínimos = INSS 8%
 b) salário bruto acima de três salários mínimos = INSS 10%
 c) para as contribuições para o INSS com valor maior que o salário mínimo, o valor
cobrado é de um salário mínimo.
Elaborar um algoritmo que receba como entrada o salário bruto, calcule o INSS e o
salário líquido e informe-os.*/

# include <stdio.h>

int main(void)

{
    float salario_bruto,salario_minimo,salario_liquido;

    printf("Informe o salario bruto: ");
    scanf("%f",&salario_bruto);
    printf("Informe o salario minimo: ");
    scanf("%f",&salario_minimo);

    if (salario_bruto <= (3*salario_minimo))
    {
        salario_liquido = salario_bruto - (salario_bruto*8/100);
        printf("\nO INSS e 8%% e o Salario Liquido de %.2fR$\n",salario_liquido);
    }
    else //if (salario_bruto > 3*salario_minimo)
    {
        salario_liquido =  (salario_bruto*10/100);
         if (salario_liquido > salario_minimo)
         {
             salario_liquido = salario_bruto - salario_minimo;
         }
         else
         {
             salario_liquido = salario_bruto - salario_liquido;
         }

        printf("\nO INSS e 8%% e o Salario Liquido de %.2fR$\n",salario_liquido);
    }

}
