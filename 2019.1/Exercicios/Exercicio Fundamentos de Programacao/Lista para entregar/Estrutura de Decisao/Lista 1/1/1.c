/*Ler um n�mero e apresentar o seu m�dulo (n�mero sem sinal), isto �, se informado
n�mero � negativo apresent�-lo como positivo. Otimize o c�digo: processe menos e use
menos mem�ria declarando o menor n�mero poss�vel de vari�veis*/

# include <stdio.h>

int main(void)

{
    int num;

    printf("Informe um numero: ");
    scanf("%d",&num);

    if (num >= 0)
    {
        printf("\nO modulo de %d e: %d\n",num,num);

    }
    else
    {
        printf("\nO modulo de %d e: %d\n",num,-num);
    }
}
