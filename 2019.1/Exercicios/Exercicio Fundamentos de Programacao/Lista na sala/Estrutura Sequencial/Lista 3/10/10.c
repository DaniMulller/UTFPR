/*O código a seguir tem como objetivos:
a) fazer a divisão float entre dois valores inteiros informados pelo usuário;
b) Obter o resto da divisão do primeiro número pelo segundo número;
Faça os ajustes necessários para que os objetivos sejam alcançados.*/

# include <stdio.h>

int main(void)

{
    int num1, num2, resto, divisao;

    printf("Informe um numero: ");
    scanf("%d",&num1);
    printf("Informe outro numero: ");
    scanf("%d",&num2);

    divisao = (float)(num1/num2);
    resto = (float)(num1%num2);

    printf("\nA divisao e de: %d e o resto e de: %d\n",divisao,resto);

}
