/*Faça um programa que mostre o resultado da seguinte soma, sendo n o valor
informado pelo usuário :
Soma = 1 + 1/2 + 1/3 + 1/4 + 1/5 + … + 1/n */

# include <stdio.h>

int main(void)

{
    int num,i;
    float soma=0;

    printf("Informe um numero: ");
    scanf("%d",&num);

    for (i=1;i<=num;i++)
    {
        soma = soma + (1/(float)i);
        printf("1/%d = %f\n+\n",i,soma);
    }
}
