/*Ler dois valores numéricos e apresentar a diferença entre eles. A diferença sempre é
positiva, portanto, o menor é subtraído do maior não importando a ordem em que os
números são informados. */

# include <stdio.h>

int main(void)

{
    int num1, num2;

    printf("Informe um numero: ");
    scanf("%d",&num1);
    printf("Informe outro numero: ");
    scanf("%d",&num2);

    if (num1 > num2)
    {
        printf("\nA diferenca do maior para o menor e de: %d\n",num1-num2);
    }
    else
    {
       printf("\nA diferenca do maior para o menor e de: %d\n",num2-num1);
    }
}
