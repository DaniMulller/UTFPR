/*Ler tr�s valores inteiros, encontrar e mostrar o menor deles. Deve ser criada uma
vari�vel para armazenar o menor valor informado. Observa��o: no algoritmo dever�
existir apenas uma instru��o printf para apresentar o menor valor e no formato:
printf(�menor entre %d,  %d e %e � %d�, num1, num2, num3, menor);*/

# include <stdio.h>

int main(void)

{
    int num1,num2,num3,menor;

    printf("Informe um numero: ");
    scanf("%d",&num1);
    printf("Informe outro numero: ");
    scanf("%d",&num2);
    printf("Informe outro numero: ");
    scanf("%d",&num3);

    if (num1<num2 && num1<num3)
    {
        menor = num1;
    }
    else if (num2<num3)
    {
        menor = num2;
    }
    else
    {
        menor = num3;
    }

    printf("\nMenor entre %d, %d e %d e %d\n",num1,num2,num3,menor);
}
