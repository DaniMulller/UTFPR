/*Ler um número ponto flutuante (float):
a) Se o número lido é menor que 100, separar a parte inteira e a parte decimal e mostrá-
las separadamente.
b) Se o número lido é maior ou igual a 100, obter o resto da divisão desse número por 3 e
mostrar esse resto.*/

# include <stdio.h>

int main(void)

{
    float num;

    printf("Informe um numero: ");
    scanf("%f",&num);

    if (num < 100)
    {
        int num_int;
        float decimal;

        num_int = num;
        decimal = num - num_int;

        printf("\nA parte inteira e %d e a decimal e %f\n",num_int,decimal);
    }
    else
    {
        int resto;

        resto = ((int)num%3);

        printf("\nO resto desse numero por 3 e: %d\n",resto);
    }
}
