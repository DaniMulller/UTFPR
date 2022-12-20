/*A contribui��o para o INSS � calculada da seguinte forma:
 a) sal�rio bruto de at� tr�s sal�rios m�nimos = INSS 8%
 b) sal�rio bruto acima de tr�s sal�rios m�nimos = INSS 10%
 c) para as contribui��es para o INSS com valor maior que o sal�rio m�nimo, o valor
cobrado � de um sal�rio m�nimo.
Elaborar um algoritmo que receba como entrada o sal�rio bruto, calcule o INSS e o
sal�rio l�quido e informe-os.*/

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
