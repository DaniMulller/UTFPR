/* Faca um algoritmo que leia o sal�rio bruto mensal de um funcion�rio, calcule e mostre
os valores conforme o modelo.
Salario Bruto : R$
(-) IR (15%) : R$
(-) INSS (11%) : R$
(-) Sindicato (3%) : R$
Salario Liquido : R$
Observa��o: � poss�vel fazer esse algoritmo utilizando somente tr�s vari�veis: uma para
para ler o sal�rio bruto, outra os descontos e outra para o sal�rio l�quido. Tente!*/

# include <stdio.h>

int main(void)

{
    float salario_bruto, salario_liquido;

    printf("Informe o salario bruto: ");
    scanf("%f",&salario_bruto);

    printf("\nSalario Bruto: %.2f R$\n",salario_bruto);

    printf("\n(-)IR (15%%): %.2f R$\n",salario_bruto*15/100);
    printf("(-)INSS (11%%): %.2f R$\n",salario_bruto*11/100);
    printf("(-)Sindicato (3%%): %.2f R$\n",salario_bruto*3/100);

    salario_liquido = salario_bruto - ((salario_bruto*15/100)+(salario_bruto*11/100)+(salario_bruto*3/100));
    printf("\nSalario Liquido: %.2f R$\n",salario_liquido);
}
