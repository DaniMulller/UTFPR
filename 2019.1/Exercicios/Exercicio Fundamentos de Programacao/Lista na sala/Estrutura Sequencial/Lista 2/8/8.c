/*Escrever um algoritmo que o leia o número de horas trabalhadas, o valor por hora, o
número de filhos com idade menor do que 14 anos, o valor do salário família por filho e
calcula o salário desse funcionário.*/

# include <stdio.h>

int main(void)

{
    int filhos;
    float horas, valor_hora, salario_filho, salario;

    printf("Informe as horas trabalhadas: ");
    scanf("%f",&horas);
    printf("Informe o valor da hora: ");
    scanf("%f",&valor_hora);
    printf("Informe a quantidade de filhos com menos de 14 anos: ");
    scanf("%d",&filhos);

    salario = horas*valor_hora;
    printf("\nO salario desse funcionario e de: %.2f R$\n",salario);

    salario_filho = salario/filhos;
    printf("\nO salario familia por filho e de: %.2f R$\n",salario_filho);
}
