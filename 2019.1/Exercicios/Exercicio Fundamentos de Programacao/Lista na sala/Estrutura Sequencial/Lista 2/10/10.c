/*Leia dos valores inteiros, fa�a a divis�o deles armazenando em uma vari�vel a parte
inteira, em outra a parte decimal dessa divis�o e em uma terceira vari�vel a parte decimal,
mas como um inteiro de dois d�gitos. Declare as vari�veis do tipo adequado.*/

# include <stdio.h>

int main(void)

{
    int divisao;
    float decimal, num1, num2, digitos;

    printf("Informe um numero: ");
    scanf("%f",&num1);
    printf("Informe outro numero: ");
    scanf("%f",&num2);

    printf("\nInformados %.2f e %.2f \n",num1,num2);

    divisao = num1/num2;
    printf("\nParte inteira: %d \n",divisao);

    decimal = (num1/num2);
    printf("\nA parte decimal: %f \n",decimal);

    digitos = (num1/num2)*10;
    printf("\nParte decimal com dois digitos: %.0f \n",digitos);
}
