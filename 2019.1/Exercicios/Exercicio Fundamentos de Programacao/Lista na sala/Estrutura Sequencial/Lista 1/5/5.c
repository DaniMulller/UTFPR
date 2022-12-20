# include <stdio.h>

int main(void)

{
    int num1, num2;
    float respFloat;
    int respInt;

    printf("Informe um valor inteiro: ");
    scanf("%d",&num1);
    printf("Infomre outro valor inteiro: ");
    scanf("%d",&num2);

    respInt = num1 + num2;
    printf("\n%d + %d = %d \n",num1, num2, respInt);
    respInt = num1 - num2;
    printf("%d - %d = %d \n",num1, num2, respInt);
    respInt = num1*num2;
    printf("%d * %d = %d \n",num1, num2, respInt);
    respInt = num1 / num2;
    printf("%d / %d = %d \n",num1, num2, respInt);
    respFloat = (float)num1 / num2;
    printf("%d / %d = %.1f \n",num1, num2, respFloat);
    respInt = num1 % num2; //% operador de resto. Só pode ser usado com operandos inteiros
    printf("%d %% %d = %d \n",num1, num2, respInt);
}
