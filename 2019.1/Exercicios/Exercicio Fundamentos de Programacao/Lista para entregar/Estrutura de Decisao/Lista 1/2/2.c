/*Ler dois valores num�ricos e apresentar a diferen�a entre eles. A diferen�a sempre �
positiva, portanto, o menor � subtra�do do maior n�o importando a ordem em que os
n�meros s�o informados. */

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
