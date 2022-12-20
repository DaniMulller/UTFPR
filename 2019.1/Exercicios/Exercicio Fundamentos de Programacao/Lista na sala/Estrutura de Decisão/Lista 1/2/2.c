/*Escreva um algoritmo que leia um número e verifique se ele é maior, menor ou igual a
10. */

# include <stdio.h>

int main(void)

{
    int num;

    printf("Informe um numero: ");
    scanf("%d",&num);

    if (num > 10)
    {
        printf("\nO numero %d e maior que 10\n",num);
    }
    else if (num < 10)
    {
        printf("\nO numero %d e menor que 10\n",num);
    }
    else
    {
        printf("\nO numero e igual a 10\n",num);
    }
}

