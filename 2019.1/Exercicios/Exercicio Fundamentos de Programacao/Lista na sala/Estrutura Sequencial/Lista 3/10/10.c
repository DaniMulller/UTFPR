/*O c�digo a seguir tem como objetivos:
a) fazer a divis�o float entre dois valores inteiros informados pelo usu�rio;
b) Obter o resto da divis�o do primeiro n�mero pelo segundo n�mero;
Fa�a os ajustes necess�rios para que os objetivos sejam alcan�ados.*/

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
