/*Ler três valores inteiros, encontrar e mostrar o número do meio. Observação idem
ao exercício anterior.*/

# include <stdio.h>

int main(void)

{
    int num1,num2,num3,meio;

    printf("Informe um numero: ");
    scanf("%d",&num1);
    printf("Informe outro numero: ");
    scanf("%d",&num2);
    printf("Informe outro numero: ");
    scanf("%d",&num3);

    if ((num1<num2 && num1>num3)||(num1>num2 && num1<num3))
    {
        meio = num1;
    }
    else if ((num2<num1 && num2>num3)||(num2<num3 && num2>num1))
    {
        meio = num2;
    }
    else
    {
        meio = num3;
    }

    printf("\nMeio entre %d, %d e %d e %d\n",num1,num2,num3,meio);
}
