/*O código a seguir tem como objetivos:
a) fazer a divisão float entre dois valores inteiros informados pelo usuário;
b) Obter o resto da divisão do primeiro número pelo segundo número;*/

# include <stdio.h>

int main(void)

{
    int num1, num2, divisao_int, resto;
    float divisao;

    printf("Informe um numero: ");
    scanf("%d",&num1);
    printf("informe outro numero: ");
    scanf("%d",&num2);

    divisao = (float)num1/num2;
    printf("\nA divisao entre eles e: %f\n",divisao);

    resto = num1%num2;
    printf("\nO resto dessa divisao e: %d\n",resto);
}
