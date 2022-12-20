/*Ler um número e apresentar o seu módulo (número sem sinal), isto é, se informado
número é negativo apresentá-lo como positivo. Otimize o código: processe menos e use
menos memória declarando o menor número possível de variáveis*/

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
