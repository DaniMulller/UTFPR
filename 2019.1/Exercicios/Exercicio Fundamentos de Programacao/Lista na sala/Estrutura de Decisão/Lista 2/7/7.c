/*Ler três valores que representam os lados de um triângulo e determinar se esses
valores podem formar um triângulo. Para formar um triângulo é necessário que a
soma de dois lados quaisquer seja maior (ou igual, no caso de triângulo com área
zero) ao valor do outro lado.*/

# include <stdio.h>

int main(void)

{
    int num1, num2, num3;

    printf("Informe um lado do tringulo: ");
    scanf("%d",&num1);
    printf("Informe outro lado do tringulo: ");
    scanf("%d",&num2);
    printf("Informe outro lado do tringulo: ");
    scanf("%d",&num3);

    if (num1+num2>=num3 || num1+num3>=num2 || num2+num3>=num1)
    {
        printf("\nE possivel formar um triangulo com esses lados!\n");
    }
    else
    {
        printf("\nNao e possivel montar um triangulo com esses lados!\n");
    }
}
